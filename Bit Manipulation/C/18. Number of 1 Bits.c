#include <stdio.h>

int hammingWeight(uint_t n)
{  
  int count = 0;
  while(n > 0)
  {
    n = n & (n - 1);     // n - 1 : Flips the rightmost set bit to 0 and the bits to it's right to 1. n = n & (n -1): Will give us a new result 
    count++;
  }
  return count;
}

int main()
{
  printf("Enter a value for n: );
  scanf("%d", &n);
  int count = hammingWeight(n);
  printf("No. of 1 bits is: %d, count);
  return 0;
}
