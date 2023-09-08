#include <stdio.h>

int hammingWeight(uint_t n)
{  
  int count = 0;
  while (n > 0)
  {
    n = n & (n - 1); // n - 1: Flips the rightmost set bit to 0 and the bits to its right to 1. n = n & (n - 1): Will give us a new result 
    count++;
  }
  return count;
}

int main()
{
  uint_t n; // Declare n
  printf("Enter a value for n: "); // Added a prompt
  scanf("%u", &n); // Use %u for an unsigned integer
  int count = hammingWeight(n);
  printf("No. of 1 bits is: %d\n", count); // Corrected the format string and added \n
  return 0;
}
