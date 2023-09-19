#include<stdio.h>
int main()
{
    int a,i;
    double x=0;

    printf("请输入你要将多少钱和存多少年定期:");

    while(scanf("%lf %d",&x,&a)!=EOF)
    {
        for(i=1;i<=a;i++)
        {
            x=0.033*x+x;
        }
        printf("%f\n",x);
        x=0;
    }




    return 0;
}
