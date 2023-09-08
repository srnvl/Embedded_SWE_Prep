#include<stdio.h>

int add(int a, int b)
{
    while(b > 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main()
{
    int a = 3, b = 1;
    int result = add(a, b);
    printf("Result: %d", result);
    return 0;
}
 
