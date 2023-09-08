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
