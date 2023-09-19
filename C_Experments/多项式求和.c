#include<stdio.h>
int main()
{
    int m ,n ,i=0;
    double j=0,sign=-1,term=0,sum=0;
    while(scanf("%d",&m)!=EOF)
    {
        for(i=1;i<=m;i++)
        {
            scanf("%d",&n);
            for(j=1;j<=n;++j)
            {
                sign=-1*sign;
                term=sign*(1/j);
                sum=sum+term;
            }

            printf("%.2lf\n",sum);
            sum=0;
            sign=-1;
        }
    }
    return 0;
}
