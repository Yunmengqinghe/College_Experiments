#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void scan(int a[][50],int n,int m);
void find(int a[][50],int n,int m);
double all(int a[][50],int n,int m);
void all_1(int a[][50],int n,int m);

int main()
{
    int n,m;
    double x;
    int a[50][50];
    scanf("%d%d",&n,&m);
    scan(a,n,m);
    find(a,n,m);
    x=all(a,n,m);
    printf("总成绩是:%.2lf分",x);
    all_1(a,n,m);
    return 0;
}

void scan(int a[][50],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void find(int a[][50],int n,int m)
{
    int i,j,k,t;
    for(i=0;i<n;i++)
    {
        t=0;
        for(j=0;j<m;j++)
        {
            if(a[i][j]<60)
            {
                t=1;
                printf("不及格学生学号:%d\n",i+1);
                printf("各门课成绩为:\n");
                for(k=0;k<m;k++)
                {
                    printf("第%d门课的成绩是%d分\n",k+1,a[i][k]);
                }
            }

                if(t==1)
                {
                    break;
                }
        }
    }

}
double all(int a[][50],int n,int m)
{
    int i,j;
    double x,b,c;
    x=n*m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            b+=a[i][j];
        }
    }
    c=(b/x)*1.0;
    return c;
}
void all_1(int a[][50],int n,int m)
{
    int b[n];
    int i,j,k,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            b[i]+=a[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        t=0;
        for(j=0;j<n;j++)
        {
            if(b[t]<b[j])
            {
                t=j;
            }
        }
        printf("排名第%d的学生学号是%d，总成绩是%d\n",i+1,t+1,b[t]);
        b[t]=-1;
    }

}

