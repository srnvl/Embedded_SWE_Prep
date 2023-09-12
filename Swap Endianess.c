#include <stdio.h>
#include <stdint.h>

uint32_t swap_endian(uint32_t value) {
    return ((value >> 24) & 0xFF) | ((value >> 8) & 0xFF00) | ((value << 8) & 0xFF0000) | ((value << 24) & 0xFF000000);
}

int main()
{
    int big_endian = 0x12345678;
    int little_endian = 0x78563412;
    int result1, result2;
    result1 = swap_endian(big_endian);
    result2 = swap_endian(little_endian);
    printf("Big Endian to Little Endian: 0x%x\n", result1);
    printf("Little Endian to Big Endian: 0x%x\n", result2);
    return 0;
}
