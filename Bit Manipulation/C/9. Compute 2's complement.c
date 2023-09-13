#include<stdio.h>

int twosComp(int n)
{
    int ones_comp = ~n;
    int twos_comp = ones_comp + 1;
    return twos_comp;
}

int main()
{
    int n = 4;
    printf("%d", twosComp(n));
    return 0;
}
