#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct studentDate
{
    int num;
    char name[8];
    char sexsual[4];
    int date;
    int cmark;
    int hmark;
    int lmark;
    double ave;
    int line;
};

void input(struct studentDate a[]);
void average(struct studentDate a[]);
void sort(struct studentDate a[]);
void output(struct studentDate a[]);

int main()
{

    int c,d,e;
    struct studentDate a[10];
    input(a);
    average(a);
    sort(a);
    output(a);
    return 0;
}

void input(struct studentDate a[])
{
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i].num);
        getchar();
        scanf("%s",&a[i].name);
        getchar();
        scanf("%s",&a[i].sexsual);
        scanf("%d %d %d %d",&a[i].date,&a[i].cmark,&a[i].hmark,&a[i].lmark);

    }
}

void average(struct studentDate a[])
{
    for(int i=0;i<10;i++)
    {
        a[i].ave=(a[i].cmark+a[i].hmark+a[i].lmark)/3.0;
    }
}

void sort(struct studentDate a[])
{
    struct studentDate b;
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(a[j].ave>a[i].ave)
            {
                b=a[j];
                a[j]=a[i];
                a[i]=b;
            }
        }
    }
}

void output(struct studentDate a[])
{
    int c=0,d=0,e=0;
    for(int i=0;i<10;i++)
    {
        if(a[c].cmark<a[i].cmark)
        {
            c=i;
        }

        if(a[d].hmark<a[i].hmark)
        {
            d=i;
        }

        if(a[e].lmark<a[i].lmark)
        {
            e=i;
        }
    }
    printf("%d %s %s %d\n",a[c].num,a[c].name,a[c].sexsual,a[c].date);
    printf("%d %s %s %d\n",a[d].num,a[d].name,a[d].sexsual,a[d].date);
    printf("%d %s %s %d\n",a[e].num,a[e].name,a[e].sexsual,a[e].date);
}

