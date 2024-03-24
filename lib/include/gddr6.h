// gddr6.h
#ifndef GDDR6_H
#define GDDR6_H

#include <stdint.h>

struct device
{
    uint32_t bar0;
    uint8_t bus, dev, func;
    uint32_t offset;
    uint16_t dev_id;
    const char *vram;
    const char *arch;
    const char *name;
    void *mapped_addr;
    uint32_t phys_addr;
    uint32_t base_offset;
};

struct gddr6_ctx {
  struct device *devices;
  int num_devices;
  int fd;
};

void gddr6_init(void);
void gddr6_memory_map(void);
void gddr6_cleanup(int signal);
void gddr6_monitor_temperatures(void);
int gddr6_detect_compatible_gpus(void);

#endif // GDDR6_H
