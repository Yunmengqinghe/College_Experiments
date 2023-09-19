#include<stdio.h>
#include<stdlib.h>

void scan(int a[]);
void sort_1(int a[]);
void output(int a[]);

int main()
{
    int a[10],m;
    printf("请输入十个数字:");
    scanf("%d",m);
    scan(a,m);
    sort_1(a);
    output(a);
    return 0;
}

void scan(int a[],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
}

void sort_1(int a[])
{
    int i,j,t;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(a[j]<=a[i])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }

        }

    }
}

void output(int a[])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d",a[i]);
        if(i<9)
        {
            printf(" ");
        }
    }

}
