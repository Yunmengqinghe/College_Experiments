#include<stdio.h>;
#include<math.h>;
int main()
{
    double a,b,c,x1,x2;
    double d,x3,x0,delta;
    printf("请输入方程的三个系数：");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a!=0)
    {
        d=b*b-4*a*c;
        delta=sqrt(abs(d));
            if(d==0)
            {
                x0=(-b)/(2*a);
                printf("x0=%.1lf\n",x0);
            }
            else if(d>0)
            {
                x1=(-b+delta)/(2*a);
                x2=(-b-delta)/(2*a);
                printf("x1=%.1lf x2=%.1lf\n",x1,x2);
            }
            else
            {
                printf("x1=%.1lf+%.1lfi x2=%.1lf%.1lfi",-b/(2*a),delta/(2*a),-b/(2*a),-delta/(2*a));

            }

    }

    else
    {
        printf("出错！");
        return 0;
    }
    return 0;
}
