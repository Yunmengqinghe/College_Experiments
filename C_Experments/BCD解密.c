#include<stdio.h>

int main()
{
    int x=0;
    while(scanf("%d",&x)!=EOF)
    {
    printf("BCD=%x\n",x);//���߿���ʹ��n=x/16,m=x%16.x=n*10+m
    }
    return 0;
}
