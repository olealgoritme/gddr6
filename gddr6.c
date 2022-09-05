#include <stdio.h>
#include <unistd.h>
#include "include/nva/nva.h"
#include "include/ampere/ga100/dev_boot.h"

enum {
    NVIDIA_MMIO_MASK_PMC        = 0x00000FFF,
    NVIDIA_MMIO_MASK_PBUS       = 0x00001FFF,
    NVIDIA_MASK_ALL             = 0x0000FFFF,
};

struct pmc_id {
    uint8_t stepping;
    uint8_t device_id;
    uint16_t gpu_id;
};

void PMC_ID (uint32_t value,
                 struct pmc_id *id) {
    id->stepping   = (value << 0) >> 0;
    id->device_id  = (value << 0) >> 12;
    id->gpu_id     = (value << 0) >> 20;
}

void read_temps(int cnum, uint32_t offset) {
  uint32_t temp = 0;
  while(1) {
    temp = nva_rd32(cnum, offset);
    temp = (temp & 0x00000fff) / 0x20;
    fprintf(stderr, "\rGDDR6 VRAM Temp: %d°c", temp);
    fflush(stderr);
    sleep(1);
  }
}

int main(int argc, char **argv) {
    int c;
    int i;
    int cnum = 0;
    int mask = NVIDIA_MASK_ALL;

    if (nva_init()) {
            fprintf (stderr, "PCI init failure!. Are you r00t?\n");
            return 1;
    }

    while ((c = getopt (argc, argv, "c:")) != -1)
    switch (c) {
            case 'c':
                    sscanf(optarg, "%d", &cnum);
                    break;
            default:
                    break;
    }

    if (cnum >= nva_cardsnum) {
            if (nva_cardsnum)
                    fprintf (stderr, "No valid card.\n");
            else
                    fprintf (stderr, "No cards found.\n");
                    return 1;
    } 

    if (mask & NVIDIA_MMIO_MASK_PMC) {
            uint32_t pmc_boot_0 = nva_rd32(cnum, NV_PMC_BOOT_0);
            struct pmc_id id;
            PMC_ID(pmc_boot_0, &id);
            
            switch (id.gpu_id) {
              uint32_t offset;
              case 0xb72: { // ga102
                            // TODO: temps over 100 might fail
                    offset = 0x0000E2A8;
                    read_temps(cnum, offset);
                    } 
                    break;

              case 0xb74: { // ga104
                    offset = 0x0000EE50;
                    read_temps(cnum, offset);
                    } 
                    break;

              default:
                    fprintf (stderr, "No valid card.\n");
                    break;
            }
    }

    return 0;
}

