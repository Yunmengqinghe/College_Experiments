#include<stdio.h>
#include<stdlib.h>
long fibonacci(int n);

int main()
{
    int n,a;
    scanf("%d",&n);
    if(n==0)
    {
        exit(0);
    }
    else
    {
        a=fibonacci(n);
        printf("%ld\n",a);
    }

}

long fibonacci(int n)
{
    int r;
    if(n>4)
    {
       r=fibonacci(n-1)+fibonacci(n-3);
    }
    else
    {
        r=n;
    }

    return r;
}
