#include<stdio.h>
#include<math.h>

int main()
{
    int x,y,z,i,n;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        z=0;
        if(x==0&&y==0)
        {
            return 0;
        }

            for(x;x<=y;x++)
            {
                n=pow(x,2)+x+41;
                for(i=2;i<=sqrt(n);i++)
                {
                    if(n%i==0)
                    {
                        z=1;
                        break;
                    }
                }
                        if(z==1)
                    {
                        break;
                    }

            }


            if(z==1)
            {
                printf("Sorry\n");
            }
            else
            {
                printf("OK\n");
            }

    }
    return 0;
}
