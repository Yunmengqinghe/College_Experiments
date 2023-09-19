#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void input(char a[]);
void output(int n);

int main()
{
    int n;
    char a[100];
    input(a);

    n=strlen(a);

    output(n);
    return 0;
}

void input(char a[])
{
    char b;
    int i=0;
    FILE *fp;
    if((fp=fopen("char.txt","w"))==NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }

    while(1)
    {
        b=getchar();
        if(b!='$')
        {
            a[i]=b;
            fprintf(fp,"%c",a[i]);
            i++;
        }
        else
        {
            fclose(fp);
            break;
        }
    }
}

void output(int n)
{
    char a[n];
    FILE *fp;
    if((fp=fopen("char.txt","r"))==NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%c",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%c",a[i]-32);
    }
    fclose(fp);
}




