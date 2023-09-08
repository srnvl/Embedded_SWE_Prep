#include<stdio.h>

int posLmB(int n)
{
    int pos = 0;
    while(n > 0)
    {
        n = n >> 1;
        pos = pos + 1;
    }
    
    return pos;
}

int main()
{
    printf("Position of LMB is: %d\n", posLmB(5));
    return 0;
}
