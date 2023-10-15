#include <stdio.h>

int main()
{
    int x = 1;
    
    char* p = (char*) &x;
    
    if(*p == 1)
    {
        printf("Big Endian");
    }
    else {
        printf("Little Endian");
    }
    return 0;
