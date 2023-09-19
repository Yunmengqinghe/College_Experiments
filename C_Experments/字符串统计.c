#include<stdio.h>
#include<string.h>

int main(void)
{
    int n,m,i;
    int d,length;
    char a[100];
    m=0;

    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        for(i=0;i<n;i++)
        {
            gets(a);
            length=strlen(a);
            for(d=0;d<length;d++)
            {
                if(a[d]>='0'&&a[d]<='9')
                {
                    m++;
                }
            }
        printf("%d\n",m);
         m=0;
        }



    }

    return 0;
}
