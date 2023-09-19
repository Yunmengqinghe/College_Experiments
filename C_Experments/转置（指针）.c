#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void exchange(int (*a)[3],int (*b)[3]);

int main()
{
    int a[3][3],b[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",*(a+i)+j);
        }
    }
    exchange(a,b);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d",*(*(b+i)+j));
            if(j<2)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void exchange(int (*a)[3],int (*b)[3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            *(*(b+j)+i)=*(*(a+i)+j);
        }
    }
}
