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
//        printf("���ļ�ʧ��!\n");
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
        printf("�����복��(����0�Զ�����):");
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
                    printf("�����г� '%s' ����Ϣ�Ѿ�����!\n",num);
                    return ;
                }
                q=q->next;
            }
        }

        p=(Link*)malloc(sizeof(Link));
        p->next=NULL;
        strcpy(p->data.num,num);//�����г��ĳ���

        printf("�������г��ĳ�������:");
        scanf("%s",p->data.startcity);

        printf("�������г���Ŀ�����:");
        scanf("%s",p->data.reachcity);

        printf("�������г��ĳ���ʱ��:");
        scanf("%s",p->data.takeofftime);

        printf("�������г��ĵ���ʱ��:");
        scanf("%s",p->data.receivetime);

        printf("������Ʊ��:");
        scanf("%d",&p->data.price);

        printf("��������Ʊ��:");
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
        printf("���ļ�ʧ��!\n");
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
        printf("�г���Ϣ�����ڣ�\n");
        return ;
    }

    printf("��ѡ��������ʽ:\n1.���ճ�������\n2.����Ŀ�ĵ�����\n");
    n=getchar();
    switch(n)
    {
        case '1':
            printf("�����복��:\n");
            gets(b);
            for(;p;p=p->next)
            {
                if(strcmp(b,p->data.num)==0)
                {

                }
            }

    }

}
