#include<stdio.h>
#define PI 3.14
int main()

{
    double r,v;
    scanf("%lf",&r);

    if(r<=100 && r>=0)
    {
    v=4.0/3.0*PI*r*r*r;
    printf("%.2lf",v);
    }

    else
    {
        printf("���������룺");
    }

    return 0;
}
