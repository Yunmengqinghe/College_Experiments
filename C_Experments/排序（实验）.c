#include<stdio.h>
#include<stdlib.h>
const int N=10;
void input(int *);
void change(int *,int *,int *);
void output(int *,int ,int );

int main()
{
    int a[11];
    int max,min;
    input(a);
    change(a,&max,&min);
    output(a,max,min);
    return 0;
}

void input(int *a)
{
    for(int i=0;i<N;i++)
    {
        scanf("%d",a+i);
    }
}

void change(int *a,int *max,int *min)
{
    int p=0,q=0,t;
    *max=*a;
    *min=*a;
    for(int i=0;i<N;i++)
    {
        if(*max<*(a+i))
        {
            *max=*(a+i);
            p=i;
        }
        if(*min>*(a+i))
        {
            *min=*(a+i);
            q=i;
        }
    }
    t=*(a+q);
    *(a+q)=*a;
    *a=t;
    t=*(a+p);
    *(a+p)=*(a+N-1);
    *(a+N-1)=t;
}

void output(int *a,int max,int min)
{
    for(int i=0;i<N;i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n");
    printf("max=%d min=%d",max,min);
}
