#include<stdio.h>

int main()
{
    int a,b,c;
    int i,num=1;
    while(~scanf("%d %d",&a,&b))
    {
        if(a==0&&b==0)
        {
            exit(0);
        }
        else
        {
            num=a;
            for(i=1;i<b;i++)
            {
                num=(num%1000)*a;
                c=num%1000;
            }
        }
            printf("%d\n",c);
    }
    return 0;
}
