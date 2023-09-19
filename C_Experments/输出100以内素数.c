#include<stdio.h>

int main()
{
    int n,m=0;
    int i,j,k=0;
    for(i=0;i<=100;i++)
    {
        m=1;
        for(j=2;j<i;j++)
        {
            if(i%j!=0)
            {
                m++;
            }

        }
        if(m==i-1)
        {
            k++;
            printf("%6d",i);

                if(k==5)
                {
                    printf("\n");
                    k=0;
                }
        }

    }
    return 0;
}
