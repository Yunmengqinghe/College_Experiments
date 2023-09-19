#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    int num;
    char name[5];
    int scores[3];
    double marks;
}stu;

void input(struct student a[]);
void WritetoFile(struct student a[]);
void ReadtoFile();

int main()
{
    stu a[5];
    input(a);
    WritetoFile(a);
    ReadtoFile();
    return 0;
}

void input(stu a[])
{
    float mark;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i].num);
        scanf("%s",a[i].name);
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i].scores[j]);
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            mark+=a[i].scores[j];
        }
        a[i].marks=mark/3.0;
        mark=0;
    }
}

void WritetoFile(struct student a[])
{
    FILE *fp;
    if((fp=fopen("STUD.txt","w"))==NULL)
    {
        printf("打开文件失败");
        exit(0);
    }
    for(int i=0;i<5;i++)
    {
        fprintf(fp,"%d ",a[i].num);
        fprintf(fp,"%s ",a[i].name);
        for(int j=0;j<3;j++)
        {
            fprintf(fp,"%d ",a[i].scores[j]);
        }
        fprintf(fp,"%.2lf ",a[i].marks);
    }
    fclose(fp);
}

void ReadtoFile()
{
    FILE *fp;
    int number;
    stu a[5];
    scanf("%d",&number);
    getchar();
    if((fp=fopen("STUD.txt","r"))==NULL)
    {
        printf("打开文件失败");
        exit(0);
    }

    for(int i=0;i<5;i++)
    {
        fscanf(fp,"%d ",&a[i].num);
        fscanf(fp,"%s ",a[i].name);
        for(int j=0;j<3;j++)
        {
            fscanf(fp,"%d ",&a[i].scores[j]);
        }
        fscanf(fp,"%lf ",&a[i].marks);
    }

    for(int i=0;i<5;i++)
    {
        if(a[i].num==number)
        {
            printf("%d ",a[i].num);
            printf("%s ",a[i].name);
            for(int j=0;j<3;j++)
            {
                printf("%d ",a[i].scores[j]);
            }
            printf("%.2lf ",a[i].marks);
            printf("\n");
        }
    }
    fclose(fp);
}

/*
20226666 小张 90 90 90
20226667 小强 80 80 80
20226668 小王 80 80 80
20226669 小潘 70 70 70
20227000 小秦 80 80 80
*/


