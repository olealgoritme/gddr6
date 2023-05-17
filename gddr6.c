#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pci/pci.h>
#include <signal.h>

#define PG_SZ sysconf(_SC_PAGE_SIZE)
#define PRINT_ERROR()                                        \
      do {                                                     \
      fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
      __LINE__, __FILE__, errno, strerror(errno)); exit(1);    \
      } while(0)


// device struct
struct device
{
    uint32_t bar0;
    uint8_t bus, dev, func;
    uint32_t offset;
    uint16_t dev_id;
    const char *vram;
    const char *arch;
    const char *name;
};


// variables
int fd;
void *map_base;
struct device devices[32];


// device table
struct device dev_table[] =
{
    { .offset = 0x0000E2A8, .dev_id = 0x2684, .vram = "GDDR6X", .arch = "AD102", .name =  "RTX 4090" },
    { .offset = 0x0000E2A8, .dev_id = 0x2782, .vram = "GDDR6X", .arch = "AD104", .name =  "RTX 4070 Ti" },
    { .offset = 0x0000E2A8, .dev_id = 0x2204, .vram = "GDDR6X", .arch = "GA102", .name =  "RTX 3090" },
    { .offset = 0x0000EE50, .dev_id = 0x2484, .vram = "GDDR6",  .arch = "GA104", .name =  "RTX 3070" },
    { .offset = 0x0000EE50, .dev_id = 0x2488, .vram = "GDDR6",  .arch = "GA104", .name =  "RTX 3070-LHR" },
};


// prototypes
void cleanup(int signal);
void cleanup_sig_handler(void);
int pci_detect_dev(void);


// cleanup
void cleanup(int signal)
{
    if (signal == SIGHUP || signal == SIGINT || signal == SIGTERM)
    {
        if (map_base != (void *) -1)
            munmap(map_base, PG_SZ);
        if (fd != -1)
            close(fd);
        exit(0);
    }
}


// cleanup signal handler
void cleanup_sig_handler(void)
{
    struct sigaction sa;
    sa.sa_handler = &cleanup;
    sa.sa_flags = 0;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) < 0)
        perror("Cannot handle SIGINT");

    if (sigaction(SIGHUP, &sa, NULL) < 0)
        perror("Cannot handle SIGHUP");

    if (sigaction(SIGTERM, &sa, NULL) < 0)
        perror("Cannot handle SIGTERM");
}


// pci device detection
int pci_detect_dev(void)
{
    struct pci_access *pacc = NULL;
    struct pci_dev *pci_dev = NULL;
    int num_devs = 0;
    ssize_t dev_table_size = (sizeof(dev_table)/sizeof(struct device));

    pacc = pci_alloc();
    pci_init(pacc);
    pci_scan_bus(pacc);

    for (pci_dev = pacc->devices; pci_dev; pci_dev = pci_dev->next)
    {
        pci_fill_info(pci_dev, PCI_FILL_IDENT | PCI_FILL_BASES | PCI_FILL_CLASS);

        for (uint32_t i = 0; i < dev_table_size; i++)
        {
            if (pci_dev->device_id == dev_table[i].dev_id)
            {
                devices[num_devs] = dev_table[i];
                devices[num_devs].bar0 = (pci_dev->base_addr[0] & 0xFFFFFFFF);
                devices[num_devs].bus = pci_dev->bus;
                devices[num_devs].dev = pci_dev->dev;
                devices[num_devs].func = pci_dev->func;
                num_devs++;
            }
        }
    }

    pci_cleanup(pacc);
    return num_devs;
}


int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    void *virt_addr;
    uint32_t temp;
    uint32_t phys_addr;
    uint32_t read_result;
    uint32_t base_offset;

    int num_devs;
    char *MEM = "\x2f\x64\x65\x76\x2f\x6d\x65\x6d";

    num_devs = pci_detect_dev();

    if (num_devs == 0)
    {
        printf("No compatible GPU found\n.");
        exit(-1);
    }

    for (int i = 0; i < num_devs; i++) {
        struct device *device = &devices[i];
        printf("Device: %s %s (%s / 0x%04x) pci=%x:%x:%x\n", device->name, device->vram,
            device->arch, device->dev_id, device->bus, device->dev, device->func);
    }

    if ((fd = open(MEM, O_RDWR | O_SYNC)) == -1)
    {
        printf("Can't read memory. If you are root, enable kernel parameter iomem=relaxed\n");
        PRINT_ERROR();
    }

    cleanup_sig_handler();


    while (1)
    {
        printf("\rVRAM Temps: |");
        for (int i = 0; i < num_devs; i++) {
            struct device *device = &devices[i];

            phys_addr = (device->bar0 + device->offset);
            base_offset = phys_addr & ~(PG_SZ-1);
            map_base = mmap(0, PG_SZ, PROT_READ | PROT_WRITE, MAP_SHARED, fd, base_offset);

            if(map_base == (void *) -1)
            {
                if (fd != -1)
                    close(fd);
                printf("Can't read memory. If you are root, enable kernel parameter iomem=relaxed\n");
                PRINT_ERROR();
            }
            virt_addr = (uint8_t *) map_base + (phys_addr - base_offset);
            read_result = *((uint32_t *) virt_addr);
            temp = ((read_result & 0x00000fff) / 0x20);

            printf(" %3u°c |", temp);
        }
        fflush(stdout);
        sleep(1);
    }

    return 0;
}
