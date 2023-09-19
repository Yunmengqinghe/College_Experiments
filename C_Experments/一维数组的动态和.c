#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int b[100000];
int main()
{
    char c;
    int n,m,c1,c2,a[100000];
    int temp;
    c1=0;
    c2=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        getchar();
        c=getchar();
        switch(c)
        {
            case 'I':
                if(c2==c1-1)
                {
                    c2++;
                    c1++;
                    scanf("%d",&a[c2]);

                    if(c2==0)
                    {
                        b[0]=a[0];
                    }
                    else
                    {
                        b[c2]=b[c2-1]+a[c2];
                    }

                }
                else
                {
                    scanf("%d",&temp);
                    for(int j=c1;j>c2;j--)
                    {
                        a[j+1]=a[j];
                        b[j+1]=b[j];
                    }
                    c2++;
                    a[c2]=temp;
                    c1++;

                    b[c2]=b[c2+1]-a[c2+1]+temp;
                    for(int j=c2+1;j<c1;j++)
                    {
                        b[j]+=temp;
                    }

                }

                break;

            case 'D':
                temp=a[c2];
                for(int j=c2;j<c1;j++)
                {
                    a[j]=a[j+1];
                    b[j]=b[j+1]-temp;
                }
//                for(int j=0;j<c1;j++)
//                {
//                    printf("a[%d]=%d b[%d]=%d\n",j,a[j],j,b[j]);
//                }

                if(c2!=0)
                {
                    c2--;
                    c1--;
                }
                else
                {
                    c1--;
                }

                break;

            case 'L':
                if(c2!=0)
                {
                    c2--;
                }
                break;

            case 'R':
                if(c2!=c1-1)
                {
                    c2++;
                }
                break;

            case 'Q':
                scanf("%d",&m);
                temp=b[0];
                for(int j=0;j<m;j++)
                {
                    if(temp<b[j])
                    {
                        temp=b[j];
                    }
                }
                printf("%d\n",temp);
                break;
        }
    }
    return 0;
}
