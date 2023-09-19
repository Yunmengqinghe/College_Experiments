#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct train
{
    char num[10];
    char startcity[10];
    char reachcity[10];
    char takeofftime[10];
    char receivetime[10];
    int price;
    int ticketnum;
};

struct man
{
    char num[10];
    char name[10];
    int bookNum;
};

typedef struct massage
{
    struct train data;
    struct massage *next;
}Link;

typedef struct Man
{
    struct man data;
    struct Man *next;
}bookLink;

void traininto(Link **phead);
void savetrain(Link **phead);
void searchtrain(Link **phead);

int main()
{
    FILE *fp1,*fp2;
    Link *head1=NULL,*p=NULL,*pr=NULL;

    traininto(&head1);
    savetrain(&head1);
    searchtrain(&head1);
//    for(pr=head1;pr;pr=pr->next)
//    {
//        printf("%s\n",pr->data.num);
//        printf("%s\n",pr->data.startcity);
//        printf("%s\n",pr->data.reachcity);
//        printf("%s\n",pr->data.takeofftime);
//        printf("%s\n",pr->data.receivetime);
//        printf("%d\n",pr->data.price);
//        printf("%d\n",pr->data.ticketnum);
//    }
//    if((fp1=fopen("train.txt","ab+"))==NULL)
//    {
//        printf("打开文件失败!\n");
//        exit(1);
//    }
//    while(!feof(fp1))
//    {
//        p=(Link*)malloc(sizeof(Link));
//
//        fscanf(fp1,"%s ",p->data.num);
//        fscanf(fp1,"%s ",p->data.startcity);
//        fscanf(fp1,"%s ",p->data.reachcity);
//        fscanf(fp1,"%s ",p->data.takeofftime);
//        fscanf(fp1,"%s ",p->data.receivetime);
//        fscanf(fp1,"%d ",&p->data.price);
//        fscanf(fp1,"%d ",&p->data.ticketnum);
//    }

    return 0;
}

void traininto(Link **phead)
{
    Link *p=NULL,*q=NULL,*pr=NULL;
    char num[10];

    while(1)
    {
        printf("请输入车次(输入0自动返回):");
        scanf("%s",num);
        if(strcmp(num,"0")==0)
        {
            break;
        }

        else
        {
            q=*phead;
            while(q)
            {
                if(strcmp(q->data.num,num)==0)
                {
                    printf("这辆列车 '%s' 的信息已经存在!\n",num);
                    return ;
                }
                q=q->next;
            }
        }

        p=(Link*)malloc(sizeof(Link));
        p->next=NULL;
        strcpy(p->data.num,num);//输入列车的车号

        printf("请输入列车的出发城市:");
        scanf("%s",p->data.startcity);

        printf("请输入列车的目标城市:");
        scanf("%s",p->data.reachcity);

        printf("请输入列车的出发时间:");
        scanf("%s",p->data.takeofftime);

        printf("请输入列车的到达时间:");
        scanf("%s",p->data.receivetime);

        printf("请输入票价:");
        scanf("%d",&p->data.price);

        printf("请输入总票数:");
        scanf("%d",&p->data.ticketnum);
        printf("\n");

        if(*phead==NULL)
        {
            *phead=p;
        }
        else
        {
            pr=*phead;
            while(pr->next!=NULL)
            {
                pr=pr->next;
            }
            pr->next=p;
        }
    }
}

void savetrain(Link **phead)
{
    Link *pr=*phead;

    FILE *fp;
    if((fp=fopen("train.txt","ab+"))==NULL)
    {
        printf("打开文件失败!\n");
        exit(1);
    }

    while(pr!=NULL)
    {
        fprintf(fp,"%s ",pr->data.num);
        fprintf(fp,"%s ",pr->data.startcity);
        fprintf(fp,"%s ",pr->data.reachcity);
        fprintf(fp,"%s ",pr->data.takeofftime);
        fprintf(fp,"%s ",pr->data.receivetime);
        fprintf(fp,"%d ",pr->data.price);
        fprintf(fp,"%d ",pr->data.ticketnum);
        pr=pr->next;
    }
    fclose(fp);
}

void searchtrain(Link **phead)
{
    char n,b[10],c[10];
    Link *p=*phead,*pr=NULL;
    if(*phead!=NULL)
    {
        printf("列车信息不存在！\n");
        return ;
    }

    printf("请选择搜索方式:\n1.按照车次搜索\n2.按照目的地搜索\n");
    n=getchar();
    switch(n)
    {
        case '1':
            printf("请输入车次:\n");
            gets(b);
            for(;p;p=p->next)
            {
                if(strcmp(b,p->data.num)==0)
                {

                }
            }

    }

}
