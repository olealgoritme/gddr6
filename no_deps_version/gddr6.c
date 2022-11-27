#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>


int main(int argc, char **argv)
{
    int fd;
    int map_size = 4096UL;
    void *map_base, *virt_addr;
    uint32_t read_result, base_offset, temp;
    //uint32_t bar = 0xFB000000; // GA102 + GA104
    uint32_t bar = 0xEC000000; // AD102 (RTX 4090)
    uint32_t offset = bar + 0x0000E2A8; // GA102 + AD102
    //uint32_t offset = bar + 0x0000EE50; // GA104

    char *MEM_RES = "\x2f\x64\x65\x76\x2f\x6d\x65\x6d";

    while (1)
    {
        if ((fd = open(MEM_RES, O_RDWR | O_SYNC)) == -1)
        {
          printf("Can't read memory. Are you r00t?\n");
          exit(-1);
        }

        base_offset = offset & ~(sysconf(_SC_PAGE_SIZE)-1);
        map_base = mmap(0, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, base_offset);

        if (!map_base)
        {
          printf("Can't map memory. Are you r00t?\n");
          exit(-1);
        }

        virt_addr = map_base + offset - base_offset;
        read_result = *((uint32_t *) virt_addr);
        temp = (read_result & 0x00000fff) / 0x20;
        printf("\rGDDR6X VRAM Temp: %d°c", temp);
        fflush(stdout);

        if (munmap(map_base, map_size) == -1)
        {
          printf("Can't unmap memory!\n");
          exit(-1);
        }

        close(fd);
        sleep(1);
    }

    return 0;
}
