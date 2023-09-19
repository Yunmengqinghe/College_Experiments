#include<stdio.h>
#include<stdlib.h>

void exchange(int *x,int *y);
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    exchange(&x,&y);
    printf("x=%d y=%d",x,y);
    return 0;
}

void exchange(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;

}
