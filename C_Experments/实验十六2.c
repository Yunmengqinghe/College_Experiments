#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int k=0,n;
    srand(time(NULL));
    printf("请输入要投掷的点数：");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        float x=rand()*1.0/RAND_MAX;
        float y=rand()*1.0/RAND_MAX;
        if(x*x+y*y<=1)
        {
            k++;
        }
    }
    float pi=4.0*k/n;
    printf("pi=%f",pi);
    return 0;
}
