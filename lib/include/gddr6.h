// gddr6.h
#ifndef GDDR6_H
#define GDDR6_H

#include <stdint.h>

struct device {
    uint32_t bar0;
    uint8_t bus, dev, func;
    uint32_t offset;
    uint16_t dev_id;
    const char *vram;
    const char *arch;
    const char *name;
};

void gddr6_initialize(void);
void gddr6_cleanup(int signal);
void gddr6_monitor_temperatures(const struct device *devices, int num_devices);
int gddr6_detect_compatible_gpus(struct device *devices, int max_devices);

#endif // GDDR6_H
