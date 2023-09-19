#include<stdio.h>
#include<stdlib.h>

void input(int,int*);
void reserve(int,int*);
void output(int,int*);

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    input(n,a);
    reserve(n,a);
    output(n,a);
}

void input(int n,int *a)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
}

void reserve(int n,int *a)
{
    int t;
    for(int i=0;i<n;i++)
    {
        n--;
        t=*(a+i);
        *(a+i)=*(a+n);
        *(a+n)=t;
    }

}

void output(int n,int *a)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}
