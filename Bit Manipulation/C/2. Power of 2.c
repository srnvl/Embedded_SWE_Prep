# include <stdio.h>
# include <stdbool.h>

bool isPowerofTwo(int n)
{
    while(n > 0)
    {
        if((n & (n - 1)) == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }
}

int main()
{
    int n = 7;
    bool x = isPowerofTwo(n);
    printf("%d", x);
    return 0;
}
