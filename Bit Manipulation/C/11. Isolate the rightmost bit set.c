#include<stdio.h>
#include<math.h>

int isoRmB(int n)
{
    return n & ~(n -1);
}

int main()
{
    printf("Iso Res = %d\n", isoRmB(12));         // Iso Res = 4
    return 0;
}
