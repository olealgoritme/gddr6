// app.c
#include "gddr6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int per_module = 0;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--per-module") == 0)
            per_module = 1;
        else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
        {
            printf("Usage: %s [--per-module]\n"
                   "  (default)      show VRAM temperature (Blackwell: hottest module)\n"
                   "  --per-module   show each GDDR7 module separately (Blackwell only)\n",
                   argv[0]);
            return 0;
        }
    }

    register_signal_handlers();
    gddr6_init();
    int num_devs = gddr6_detect_compatible_gpus();

    if (num_devs == 0)
    {
        printf("No compatible GPU found.\n");
        return 1;
    }

    gddr6_memory_map();
    gddr6_monitor_temperatures(per_module);

    return 0;
}
