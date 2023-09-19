#include<stdio.h>
#include<math.h>
int main()
{
    int a,c,n;
    scanf("%d%d",&a,&n);
    c=pow(a,n);

    if(c<1000000 && c>-1000000)
    {
    printf("%d",c);
    }

    else
    {
        printf("no");
    }

    return 0;
}
