#include<stdio.h>
#include<math.h>
int main()
{
    int i,n,m=0;
    int x=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n-1;i++)
        {
            x=(x+1)*2;
        }
        printf("%d\n",x);
        x=1;
    }
    return 0;
}
