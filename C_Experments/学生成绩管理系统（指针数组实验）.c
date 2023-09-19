#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void input(int (*a)[4]);
void average(int (*a)[4],double*);
int find_1(int (*a)[4],int (*b)[5]);
int find_2(int (*a)[4],int d[5]);
void output(int (*b)[5],int);

int main()
{

    int a[5][4],b[5][5],d[5];
    int c;
    double p;
    input(a);
    average(a,&p);
    printf("%lf",p);
    c=find_1(a,b);
    output(b,c);
    c=find_2(a,d);

    for(int i=0;i<c;i++)
    {
        printf("%d\n",d[i]);
    }

    return 0;
}

void input(int (*a)[4])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",*(a+i)+j);
        }
    }
}

void average(int (*a)[4],double *p)
{
    int i=0;
    while(i<5)
    {
        *p+=*(*(a+i)+1);
        i++;
    }
    *p/=5;
}

int find_1(int (*a)[4],int (*b)[5])
{
    int ave=0,count=0,h=0,l=0,k=0;
    for(int i=0;i<5;i++)
    {
        count=0;
        for(int j=1;j<4;j++)
        {
            if(*(*(a+i)+j)<60)
            {
                count++;
                if(count==2)
                {
                    k++;
                    for(l=0;l<4;l++)
                    {
                        *(*(b+h)+l)=*(*(a+i)+l);
                    }
                    for(l=1;l<4;l++)
                    {
                        ave+=*(*(a+i)+l);
                    }
                    ave/=3;
                    *(*(b+h)+l)=ave;
                    h++;
                }
            }
        }
    }
    return k;
}
int find_2(int (*a)[4],int d[5])
{
    int ave,count,c=0;
    for(int i=0;i<5;i++)
    {
        count=0;
        for(int j=1;j<4;j++)
        {
            ave+=*(*(a+i)+j);
            if(*(*(a+i)+j)>=90)
            {
                count++;
            }
        }
        ave/=3;
        if(ave>=90||count==3)
        {
            *(d+i)=*(*(a+i)+0);
            c++;
        }
    }
    return c;
}


void output(int (*b)[5],int c)
{
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%d", *(*(b+i)+j));
            if(j<4)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

