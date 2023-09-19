#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#define HEADER1 " -------------------------------订  票-------------------------------\n"
#define HEADER2 "|  number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n"
#define HEADER3 "|----------|----------|----------|-----------|-----------|-----|------------|\n"
#define FORMAT  "|%-10s|%-10s|%-10s|%-10s |%-10s |%5d|  %5d     |\n"
#define DATA p->data.num,p->data.startcity,p->data.reachcity,p->data.takeofftime,p->data.receivetime,p->data.price,p->data.ticketnum
int saveflag=0;

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

typedef struct node
{
    struct train data;
    struct node *next;
}Node,*Link;

typedef struct Man
{
    struct man data;
    struct Man *next;
}book,*bookLink;

void menu()
{

    return;
}

void printheader()
{
    printf(HEADER1);
    printf(HEADER2);
    printf(HEADER3);
}

void printdata(Node *q)
{
    Node *p;
    p=q;
    printf(FORMAT,DATA);
}

void Trianinfo(Link linkhead)
{
    struct node *p,*r,*s;
    char num[10];
    r=linkhead;
    s=linkhead->next;

    while(r->next!=NULL)
    {
        r=r->next;
    }

    while(1)
    {
        printf("请输入车次(输入0自动返回):");
        gets(num);
        if(strcmp(num,0)==0)
        {
            break;
        }

        while(s)
        {
            if(strcmp(s->data.num,num)==0)
            {
                printf("这个车次 '%s' 已经存在!\n",num);
                return ;
            }
            s=s->next;
        }

        p=(struct node*)malloc(sizeof(struct node));
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
        p->next=NULL;
        r->next=p;
        r=p;
        saveflag=1;
    }
}

void searchtrain(Link l)
{
    Node *s[10],*r;
    int sel,k,i=0;
    char str1[5],str2[10];

    if(!l->next)
    {
        printf("没有列车记录!");
        return ;
    }

    printf("选择查询方式\n1:通过车号查询;\n2:通过目标城市查询;");
    scanf("%d",&sel);
    if(sel==1)
    {
        printf("请输入你要搜索的车号:");
        gets(str1);
        r=l->next;

        while(r!=NULL)
        {
            if(strcmp(r->data.num,str1)==0)
            {
                s[i]=r;
                i++;
                break;
            }
            else
            {
                r=r->next;
            }
        }
    }
    else if(sel==2)
    {
        printf("请输入你的目标城市:");
        gets(str2);
        r=l->next;

        while(r!=NULL)
        {
            if(strcmp(r->data.reachcity,str2)==0)
            {
                s[i]=r;
                i++;
                break;
            }
            else
            {
                r=r->next;
            }
        }
    }

    if(i==0)
    {
        printf("找不到该车次信息!");
    }
    else
    {
        printheader();
        for(k=0;k<i;k++)
        {
            printdata(s[k]);
        }
    }
}

int main()
{
    FILE *fp1,*fp2;
    int sel;
    char ch1,ch2;
    Node *p,*r;
    Link l;
    book *t,*h;
    bookLink k;

    l=(Node*)malloc(sizeof(book));
    l->next=NULL;
    r=l;
    k=(book*)malloc(sizeof(book));
    k->next=NULL;
    h=k;

    if((fp1=fopen("train.txt","ab+"))==NULL)
    {
        printf("打开文件失败!\n");
        exit(1);
    }
    while(!feof(fp1))
    {
        p=(Node*)malloc(sizeof(Node));
        if(fread(p,sizeof(Node),1,fp1)==1)
        {
            p->next=NULL;
            r->next=p;
            r=p;
        }
    }
    fclose(fp1);

    if((fp2=fopen("train.txt","ab+"))==NULL)
    {
        printf("打开文件失败!\n");
        exit(1);
    }
    while(!feof(fp2))
    {
        t=(book*)malloc(sizeof(book));
        if(fread(t,sizeof(book),1,fp2)==1)
        {
            t->next=NULL;
            h->next=t;
            h=t;
        }
    }
    fclose(fp2);

    while(1)
    {
        system("CLS");
        menu();
        printf("\t请选择(0-6):  ");
        scanf("%d",&sel);
        system("CLS");
        if(sel==0)
        {
            if(saveflag==1)
            {
                getchar();
                printf("\n文件已经被改变！你是否想要保存(y/n)?\n");
                scanf("%c",&ch1);
                if(ch1=='y' || ch1=='Y')
                {
//                    SaveBookInfo(k);
//                    SaveTrainInfo(l);
                }

            }
        }
    }
    return 0;
}
