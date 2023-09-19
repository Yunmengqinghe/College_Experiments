#include<stdio.h>
#include<stdlib.h>
int recursion(int n);
int unrecursion(int n);

int main()
{
    int a,b,n;
    while(~scanf("%d",&n))
    {
        a=recursion(n);
        b=unrecursion(n);

        printf("非递推=%d\n",a);
        printf("递推=%d\n",b);
    }
}

//非递归
int recursion(int n)
{
    int a,i;
    a=1;
    for(i=1;i<=n;i++)
    {
        a*=i;
    }
    return a;
}

//递归
int unrecursion(int n)
{
    int a;
    if(n<=2&&n>=1)
    {
        a=n;
    }
    else
    {
        a=unrecursion(n-1)*n;
    }
    return a;
}
