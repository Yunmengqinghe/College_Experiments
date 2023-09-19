#include<stdio.h>
#include<stdlib.h>

void scan(int a[][3]);
void find(int a[][3],int *x,int *y);
void output(int a[][3],int x,int y);

int main()
{
    int x,y;
    int a[3][3];
    printf("请输入一个三阶矩阵:\n");
    scan(a);
    find(a,&x,&y);
    output(a,x,y);
    return 0;
}

void scan(int a[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void find(int a[][3],int *x,int *y)
{
    int i,j;
    *x=0,*y=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[*x][*y]<a[i][j])
            {
                *x=i;
                *y=j;
            }
        }
    }
}

void output(int a[][3],int x,int y)
{
    printf("%d",a[x][y]);
}
