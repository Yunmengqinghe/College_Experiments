#include<stdio.h>
#include<math.h>
int main()

{
    int i=1,m=0;
    double n=0.0,sum=0.0;

    while(scanf("%lf %d",&n,&m)!=EOF)
    {
        for(i=1;i<=m;i++)
        {
          sum=sum+n;
          n=sqrt(n);

        }

        printf("%.2lf\n",sum);

        n=0.0;
        sum=0.0;
    }


    return 0;
}
