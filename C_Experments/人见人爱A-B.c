#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,m,i;
    int j,count;
    int temp=0,z;
    int a[100]={0},b[100]={0},c[100]={0};
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        {
            exit(0);
        }

        else
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }

            for(i=0;i<m;i++)
            {
                scanf("%d",&b[i]);
            }

                for(i=0;i<n;i++)
                {
                    for(j=0;j<m;j++)
                    {
                        if(a[i]==b[j])
                        {
                            a[i]=0;
                            break;
                        }

                    }
                }


                    for(i=0,j=0;i<n;i++)
                    {
                        if(a[i]!=0)
                        {
                           c[j]=a[i];
                           j++;
                        }
                    }

                    if(j==0)
                    {
                        printf("NULL\n");
                    }
                    else
                    {
                        for(i=0;i<j;i++)
                        {
                            for(z=0;z<j-1;z++)
                            {
                                if(a[z]>a[z+1])
                                {
                                    temp=a[z];
                                    a[z]=a[z+1];
                                    a[z+1]=temp;
                                }
                            }
                        }

                        for(i=0;i<j;i++)
                        {
                            printf("%d\n",c[i]);
                        }
                    }
            }

    }
    return 0;
}
