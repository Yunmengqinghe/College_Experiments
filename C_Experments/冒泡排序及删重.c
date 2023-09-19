#include<stdio.h>
int main()
{
    int a[1000];
    int n,m,i,j,k,t,z;
    while(~scanf("%d",&m))
    {
        for(z=0;z<m;z++)
        {
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    scanf("%d",&a[i]);
                }
                for(i=0;i<n-1;i++)
                {
                    for(j=0;j<n-1-i;j++)
                    {
                        if(a[j]<a[j+1])
                        {
                            t=a[j];
                            a[j]=a[j+1];
                            a[j+1]=t;
                        }
                    }
                }

                for(i=0;i<n-1;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(a[i]==a[j])
                        {
                            for(k=j;k<n-1;k++)
                            {
                                a[k]=a[k+1];
                            }
                            --n;
                            --j;
                        }
                    }
                }
                printf("%d\n",a[1]);
        }


    }
    return 0;
}


