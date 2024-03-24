// gddr6.c
#define _GNU_SOURCE

#include "gddr6.h"
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
#define PRINT_ERROR()                                          \
      do {                                                     \
      fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
      __LINE__, __FILE__, errno, strerror(errno)); exit(1);    \
      } while(0)

static int fd = -1;
static void *map_base = MAP_FAILED;
static struct device devices[32];

struct device dev_table[] =
{
    { .offset = 0x0000E2A8, .dev_id = 0x2684, .vram = "GDDR6X", .arch = "AD102", .name =  "RTX 4090" },
    { .offset = 0x0000E2A8, .dev_id = 0x2704, .vram = "GDDR6X", .arch = "AD103", .name =  "RTX 4080" },
    { .offset = 0x0000E2A8, .dev_id = 0x2782, .vram = "GDDR6X", .arch = "AD104", .name =  "RTX 4070 Ti" },
    { .offset = 0x0000E2A8, .dev_id = 0x2786, .vram = "GDDR6X", .arch = "AD104", .name =  "RTX 4070" },
    { .offset = 0x0000E2A8, .dev_id = 0x2204, .vram = "GDDR6X", .arch = "GA102", .name =  "RTX 3090" },
    { .offset = 0x0000E2A8, .dev_id = 0x2208, .vram = "GDDR6X", .arch = "GA102", .name =  "RTX 3080 Ti" },
    { .offset = 0x0000E2A8, .dev_id = 0x2206, .vram = "GDDR6X", .arch = "GA102", .name =  "RTX 3080" },
    { .offset = 0x0000E2A8, .dev_id = 0x2216, .vram = "GDDR6X", .arch = "GA102", .name =  "RTX 3080 LHR" },
    { .offset = 0x0000EE50, .dev_id = 0x2484, .vram = "GDDR6",  .arch = "GA104", .name =  "RTX 3070" },
    { .offset = 0x0000EE50, .dev_id = 0x2488, .vram = "GDDR6",  .arch = "GA104", .name =  "RTX 3070 LHR" },
    { .offset = 0x0000E2A8, .dev_id = 0x2531, .vram = "GDDR6",  .arch = "GA106", .name =  "RTX A2000" },
    { .offset = 0x0000E2A8, .dev_id = 0x2571, .vram = "GDDR6",  .arch = "GA106", .name =  "RTX A2000" },
    { .offset = 0x0000E2A8, .dev_id = 0x2232, .vram = "GDDR6",  .arch = "GA102", .name =  "RTX A4500" },
    { .offset = 0x0000E2A8, .dev_id = 0x2231, .vram = "GDDR6",  .arch = "GA102", .name =  "RTX A5000" },
    { .offset = 0x0000E2A8, .dev_id = 0x26B1, .vram = "GDDR6",  .arch = "AD102", .name =  "RTX A6000" },
    { .offset = 0x0000E2A8, .dev_id = 0x27b8, .vram = "GDDR6",  .arch = "AD104", .name =  "L4" },
    { .offset = 0x0000E2A8, .dev_id = 0x26b9, .vram = "GDDR6",  .arch = "AD102", .name =  "L40S" },
    { .offset = 0x0000E2A8, .dev_id = 0x2236, .vram = "GDDR6",  .arch = "GA102", .name =  "A10" },
};


void gddr6_initialize(void) 
{
    const char *MEM = "/dev/mem";
    if ((fd = open(MEM, O_RDONLY)) == -1) {
        PRINT_ERROR();
    }
}

int gddr6_detect_compatible_gpus(struct device *devices, int max_devices) 
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

void gddr6_cleanup(int signal) 
{
    if (map_base != MAP_FAILED) 
    {
        munmap(map_base, PG_SZ);
        map_base = MAP_FAILED;
    }

    if (fd != -1)
    {
        close(fd);
        fd = -1;
    }

    exit(signal);
}

void gddr6_monitor_temperatures(const struct device *devices, int num_devices) 
{
    void *virt_addr;
    uint32_t temp;
    uint32_t phys_addr;
    uint32_t read_result;
    uint32_t base_offset;

    while (1) 
    {
        printf("\rVRAM Temps: |");
        for (int i = 0; i < num_devices; i++) 
        {
            const struct device *device = &devices[i];
            phys_addr = (device->bar0 + device->offset);
            base_offset = phys_addr & ~(PG_SZ-1);
            map_base = mmap(0, PG_SZ, PROT_READ, MAP_SHARED, fd, base_offset);
            if(map_base == (void *) MAP_FAILED)
            {
                if (fd != -1)
                {
                    close(fd);
                }
                printf("Can't read memory. If you are root, enable kernel parameter iomem=relaxed\n");
                PRINT_ERROR();
            }
            virt_addr = (uint8_t *) map_base + (phys_addr - base_offset);
            read_result = *((uint32_t *) virt_addr);
            temp = ((read_result & 0x00000fff) / 0x20);

            printf(" %3u°C |", temp);
        }
        fflush(stdout);
        sleep(1);
    }
}
