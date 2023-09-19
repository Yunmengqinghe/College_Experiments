#include<stdio.h>
#include<stdlib.h>
void input(int a[],int n);
void sort(int a[],int n);
void output(int a[],int n);


int main()
{
    int n;
    int a[1000];
    printf("请输入数组的长度:");
    scanf("%d",&n);

    input(a,n);
    sort(a,n);
    output(a,n);

    return 0;
}

void input(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void sort(int a[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void output(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}
