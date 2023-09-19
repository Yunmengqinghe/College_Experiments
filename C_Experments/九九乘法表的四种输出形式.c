#include<stdio.h>
#include<stdio.h>
int main()
{
    int n,m;
    int i,j,k;
    int x,y;
    int a,b;
          for(i=1;i<=9;i++)
          {

                    for(j=1;j<i+1;j++)
                    {
                        a=i,b=j;
                        printf("%dX%d=%d\t",b,a,a*b);

                    }
                    printf("\n");
          }


            for(i=1;i<=9;i++)
            {
                a=i;
                for(j=1;j<a;j++)
                {
                    printf("\t");
                }
                    for(k=1;k<=9;k++)
                    {
                        b=k;
                        if(a<=b)
                        {
                            printf("%dX%d=%d\t",a,b,a*b);
                        }
                    }
                printf("\n");
            }

            m=8;
            for(i=1;i<=9;i++)
            {
                for(j=1;j<=m;j++)
                {
                    printf("    ");
                }
                m--;
                for(k=1;k<=9;k++)
                {
                    a=i,b=k;
                    if(i>=k)
                    {
                        printf("%dX%d=%d",b,a,a*b);
                        if(a*b<=9)
                        {
                            printf("   ");
                        }
                        else if(a*b>9)
                        {
                            printf("  ");
                        }
                    }
                }
                printf("\n");
            }

            m=8;
            for(i=9;i>=1;i--)
            {
                for(j=1;j<=m;j++)
                {
                    printf("    ");
                }
                m--;
                for(k=1;k<=9;k++)
                {
                    a=i,b=k;
                    if(i<=k)
                    {
                        printf("%dX%d=%d",a,b,a*b);
                        if(a*b<=9)
                        {
                            printf("   ");
                        }
                        else if(a*b>9)
                        {
                            printf("  ");
                        }
                    }
                }
                printf("\n");
            }


    return 0;
}
