#include<stdio.h>
#include<math.h>

int posRmB(int n){
  return log2(n & ~(n - 1)) + 1;
}

int main()
{
  printf("Pos Res = %d", posRmB(12);  // Pos Res = 3
  return 0;
}
