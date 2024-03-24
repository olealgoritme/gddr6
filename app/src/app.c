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
    gddr6_init();
    int num_devs = gddr6_detect_compatible_gpus();

    if (num_devs == 0)
    {
        printf("No compatible GPU found.\n");
        return 1;
    }

    gddr6_memory_map();
    gddr6_monitor_temperatures();

    return 0;
}
