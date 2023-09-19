#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a[30][100]={{1},{1,1}};
    int n,i,j,k;
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }


    for(i=0;i<n;i++)
    {
        for(k=1;k<40-3*i;k++)
        {
            printf(" ");
        }

        for(j=0;j<i+1;j++)
        {

            printf("%6d",a[i][j]);
        }
        printf("\n");
    }


    return 0;
}
