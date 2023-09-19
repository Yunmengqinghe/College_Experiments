#include<stdio.h>
#include<math.h>

int main()
{
    double a,b;

    while(scanf("%lf",&a)!=EOF)
    {
        b=fabs(a);
        printf("%.2lf\n",b);
    }
    return 0;
}
