#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void change(char a[],int n,int m);

int main()
{
    int n,m,i;
    char a[1000];
    scanf("%d",&n);//n是输入的个数
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
    }
    scanf("%d",&m);//m是要移多少位
    change(a,n,m);
    for(i=0;i<n;i++)
    {
        printf("%c",a[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }
    return 0;
}

void change(char a[],int n,int m)
{
    int i,j;
    char t;
    for(i=1;i<=m;i++)
    {
        t=a[n-1];
        for(j=n-2;j>=0;j--)
        {
            a[j+1]=a[j];
        }
        a[0]=t;
    }
}

