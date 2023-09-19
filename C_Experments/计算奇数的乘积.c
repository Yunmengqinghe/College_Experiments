#include<stdio.h>
int main()
{
    int i,x,n,sum;
    while(scanf("%d",&i)!=EOF)
    {
        sum=1;
        for(n=1;n<=i;n++)
        {
            scanf("%d",&x);
            if(x%2!=0)
            {
            sum*=x;
            }
        }
    printf("%d\n",sum);
    }
    return 0;
}
