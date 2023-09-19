#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    long studentID;
    char studentName[10];
    int score[3];
}STUDENT;
void input(STUDENT stu[])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        scanf("%ld",&stu[i].studentID);
        scanf("%s",stu[i].studentName);
        for(j=0;j<3;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }
    }
}
void average(STUDENT stu[],float ave[])
{
    int i,j,sum;
    for(i=0;i<5;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=stu[i].score[j];
        }
        ave[i]=(float)sum/3;
    }
}
void writetofile(STUDENT stu[],float ave[])
{
    FILE *fp;
    if((fp=fopen("STUD.txt","w"))==NULL)
    {
        printf("Failure to open STUD.txt\n");
        exit(0);
    }
    for(int i=0;i<5;i++)
    {
        fprintf(fp,"%ld ",stu[i].studentID);
        fprintf(fp,"%s ",stu[i].studentName);
        for(int j=0;j<3;j++)
        {
            fprintf(fp,"%d ",stu[i].score[j]);
        }
        fprintf(fp,"%.2f\n",ave[i]);
    }
    fclose(fp);
}
void readfromfile(STUDENT stu[],float ave[])
{
    FILE *fp;
    if((fp=fopen("STUD.txt","r"))==NULL)
    {
        printf("Failure to open STUD.txt\n");
        exit(0);
    }
        for(int i=0;i<5;i++)
        {
                fscanf(fp,"%ld ",&stu[i].studentID);
                fscanf(fp,"%s ",stu[i].studentName);
                for(int j=0;j<3;j++)
                {
                    fscanf(fp,"%d ",&stu[i].score[j]);
                }
                fscanf(fp,"%f ",&ave[i]);
        }
}
void output(STUDENT stu[],float ave[])
{
    long ID;
    int k,i,j;
     while(scanf("%ld",&ID)!=EOF)
    {
        for(i=0;i<5;i++)
        {
            if(ID==stu[i].studentID)
            {
                k=i;
            }
        }
        if(k<5)
        {
            printf("%ld ",stu[k].studentID);
            printf("%s ",stu[k].studentName);
            for(j=0;j<3;j++)
            {
                printf("%d ",stu[k].score[j]);
            }
            printf("平均分为：%.2f\n",ave[k]);
        }
    }
}
int main()
{
    STUDENT stu[5];
    float ave[5];
    input(stu);
    average(stu,ave);
    writetofile(stu,ave);
    readfromfile(stu,ave);
    output(stu,ave);
    return 0;
}
/*
20225001 小张 90 90 90
20225002 小强 80 80 80
20225003 小王 80 80 80
20225004 小潘 70 70 70
20225005 小秦 80 80 80
*/
