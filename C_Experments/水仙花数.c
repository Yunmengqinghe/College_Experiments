#include<stdio.h>
#include<math.h>

int main()
{
    int m=0,n=0,x=0;
    int a=0,b=0,c=0;
    int i=0;

    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(m;m<=n;m++)
        {

            a=m/100%10;
            b=m/10%10;
            c=m%10;

            if(m==pow(a,3)+pow(b,3)+pow(c,3))
            {
                x+=1;

                if(x==1)
                {
                    printf("%d",m);
                }
                else
                {
                    printf(" %d",m);
                }
            }

        }

                if(x==0)
                {
                    printf("no");
                }

                    printf("\n");
                    x=0;
    }

    return 0;
}
