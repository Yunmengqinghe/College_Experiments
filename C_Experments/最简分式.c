#include<stdio.h>
int main()
{
    int m,z,a,b,c;
    int i,n,e,f;
    while(~scanf("%d/%d",&z,&m))
    {
        a=z,b=m;
        while(b>0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        e=z/a;
        f=m/a;
        printf("%d/%d",e,f);
    }
    return 0;
}
