#include<stdio.h>

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int x = 10, y = 5;
    s(&x, &y);      // Here we are sending referenced values of a and b as if we don't do it we'll be modifying only the copies and 
// not the original variables
    printf("After swapping: x = %d, y = %d", x, y);
}

------- OR ----------

#include <stdio.h>

int main()
{
    int x = 10, y = 5;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("After swapping: x = %d, y = %d", x, y);
    return 0;
}
