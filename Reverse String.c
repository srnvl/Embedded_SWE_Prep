#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverseString(char *str)
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}


int main()
{
    char str[] = "BRUCE WAYNE";
    printf("original string: %s\n", str);
    reverseString(str);
    printf("reverse string: %s\n", str);
    return 0;
}
