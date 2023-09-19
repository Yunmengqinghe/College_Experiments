#include<stdio.h>
#include<math.h>

int main()
{
    double a1,a2,a3,a4,x;

    while(scanf("%lf %lf %lf %lf",&a1,&a2,&a3,&a4)!=EOF)
{
    x=sqrt((a1-a3)*(a1-a3)+(a2-a4)*(a2-a4));
    printf("%.2lf\n",x);

}

    return 0;
}
