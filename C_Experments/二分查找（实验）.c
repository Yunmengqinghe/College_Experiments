#include<stdio.h>
#include<stdlib.h>
void intput(int a[],int *x,int *right);
int find_1(int a[],int left,int right,int x);
int find_2(int a[],int left,int right,int x);
void output(int b);

int main()
{
    int x,left,right,b;
    int a[1000];
    left=0;
    intput(a,&x,&right);
    b=find_1(a,left,right,x);
    b=find_2(a,left,right,x);
    output(b);
    return 0;
}

void intput(int a[],int *x,int *right)
{
    printf("�������������:");
    scanf("%d",&*right);
    for(int i=0;i<*right;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("������Ҫ������Ԫ��:");
    scanf("%d",&*x);
}

//�ݹ�
int find_1(int a[],int left,int right,int x)
{
    int mid;
    mid=(left+right)/2;
    if(x==a[mid])
    {
        return mid;
    }
    else if(x<a[mid])
    {
        right=mid-1;
        find_1(a,left,right,x);
    }
    else if(x>a[mid])
    {
        left=mid+1;
        find_1(a,left,right,x);
    }
}

//�ǵݹ�
int find_2(int a[],int left,int right,int x)
{
    int mid;
    mid=(left+right)/2;
    while(x!=a[mid])
    {
        if(x<a[mid])
        {
            mid=mid-1;
        }
        else if(x>a[mid])
        {
            mid=mid+1;
        }
    }
    return mid;
}

void output(int b)
{
    printf("��Ԫ��λ�ڵ�%dλ��",b+1);
}
