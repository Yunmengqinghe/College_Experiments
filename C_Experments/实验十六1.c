#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n,m=0;
    float a,b,d;
    srand(time(NULL));
    printf("请输入n:");
    scanf("%d",&n);
    printf("请输入大于0的a,b:");
    scanf("%f %f",&a,&b);
    d=1+b*b;
    for(int i=1;i<=n;i++)
    {
        float x=rand()*1.0/RAND_MAX*(b-a)+a;
        float y=rand()*1.0/RAND_MAX*d;
        if(y<=1+x*x)
        {
            m++;
        }
    }
    float s=m*(b-a)*d/n;
    printf("f(x)的定积分=%f",s);
    return 0;
}
