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

#define PG_SZ sysconf(_SC_PAGE_SIZE)
#define PRINT_ERROR()                                          \
      do {                                                     \
      fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
      __LINE__, __FILE__, errno, strerror(errno)); exit(1);    \
      } while(0)

#define MAX_DEVICES 32

struct gddr6_ctx ctx = {0};
// Ada/Ampere GPUs: temperature field is bits [11:0], Celsius = field / 32.
struct device dev_table[] =
{
    { .offset = 0x0000E2A8, .dev_id = 0x2684, .vram = "GDDR6X", .arch = "AD102", .name =  "RTX 4090" },
    { .offset = 0x0000E2A8, .dev_id = 0x2685, .vram = "GDDR6X", .arch = "AD102", .name =  "RTX 4090 D" },
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
    // Blackwell GDDR7 memory temperature: the raw FBPA DRAM sensor at
    // NV_PFB_FBPA_DQR_STATUS_DQ_IC0_SUBP0 (0x9A24C0) - the register the FBFALCON
    // firmware reads. NOT PLM-locked; reads valid data from userspace (validity
    // bit 24 of 0x9A24D0). The value is a per-device GDDR temp MR-code in bits
    // 23:16; DECODE_GDDR_MRCODE converts it to Celsius. (The documented mem-temp
    // reg 0x9A44B0 is PLM-locked and its 0xE2A8 scratch mirror is unpopulated on
    // this card, so we read the raw sensor directly.)
    { .offset = 0x009A24C0, .decode = DECODE_GDDR_MRCODE, .dev_id = 0x2b85, .vram = "GDDR7", .arch = "GB202", .name = "RTX 5090" },
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

// Convert a raw register value to degrees Celsius per the device's decode.
static int decode_temp(enum temp_decode decode, uint32_t raw)
{
    switch (decode)
    {
    case DECODE_GDDR_MRCODE:
    {
        // GDDR temp MR-code in bits 23:16 (see NV_PFB_FBPA_DQR_STATUS_DQ).
        // code 20 = 0 C, +2 C per unit above 20; below 20 is negative.
        int code = (raw >> 16) & 0xFF;
        if (code > 80) code = 80;
        return (code > 19) ? (code - 20) * 2 : -(40 - code * 2);
    }
    case DECODE_ADA:
    default:
        return (raw & 0x00000fff) / 0x20;
    }
}

// Blackwell GDDR7 per-memory-partition (module) DQR sensors. Module p lives at
// BAR0 + DQR_MODULE0 + p*DQR_STRIDE; validity nibble (all 4 IC/subp valid = 0xF)
// is at +DQR_VLD_OFF. Unlike the single pre-mapped register, these span several
// pages, so they are read on demand with a fresh page-aligned mmap.
#define DQR_MODULE0   0x009024C0u
#define DQR_VLD_OFF   (0x009024D0u - 0x009024C0u)   // +0x10
#define DQR_STRIDE    0x00004000u
#define DQR_MAX_MODULES 16

// Read one 32-bit MMIO register at BAR0+off via a fresh read-only page mmap.
// Returns 0 on success. Used only for the on-demand per-module GDDR7 reads.
static int read_bar0_reg(uint32_t bar0, uint32_t off, uint32_t *out)
{
    long pg = PG_SZ;
    uint64_t phys = (uint64_t)bar0 + off;
    uint64_t base = phys & ~((uint64_t)pg - 1);
    volatile void *map = mmap(0, pg, PROT_READ, MAP_SHARED, ctx.fd, base);
    if (map == MAP_FAILED) return -1;
    *out = *(volatile uint32_t *)((const uint8_t *)map + (phys - base));
    munmap((void *)map, pg);
    return 0;
}

// Read the GDDR7 modules for a Blackwell device. Fills temps[]/present[] for up
// to DQR_MAX_MODULES, returns the module count found and the hottest temp in
// *hottest. A module counts as present only if all 4 DQR valid bits are set and
// the data word is not the 0xBADF.... poison sentinel.
static int gddr7_read_modules(uint32_t bar0, int temps[], int *hottest)
{
    int count = 0, hot = -128;
    for (int p = 0; p < DQR_MAX_MODULES; p++)
    {
        uint32_t off = DQR_MODULE0 + (uint32_t)p * DQR_STRIDE;
        uint32_t vld = 0, dq = 0;
        if (read_bar0_reg(bar0, off + DQR_VLD_OFF, &vld) != 0) continue;
        if (read_bar0_reg(bar0, off, &dq) != 0) continue;

        int all_valid = (((vld >> 24) & 0xF) == 0xF);
        int poison    = ((dq & 0xFFFF0000u) == 0xBADF0000u);
        if (!all_valid || poison) continue;

        int c = decode_temp(DECODE_GDDR_MRCODE, dq);
        temps[count++] = c;
        if (c > hot) hot = c;
    }
    *hottest = hot;
    return count;
}

void gddr6_monitor_temperatures(int per_module)
{
   int temps[DQR_MAX_MODULES];
   while (1) {
        printf("\rVRAM Temps: |");
        for (uint32_t i = 0; i < ctx.num_devices; i++)
        {
            if (ctx.devices[i].mapped_addr == NULL || ctx.devices[i].mapped_addr == MAP_FAILED)
            {
                continue;
            }

            // Blackwell GDDR7: per-module DQR sensors. Default shows the hotspot
            // (max across modules); --per-module lists each module.
            if (ctx.devices[i].decode == DECODE_GDDR_MRCODE)
            {
                int hottest = 0;
                int n = gddr7_read_modules(ctx.devices[i].bar0, temps, &hottest);
                if (n == 0) { printf("  n/a |"); continue; }

                if (per_module)
                {
                    for (int m = 0; m < n; m++)
                        printf(" m%d=%3d°C |", m, temps[m]);
                }
                else
                {
                    printf(" %3d°C (hotspot) |", hottest);
                }
                continue;
            }

            // Ada/Ampere: single pre-mapped VRAM register.
            void *virt_addr = (uint8_t *) ctx.devices[i].mapped_addr + (ctx.devices[i].phys_addr - ctx.devices[i].base_offset);
            uint32_t read_result = *((uint32_t *)virt_addr);
            int temp = decode_temp(ctx.devices[i].decode, read_result);
            printf(" %3d°C |", temp);
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
