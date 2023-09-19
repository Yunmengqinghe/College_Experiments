#include<stdio.h>
int main()
{
    int n=0,i=1,sum1=0,sum2=0,sum3=0;
    double a=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            break;
        }

        else if(n!=0)
        {
        for(i=1 && i!=0 && i<100;i<=n;i++)
        {
                scanf("%lf",&a);

                if(a<0)
                {
                    sum1=sum1+1;
                }

                else if(a==0)
                {
                    sum2=sum2+1;
                }

                else if(a>0)
                {
                    sum3=sum3+1;
                }
        }


        }
        printf("%d %d %d\n",sum1,sum2,sum3);
        sum1=0;
        sum2=0;
        sum3=0;
    }
    return 0;

}
