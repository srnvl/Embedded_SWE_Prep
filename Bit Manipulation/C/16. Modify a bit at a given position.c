# include <stdio.h>

int modifyBit(int n, int p, int b)
{
    mask = 1 << p;
    n = (n & ~mask) | (b << p);
    return n;
}

int main()
{
  int n, b, p;
  scanf("%d%d%d", n, b, p);
  int x = modifyBit(n, b, p);
  printf("x:%d", x);
  return 0;
}
