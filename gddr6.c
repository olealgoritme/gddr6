#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pci/pci.h>

#define PRINT_ERROR()                                                    \
                do {                                                     \
                fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
                __LINE__, __FILE__, errno, strerror(errno)); exit(1);    \
                } while(0)

struct device 
{
    uint32_t bar0;
    uint32_t offset;
    uint16_t dev_id;
    const char *vram;
    const char *arch;
    const char *name;
};

static struct device dev_table[] = 
{
    { .bar0 = 0xEC000000, .offset = 0x0000E2A8, .dev_id = 0x2684, .vram = "GDDR6X", .arch = "AD102", .name =  "RTX 4090" },
    { .bar0 = 0xFB000000, .offset = 0x0000E2A8, .dev_id = 0x2204, .vram = "GDDR6X", .arch = "GA102", .name =  "RTX 3090" },
    { .bar0 = 0xFB000000, .offset = 0x0000EE50, .dev_id = 0x2484, .vram = "GDDR6",  .arch = "GA104", .name =  "RTX 3070" },
    { .bar0 = 0xFB000000, .offset = 0x0000EE50, .dev_id = 0x2488, .vram = "GDDR6",  .arch = "GA104", .name =  "RTX 3070-LHR" },
};

struct device * pci_detect_dev() 
{
    struct pci_access *pacc = NULL;
    struct pci_dev *dev = NULL;
    struct device *device = NULL;
    ssize_t dev_table_size = (sizeof(dev_table)/sizeof(struct device));

    pacc = pci_alloc();
    pci_init(pacc);
    pci_scan_bus(pacc);

    for (dev = pacc->devices; dev; dev = dev->next) 
    {
        pci_fill_info(dev, PCI_FILL_IDENT | PCI_FILL_BASES | PCI_FILL_CLASS);

        for (uint32_t i = 0; i < dev_table_size; i++) 
        {
            if (dev->device_id == dev_table[i].dev_id) 
            {
                device = &dev_table[i]; 

                if (dev->base_addr[0] != device->bar0) 
                {
                    device->bar0 = dev->base_addr[0];
                }

                break;
            }
        }
    }

    pci_cleanup(pacc);
    return device;
}

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    int fd;
    void *map_base;
    void *virt_addr;
    uint32_t temp;
    uint32_t phys_addr;
    uint32_t read_result;
    uint32_t base_offset;
    uint32_t map_size = 0x1000;
    struct device *device = NULL; 
    char *MEM = "\x2f\x64\x65\x76\x2f\x6d\x65\x6d";

    device = pci_detect_dev();
    phys_addr = device->bar0 + device->offset;

    if (device == NULL) 
    {
        printf("No compatible devices device. \n");
        exit(-1);
    }

    printf("Device: %s (%s / 0x%04x)\n", device->name, device->arch, device->dev_id);

    if ((fd = open(MEM, O_RDWR | O_SYNC)) == -1) 
    {
        printf("Can't read memory. If you are root, enable kernel parameter iomem=relaxed\n");
        PRINT_ERROR();
    }

    base_offset = phys_addr & ~(sysconf(_SC_PAGE_SIZE)-1);
    map_base = mmap(0, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, base_offset);

    if(map_base == (void *) -1)
    {
        close(fd);
        PRINT_ERROR();
    }

    while (1)
    {
        virt_addr = (map_base + (phys_addr - base_offset));
        read_result = *((uint32_t *) virt_addr);

        temp = ((read_result & 0x00000fff) / 0x20);

        printf("\r%s VRAM Temp: %d°c", device->vram, temp);
        fflush(stdout);

        sleep(1);
    }

    munmap(map_base, map_size);
    close(fd);
        
    return 0;
}
