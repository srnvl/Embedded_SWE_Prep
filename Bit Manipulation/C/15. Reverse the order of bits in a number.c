#include<stdio.h>

unsigned int reverse(unsigned int n)
{
    int rev = 0;
    while(n > 0)
    {
        rev = rev << 1;
        if(n & 1 == 1)
        {
           rev = rev ^ 1;
        }
        n = n >> 1;
    }
    return rev;
}


int main()
{
    int n = 11;
    printf("%u", reverse(11));
    return 0;
}
