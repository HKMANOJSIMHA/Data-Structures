#include<stdio.h>
int factorial (int);
int main()
{
    int n,fact;
    printf("give a no.\n");
    scanf("%d",&n);
    if(n==0)
    printf("0!=1");
    else
    {
    fact=factorial(n);
    printf("factorial of %d is %d",n,fact);
    }
    return 0;
}
int factorial(int n)
{
    int i;
    if(n<=1)
    {
        return 1;
    }
    return (n*factorial(n-1));

}
