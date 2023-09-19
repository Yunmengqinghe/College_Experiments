#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f1(float x);
float integralF1(float a,float b);
float f2(float x);
float integralF2(float a,float b);
float Integral(float (*f)(float),float a,float b);

int main()
{
    int temp;
    float a,b,y;

    printf("请输入要计算的函数(f1,f2分别用1,2代替):\n");
    scanf("%d",&temp);

    printf("请输入a b:\n");
    scanf("%f %f",&a,&b);

    switch(temp)
    {
        case 1:
            y=Integral(f1,a,b);
            break;
        case 2:
            y=Integral(f2,a,b);
            break;
    }
    printf("%f\n",y);
    return 0;
}

float f1(float x)
{
    float y=1.0+pow(x,2);
    return y;
}

float integralF1(float a, float b)
{
    int n=100;
    float h,t;
    h=(b-a)/n;
    t=(f1(a)+f1(b))/2.0;

    for(int i=1;i<=n;i++)
    {
        t+=f1(a+i*h);
    }

    return h*t;
}

float f2(float x)
{
    float y=x/(1+pow(x,2));
    return y;
}

float integralF2(float a, float b)
{
    int n=100;
    float h,t;
    h=(b-a)/n;
    t=(f2(a)+f2(b))/2.0;

    for(int i=1;i<=n;i++)
    {
        t+=f2(a+i*h);
    }

    return h*t;
}

float Integral(float (*f)(float),float a,float b)
{
    int n=100;
    float h,t;
    h=(b-a)/n;
    t=(f(a)+f(b))/2.0;

    for(int i=1;i<=n;i++)
    {
        t+=f(a+i*h);
    }

    return h*t;
}
