#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int i,j,t,a[20];
    int n,m,p;
    printf("������һ���ź���ľ�λ��������:");
    for(i=0;i<9;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("����������Ҫ�������:");
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

