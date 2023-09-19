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

        printf("�ǵ���=%d\n",a);
        printf("����=%d\n",b);
    }
}

//�ǵݹ�
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

//�ݹ�
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
