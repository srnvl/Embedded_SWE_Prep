#include <stdio.h>
#include <stdbool.h>

// int powTwo(int n)
// {
//     if(n > 0)
//     {
//         if((n & (n - 1)) == 0)
//         {
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     return false;
// }

int posOfsetBit(int n)
{
    int i = 1;
    int pos = 1;
    // if(powTwo(n) == false)
    // {
    //     return -1;
    // }
    // else{
        while((n & i) == 0)
        {
            i = i << 1;
            pos += 1;
        }
    // }
    return pos;
}

int main()
{
    int n  = 4;
    int res = posOfsetBit(4);
    printf("%d", res);
    return 0;
}
