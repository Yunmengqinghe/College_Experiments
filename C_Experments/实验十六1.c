#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n,m=0;
    float a,b,d;
    srand(time(NULL));
    printf("������n:");
    scanf("%d",&n);
    printf("���������0��a,b:");
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
    printf("f(x)�Ķ�����=%f",s);
    return 0;
}
