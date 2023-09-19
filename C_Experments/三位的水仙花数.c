#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i;
    int a,b,c;
    m=1000;
    for(n=100;n<m;n++)
    {
        i=0;
        a=n%10;
        b=n/10%10;
        c=n/100%10;
        if(n==pow(a,3)+pow(b,3)+pow(c,3))
        {
            i++;
            printf("%d\n",n);
        }
    }
    return 0;
}
