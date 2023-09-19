#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int i,j,t,a[4][4];
    int n,m;
    printf("请输入一个三阶矩阵:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    n=a[0][0]+a[1][1]+a[2][2];
    m=a[0][2]+a[1][1]+a[2][0];

    printf("主对角线之和=%d 副对角线之和=%d",n,m);


	return 0;
}
