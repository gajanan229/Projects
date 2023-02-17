#include<stdio.h>
int main()
{
  int n=9;
  int rows, num, i;
  
  for(rows=1; rows<=n; rows++)
  {
    num=1;
    for( i=1; i<=rows; i++)
    {
      printf("%d ",num);
      num = num * (rows-i)/i;
    }
    printf("\n");
  }
  return 0;
}
