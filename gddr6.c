#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pci/pci.h>

struct device 
{
    uint32_t bar0;
    uint32_t offset;
    uint16_t dev_id;
    const char *arch;
    const char *name;
};

static struct device devices[] = {
    { .bar0 = 0xEC000000, .offset = 0x0000E2A8, .dev_id = 0x2684, .arch = "AD102", .name =  "RTX 4090" },
    { .bar0 = 0xFB000000, .offset = 0x0000E2A8, .dev_id = 0x1337, .arch = "GA102", .name =  "RTX 3090" },
    { .bar0 = 0xFB000000, .offset = 0x0000EE50, .dev_id = 0x1337, .arch = "GA104", .name =  "RTX 3070" },
};

struct device * pci_detect_dev() 
{
    struct pci_access *pacc = NULL;
    struct pci_dev *dev = NULL;
    struct device *device = NULL;

    pacc = pci_alloc();
    pci_init(pacc);
    pci_scan_bus(pacc);

    for (dev = pacc->devices; dev; dev = dev->next) {
        pci_fill_info(dev, PCI_FILL_IDENT | PCI_FILL_BASES | PCI_FILL_CLASS);
        for (uint32_t i = 0; i < 3; i++) {
          if (dev->device_id == devices[i].dev_id) {
            device = &devices[i]; 
          }
        }
    }

    pci_cleanup(pacc);
    return device;
}

int main(int argc, char **argv)
{
    int fd;
    int map_size = 4096UL;
    void *map_base, *virt_addr;
    uint32_t read_result, base_offset, temp;
    uint32_t offset;
    struct device *device = NULL; 

    char *MEM_RES = "\x2f\x64\x65\x76\x2f\x6d\x65\x6d";

    device = pci_detect_dev();
    offset = device->bar0 + device->offset;

    if (device == NULL) {
      printf("No compatible devices device. \n");
      exit(-1);
    }

    printf("Device: %s (%s / 0x%04x) \n", device->name, device->arch, device->dev_id);

    while (1) {
        if ((fd = open(MEM_RES, O_RDWR | O_SYNC)) == -1) {
          printf("Can't read memory. Are you r00t?\n");
          exit(-1);
        }

        base_offset = offset & ~(sysconf(_SC_PAGE_SIZE)-1);
        map_base = mmap(0, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, base_offset);

        if (!map_base) {
          printf("Can't map memory. Are you r00t?\n");
          exit(-1);
        }

        virt_addr = map_base + offset - base_offset;
        read_result = *((uint32_t *) virt_addr);
        temp = (read_result & 0x00000fff) / 0x20;
        printf("\rGDDR6X VRAM Temp: %d°c", temp);
        fflush(stdout);

        if (munmap(map_base, map_size) == -1) {
          printf("Can't unmap memory!\n");
          exit(-1);
        }

        close(fd);
        sleep(1);
    }
    return 0;
}
