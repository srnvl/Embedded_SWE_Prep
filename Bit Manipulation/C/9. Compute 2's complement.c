#include<stdio.h>

int twosComp(int n)
{
    return -n;
}

int main()
{
    int n = 4;
    printf("%d", twosComp(n));
    return 0;
}
