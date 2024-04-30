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

#define MAX_DEVICES 32

struct gddr6_ctx ctx = {0};
struct device dev_table[] =
{
    { .offset = 0x0000E2A8, .dev_id = 0x2684, .vram = "GDDR6X", .arch = "AD102", .name =  "RTX 4090" },
    { .offset = 0x0000E2A8, .dev_id = 0x2702, .vram = "GDDR6X", .arch = "AD103", .name =  "RTX 4080 Super" },
    { .offset = 0x0000E2A8, .dev_id = 0x2704, .vram = "GDDR6X", .arch = "AD103", .name =  "RTX 4080" },
    { .offset = 0x0000E2A8, .dev_id = 0x2705, .vram = "GDDR6X", .arch = "AD103", .name =  "RTX 4070 Ti Super" },
    { .offset = 0x0000E2A8, .dev_id = 0x2782, .vram = "GDDR6X", .arch = "AD104", .name =  "RTX 4070 Ti" },
    { .offset = 0x0000E2A8, .dev_id = 0x2783, .vram = "GDDR6X", .arch = "AD104", .name =  "RTX 4070 Super" },
    { .offset = 0x0000E2A8, .dev_id = 0x2786, .vram = "GDDR6X", .arch = "AD104", .name =  "RTX 4070" },
    { .offset = 0x0000E2A8, .dev_id = 0x2860, .vram = "GDDR6",  .arch = "AD106", .name =  "RTX 4070 Max-Q / Mobile" },
    { .offset = 0x0000E2A8, .dev_id = 0x2203, .vram = "GDDR6X", .arch = "GA102", .name =  "RTX 3090 Ti" },
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

void gddr6_init(void)
{
    ctx.fd = open("/dev/mem", O_RDONLY);
    if (ctx.fd == -1) {
        PRINT_ERROR();
    }
}

int gddr6_detect_compatible_gpus(void)
{
    ctx.devices = NULL;
    ctx.num_devices = 0;

    struct pci_access *pacc = NULL;
    struct pci_dev *pci_dev = NULL;
    ssize_t dev_table_size = (sizeof(dev_table)/sizeof(struct device));

    pacc = pci_alloc();
    pci_init(pacc);
    pci_scan_bus(pacc);

    for (pci_dev = pacc->devices; pci_dev != NULL; pci_dev = pci_dev->next) 
    {
          pci_fill_info(pci_dev, PCI_FILL_IDENT | PCI_FILL_BASES | PCI_FILL_CLASS);
          for (uint32_t i = 0; i < dev_table_size; ++i) 
          {
              if (pci_dev->device_id == dev_table[i].dev_id) 
              {
                  struct device *new_devices = realloc(ctx.devices, (ctx.num_devices + 1) * sizeof(struct device));
                  if (new_devices == NULL)
                  {
                      fprintf(stderr, "Memory allocation failed\n");
                      pci_cleanup(pacc);
                      free(ctx.devices);
                      ctx.devices = NULL;
                      return 0;
                  }
                  ctx.devices = new_devices;

                  ctx.devices[ctx.num_devices] = dev_table[i];
                  ctx.devices[ctx.num_devices].bar0 = (pci_dev->base_addr[0] & 0xffffffff);
                  ctx.devices[ctx.num_devices].bus = pci_dev->bus;
                  ctx.devices[ctx.num_devices].dev = pci_dev->dev;
                  ctx.devices[ctx.num_devices].func = pci_dev->func;
                  ctx.num_devices++;
              }
          }
      }

    pci_cleanup(pacc);
    return ctx.num_devices;
}

void gddr6_memory_map(void)
{
    for (uint32_t i = 0; i < ctx.num_devices; i++)
    {
        ctx.devices[i].phys_addr = (ctx.devices[i].bar0 + ctx.devices[i].offset);
        ctx.devices[i].base_offset = ctx.devices[i].phys_addr & ~(PG_SZ - 1);

        ctx.devices[i].mapped_addr = mmap(0, PG_SZ, PROT_READ, MAP_SHARED, ctx.fd, ctx.devices[i].base_offset);
        if (ctx.devices[i].mapped_addr == MAP_FAILED)
        {
            ctx.devices[i].mapped_addr = NULL;
            fprintf(stderr, "Memory mapping failed for pci=%x:%x:%x\n", ctx.devices[i].bus, ctx.devices[i].dev, ctx.devices[i].func);
            fprintf(stderr, "Did you enable iomem=relaxed? Are you r00t?\n");
            exit(EXIT_FAILURE);
        } else {
            printf("Device: %s %s (%s / 0x%04x) pci=%x:%x:%x\n", ctx.devices[i].name, ctx.devices[i].vram,
            ctx.devices[i].arch, ctx.devices[i].dev_id, ctx.devices[i].bus, ctx.devices[i].dev, ctx.devices[i].func);
        }
    }
}

void gddr6_monitor_temperatures(void)
{
   while (1) {
        printf("\rVRAM Temps: |");
        for (uint32_t i = 0; i < ctx.num_devices; i++)
        {
            if (ctx.devices[i].mapped_addr == NULL || ctx.devices[i].mapped_addr == MAP_FAILED)
            {
                continue;
            }

            void *virt_addr = (uint8_t *) ctx.devices[i].mapped_addr + (ctx.devices[i].phys_addr  - ctx.devices[i].base_offset);
            uint32_t read_result = *((uint32_t *)virt_addr);
            uint32_t temp = ((read_result & 0x00000fff) / 0x20);

            printf(" %3u°C |", temp);
        }
        fflush(stdout);
        sleep(1);
   }
}

void gddr6_cleanup(int signal)
{
    for (uint32_t i = 0; i < ctx.num_devices; i++)
    {
        if (ctx.devices[i].mapped_addr != NULL && ctx.devices[i].mapped_addr != MAP_FAILED)
        {
            munmap(ctx.devices[i].mapped_addr, PG_SZ);
            ctx.devices[i].mapped_addr = NULL;
        }
    }
    if (ctx.fd != -1)
    {
        close(ctx.fd);
        ctx.fd = -1;
    }
    if (ctx.devices)
    {
        free(ctx.devices);
        ctx.devices = NULL;
    }
    exit(signal);
}
