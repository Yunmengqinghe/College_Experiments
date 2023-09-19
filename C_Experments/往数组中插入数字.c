#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int i,j,t,a[20];
    int n,m,p;
    printf("请输入一个排好序的九位数字数组:");
    for(i=0;i<9;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("请输入你想要插入的数:");
    scanf("%d",&n);
    for(i=0;i<9;i++)
    {
        p=0;
        if(n>=a[i]&&n<a[i+1])
        {
            for(j=8;j>i;j--)
            {
                a[j+1]=a[j];
            }
            a[i+1]=n;
            p=1;
        }
        else if(n>a[8])
        {
            a[9]=n;
            p=1;
        }
            if(p==1)
            {
                break;
            }
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }

	return 0;
}

