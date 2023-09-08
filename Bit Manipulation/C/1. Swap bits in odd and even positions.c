#include <stdio.h>

int main()
{
    int a = 7;
    int even_mask = 0xAAAAAAAA;
    int odd_mask = 0x55555555;
    
    int even_bits = a & even_mask;
    int odd_bits = a & odd_mask;
    
    even_bits = even_bits >> 1;
    odd_bits = odd_bits << 1;
    
    int swapped_bits = even_bits | odd_bits;
    
    printf("Swapped bit values is: %d", swapped_bits);
    

    return 0;
}
