#include<stdio.h>

int main(void)
{
    int n, m ,i ;
    int max,min;
    int a[100];
    double sum;

    while(scanf("%d",&n)!=EOF)
    {
        max=0;
        min=200;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

            if(min>a[i])
            {
                min=a[i];
            }
            if(max<a[i])
            {
                max=a[i];
            }
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i];
        }

        printf("%.2lf\n",(sum-max-min)/(n-2));
    }
    return 0;
}
