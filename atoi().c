#include <stdio.h>

int atoi(char *str)
{
    int result = 0;
    int sign = 1;
    
    if(str[0] == '-')
    {
        sign = -1;
        str++;
    }
    
    while (str[0] >= '0' && str[0] <= '9')
    {
        result = result * 10 + (*str - '0');
        str++; // Move to the next character
    }
    
    return sign * result;
}

int main()
{
    int n;
    scanf("%d", &n);
    char str[10];
    
    // Add a space before %c to skip any leading whitespace characters
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &str[i]); // Read characters with leading whitespace skipped
    }

    // Null-terminate the string
    str[n] = '\0';
    
    int result = atoi(str);    
    
    printf("Result in integer: %d\n", result);

    return 0;
}
