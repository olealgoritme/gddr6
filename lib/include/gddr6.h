// gddr6.h
#ifndef GDDR6_H
#define GDDR6_H

#include <stdint.h>

// How to convert a raw register read into degrees Celsius.
enum temp_decode {
    DECODE_ADA = 0,      // Ada/Ampere: (raw & 0xfff) / 32
    DECODE_GDDR_MRCODE,  // Blackwell FBPA DQR: byte in bits 23:16 is a GDDR temp
                         // MR-code; C = (code-20)*2 for code>19, else -(40-code*2)
};

struct device
{
    uint32_t bar0;
    uint8_t bus, dev, func;
    uint32_t offset;
    enum temp_decode decode;  // how to turn the raw reg into Celsius
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
void gddr6_monitor_temperatures(int per_module);
int gddr6_detect_compatible_gpus(void);

#endif // GDDR6_H
