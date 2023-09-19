#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a,b,c,ex;
    printf("请输入三个数字：");
    scanf("%d%d%d",&a,&b,&c);
            if(a>b)
            {
               ex=a;
               a=b;
               b=ex;
            }
            if(a>c)
            {
                ex=a;
                a=c;
                c=ex;
            }
            if(b>c)
            {
                ex=b;
                b=c;
                c=ex;
            }
            printf("a=%d b=%d c=%d",a,b,c);


    return 0;
}
