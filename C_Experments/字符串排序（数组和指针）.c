#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input(char *p[]);
void swap(char *p[]);
void output(char *p[]);

int main()
{
    char a[10][10];
    char *p[10];
    for(int i=0;i<10;i++)
    {
        p[i]=a[i];
        gets(p[i]);
    }

    swap(p);

    for(int i=0;i<10;i++)
    {
        puts(p[i]);
    }
    return 0;
}

void swap(char *p[10])
{
    char *temp=NULL;
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(strcmp(p[j],p[i])<0)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

