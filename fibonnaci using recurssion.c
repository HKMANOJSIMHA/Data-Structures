#include<stdio.h>
void fnprintFibonacci(int,int,int);
int main()
{
int k,n;
int i=0,j=1,f;
printf("Enter the range of the Fibonacci series: ");
scanf("%d",&n);
printf("Fibonacci Series upto %d are: ",n);
printf("%d %d ",0,1);
fnprintFibonacci(0,1,n);
return 0;
}
void fnprintFibonacci(int first,int second,int n)
{
  int third;
  if(n>0)
  {
   third = first + second;
   first = second;
   second = third;
   printf("%d ",third);
   fnprintFibonacci(first,second,n-1);
  }
}