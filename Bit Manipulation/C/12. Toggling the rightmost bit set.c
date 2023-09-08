#include<stdio.h>
#include<math.h>

int toggRmB(int n)
{
    return n & (n - 1);
}
int main()
{
    printf("Toggle Res = %d\n", toggRmB(12));     // Toggle Res = 8
    return 0;
}
