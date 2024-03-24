// app.c
#include "gddr6.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void register_signal_handlers(void)
{
    struct sigaction sa;
    sa.sa_handler = gddr6_cleanup;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
}

int main(int argc, char **argv)
{

    register_signal_handlers();
    struct device devices[32];
    int num_devs = gddr6_detect_compatible_gpus(devices, 32);

    if (num_devs == 0)
    {
        printf("No compatible GPU found.\n");
        return 1;
    }

    for (int i = 0; i < num_devs; i++)
    {
        struct device *device = &devices[i];
        printf("Device: %s %s (%s / 0x%04x) pci=%x:%x:%x\n", device->name, device->vram,
            device->arch, device->dev_id, device->bus, device->dev, device->func);
    }

    gddr6_initialize();
    gddr6_monitor_temperatures(devices, num_devs);
    gddr6_cleanup(0);

    return 0;
}
