#include<stdio.h>
#include<stdlib.h>
float power_1(float x,int n);
float power_2(float x,int n);

int main()
{
    int n;
    float x,a,b;
    while(scanf("%f %d",&x,&n)!=EOF)
    {
        a=power_1(x,n);
        b=power_2(x,n);
        printf("%f",a);
        printf("%f",b);
    }
}

//�ǵݹ�
float power_1(float x,int n)
{
    int i;
    float a;
    a=x;
    for(i=1;i<n;i++)
    {
        a*=a;
    }
    return a;
}

//�ݹ�
float power_2(float x,int n)
{
    float a;
    if(n==1)
    {
        a=x;
    }
    else
    {
        a=x*power_2(x,n-1);
    }

    return a;
}

