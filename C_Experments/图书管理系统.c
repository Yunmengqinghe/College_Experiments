#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct borrowState
{
    char name[12];
    char unit[20];
    char phoneNumber[15];
    int canBorrow;
    int alBorrow;
};

typedef struct person
{
    int type;
    int userNumber;
    char lock[10];
    struct borrowState borrow;
    struct person *next;
}person;

struct Point1
{
    int point1;
    int point2;
    int point3;
};

typedef struct Books
{
    int number;
    char name[20];
    char writer[20];
    char publish[20];
    int haveNumber;
    int alNumber;
    struct Point1 point;
}books;

struct Point2
{
    int point;
    int length;
};

typedef struct NameIndex
{
    char name[20];
    struct Point2 pointer;
}nameindex;

typedef struct WriterIndex
{
    char name[20];
    struct Point2 pointer;
}writerindex;

typedef struct PubIndex
{
    char name[20];
    struct Point2 pointer;
}pubindex;

struct Date
{
    int year;
    int month;
    int day;
};

typedef struct Lent
{
    int userNumber;
    int bookNumber;
    struct Date leDay;
    struct Date reDay;
    struct Lent *next;
}lent;

int logIn(person **head);

void uiShow1();
void uiShow2();
void uiShow3();
void uiShow4();
void uiShow5();
void uiShow6();

int userManager(person **head);
int readerManager(person **head);
int bookManager(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen);
int lentManager(person **headA,lent **headB,books main[],int len);
int findBooks(books main[],int sel,int n);
void sortBooks(books main[],nameindex name[],writerindex writer[],pubindex pub[],int len);

void outputInformation(books main[],int i);
void outputState(lent *headB);

void writeTofile(person **head);
void readFromfile(person **head);
void writeTofile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int len,int nlen,int wlen,int plen);
void readFromfile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen);
void writeTofile2(lent **head);
void readFromfile2(lent **head);
void release(person **head);

int main()
{
    int sel=0,flag=0,pend=0,n=10;
    int len=-1,nlen=-1,wlen=-1,plen=-1;
    person *headA=NULL;
    lent *headB=NULL;
    books main[n];
    nameindex name[n];
    writerindex writer[n];
    pubindex pub[n];
    readFromfile1(main,name,writer,pub,&len,&nlen,&wlen,&plen);
    readFromfile2(&headB);

    do
    {
        release(&headA);
        readFromfile(&headA);
        flag=logIn(&headA);
    }while(flag==0);

    release(&headA);
    readFromfile(&headA);

    while(1)
    {
        pend=0;
        uiShow1();//��ʾѡ���UI

        scanf("%d", &sel);
        printf("\n");

        switch (sel)
        {
            case 1:
                while(1)
                {
                    pend=userManager(&headA);
                    if(pend==1)
                        break;
                }
                break;//�û�����
            case 2:
                while(1)
                {
                    pend=readerManager(&headA);
                    if(pend==1)
                        break;
                }
                break;
            case 3:
                readFromfile1(main,name,writer,pub,&len,&nlen,&wlen,&plen);
                while(1)
                {
                    pend=bookManager(main,name,writer,pub,&len,&nlen,&wlen,&plen);
                    if(pend==1)
                        break;
                }
                break;
            case 4:
                while(1)
                {
                    pend=lentManager(&headA,&headB,main,len);
                    if(pend==1)
                        break;
                }
                break;
            case 5:
                writeTofile(&headA);
                writeTofile1(main,name,writer,pub,len,nlen,wlen,plen);
                writeTofile2(&headB);
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}

void uiShow1()
{
    printf("******************\n  1.�û�����\n  2.���߹���\n  3.ͼ�����\n  4.ͼ����ͨ����\n  5.�˳�ϵͳ\n******************\n��Ҫѡ��Ĺ���:");
}

void uiShow2()
{
    printf("******************\n  1.�û���Ϣ����\n  2.�û���Ϣ�޸�\n  3.�û���Ϣɾ��\n  4.�û���Ϣ��ʾ\n  5.�û������޸�\n  6.�������˵�\n******************\n��Ҫѡ��Ĺ���:");
}

void uiShow3()
{
    printf("******************\n  1.������Ϣ����\n  2.������Ϣ�޸�\n  3.������Ϣɾ��\n  4.������Ϣ��ѯ\n  5.������Ϣ��ʾ\n  6.�������˵�\n******************\n��Ҫѡ��Ĺ���:");
}

void uiShow4()
{
    printf("******************\n  1.ͼ����Ϣ����\n  2.ͼ����Ϣ�޸�\n  3.ͼ����Ϣ��ѯ\n  4.����ͳ��\n  5.�������˵�\n******************\n��Ҫѡ��Ĺ���:");
}

void uiShow5()
{
    printf("******************\n  1.����Ų�ѯ\n  2.��������ѯ\n  3.�����߲�ѯ\n  4.���������ѯ\n  5.�������˵�\n 6.��������ѯ\n******************\n��Ҫѡ��Ĺ���:");
}

void uiShow6()
{
    printf("******************\n  1.���鴦��\n  2.���鴦��\n  3.��ʾģ��\n  4.�������˵�\n******************\n��Ҫѡ��Ĺ���:");
}

int logIn(person **head)
{
    if(*head==NULL)
    {
        FILE *fp;
        if((fp=fopen("library.txt","w"))==NULL)
        {
            printf("�ļ���ʧ��!");
            exit(0);
        }

        person *p=(person*)malloc(sizeof(person));
        p->next=NULL;
        printf("********ע��********\n");
        printf("�������û�����:");
        scanf("%d",&p->type);
        printf("�������û���:");
        scanf("%d",&p->userNumber);
        printf("����������:");
        scanf("%s",p->lock);
        printf("\n");

        p->borrow.alBorrow=0;
        fprintf(fp,"%d %d %s %s %s %s %d ",p->type,p->userNumber,p->lock,p->borrow.name,
                p->borrow.unit,p->borrow.phoneNumber,p->borrow.alBorrow);
        fclose(fp);
    }
    else
    {
        char lockTemp[10];
        int nameTemp,count;
        printf("********��¼********\n");

        printf("�����û���:");
        scanf("%d",&nameTemp);

        for(person *pr=*head;pr;pr=pr->next)
        {
            count=0;
            if(pr->userNumber==nameTemp)
            {
                count=3;
            }
            while(count>0)
            {
                printf("��������:");
                scanf("%s",lockTemp);
                if(strcmp(pr->lock,lockTemp)==0)
                {
                    printf("��¼�ɹ�\n\n");
                    return pr->type;
                }
                else
                {
                    count--;
                    printf("�������!ʣ�����%d\n\n",count);
                    if(count==0)
                    {
                        printf("��¼ʧ��!\n\n");
                        return 0;
                    }
                }
            }
            if(pr->next==NULL)
            {
                printf("�û���������!\n\n");
            }
        }
    }
}

int userManager(struct person **head)
{
    uiShow2();
    int sel=0,pend=0,numberTemp=0;
    person *pr=NULL,*pt=NULL;
    person *p=(person*)malloc(sizeof(person));
    p->next=NULL;

    if(p==NULL)
    {
        printf("��������ʧ��\n");
        exit(0);
    }

    scanf("%d",&sel);
    printf("\n");

    switch (sel)
    {
        case 1:
            printf("�������û���:");
            scanf("%d", &numberTemp);

            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("���û��Ѵ���,�޷����룡\n");
                    break;
                }
                else
                {
                    p->userNumber=numberTemp;
                    printf("�������û�����:");
                    scanf("%d", &p->type);
                    printf("�������û�����:");
                    scanf("%s",p->lock);
                    p->borrow.alBorrow=0;

                    if(*head==NULL)
                    {
                        *head=p;
                    }
                    else
                    {
                        pr=*head;
                        while(pr->next)
                        {
                            pr=pr->next;
                        }
                        pr->next=p;
                    }

                    printf("����ɹ�!\n\n");
                    break;
                }
            }
            break;

        case 2:
            printf("������Ҫ�޸���Ϣ��ԭ�û���:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("******************\n");
                    printf(" 1.�û����޸�\n");
                    printf(" 2.�����޸�\n");
                    printf(" 3.�û������޸�\n");
                    printf("******************\n");
                    printf("��Ҫѡ��Ĺ���:");
                    scanf("%d",&sel);
                    printf("\n");

                    switch(sel)
                    {
                        case 1:
                            printf("�������û���:");
                            scanf("%d",&pr->userNumber);
                            printf("\n");
                            break;
                        case 2:
                            printf("����������:");
                            scanf("%s",pr->lock);
                            printf("\n");
                            break;
                        case 3:
                            printf("�������û�����:");
                            scanf("%d",&pr->type);
                            printf("\n");
                            break;
                    }
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("���û�������!\n\n");
                    break;
                }
            }
            break;

        case 3:
            printf("������Ҫɾ������Ϣ���û���:");
            scanf("%d",&numberTemp);
            for(pr=*head,pt=pr;pr;pt=pr,pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    if(pr->borrow.alBorrow==0)
                    {
                        if(pr==*head)
                        {
                            *head=pr->next;
                        }
                        else
                        {
                            pt->next=pr->next;
                        }
                        free(pr);
                        printf("ɾ���ɹ�!\n\n");
                        break;
                    }
                    else
                    {
                        printf("����δ����ɾ��ʧ��!\n");
                        break;
                    }
                }
                if(pr->next==NULL)
                {
                    printf("���û�������!\n\n");
                    break;
                }
            }
            break;

        case 4:
            printf("--------------------------------------------------\n");
            printf(" �û���(���ߺ�)      �û�����      �û�����\n");
            printf("--------------------------------------------------\n");
            for(pr=*head;pr;pr=pr->next)
            {
                printf(" %-20d%-14s%d",pr->userNumber,pr->lock,pr->type);
                switch(pr->type)
                {
                case 1:
                    printf("(�û�����Ա)\n");
                    break;
                case 2:
                    printf("(ͼ�����Ա)\n");
                    break;
                case 3:
                    printf("(��ͨ����)\n");
                    break;
                default:
                    break;
                }
            }
            printf("--------------------------------------------------\n\n");
            break;

        case 5:
            printf("�������û���:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("������Ҫ�޸ĵ�����:");
                    scanf("%s",pr->lock);
                    printf("\n");
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("���û�������!\n\n");
                    break;
                }
            }
            break;

        case 6:
            return 1;
            break;

        default:
            break;
    }
}

int readerManager(person **head)
{
    uiShow3();

    int sel=0,pend=0,numberTemp=0;
    char nameTemp[12];
    person *pr=NULL,*pt=NULL;

    for(pr=*head;pr;pr=pr->next)
    {
        if(pr->userNumber>=10000000)
        {
            pr->borrow.canBorrow=5;
        }
        else
        {
            pr->borrow.canBorrow=10;
        }
    }

    person *p=(person*)malloc(sizeof(person));
    p->next=NULL;
    if(p==NULL)
    {
        printf("��������ʧ��\n");
        exit(0);
    }

    scanf("%d",&sel);
    printf("\n");

    switch(sel)
    {
        case 1:
            printf("�������û���:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    free(p);
                    printf("�����������:");
                    scanf("%s",pr->borrow.name);
                    printf("��������ߵ�λ:");
                    scanf("%s",pr->borrow.unit);
                    printf("�����������ϵ�绰:");
                    scanf("%s",pr->borrow.phoneNumber);
                    printf("�������ѽ�����:");
                    scanf("%d",&pr->borrow.alBorrow);

                    printf("����ɹ�!\n\n");
                    break;
                }

                if(pr->next==NULL)
                {
                    p->userNumber=numberTemp;

                    printf("�������û�����:");
                    scanf("%d", &p->type);
                    printf("�������û�����:");
                    scanf("%s",p->lock);
                    printf("�����������:");
                    scanf("%s",p->borrow.name);
                    printf("��������ߵ�λ:");
                    scanf("%s",p->borrow.unit);
                    printf("�����������ϵ�绰:");
                    scanf("%s",p->borrow.phoneNumber);
                    printf("�������ѽ�����:");
                    scanf("%d",&p->borrow.alBorrow);

                    printf("����ɹ�!\n\n");

                    if(*head==NULL)
                    {
                        *head=p;
                    }
                    else
                    {
                        pr=*head;
                        while(pr->next)
                        {
                            pr=pr->next;
                        }
                        pr->next=p;
                    }
                    break;
                }
            }
            break;

        case 2:
            printf("������Ҫ�޸���Ϣ��ԭ���ߺ�:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("******************\n");
                    printf(" 1.���ߺ��޸�\n");
                    printf(" 2.�������޸�\n");
                    printf(" 3.��λ�޸�\n");
                    printf(" 4.��ϵ��ʽ�޸�\n");
                    printf(" 5.�ѽ������޸�\n");
                    printf("******************\n");
                    printf("��Ҫѡ��Ĺ���:");
                    scanf("%d",&sel);
                    printf("\n");

                    switch(sel)
                    {
                        case 1:
                            printf("��������ߺ�:");
                            scanf("%d",&pr->userNumber);
                            printf("\n");
                            break;
                        case 2:
                            printf("�����������:");
                            scanf("%s",pr->borrow.name);
                            printf("\n");
                            break;
                        case 3:
                            printf("�����뵥λ:");
                            scanf("%s",pr->borrow.unit);
                            printf("\n");
                            break;
                        case 4:
                            printf("��������ϵ��ʽ:");
                            scanf("%s",pr->borrow.phoneNumber);
                            printf("\n");
                            break;
                        case 5:
                            printf("�������ѽ�����:");
                            scanf("%d",&pr->borrow.alBorrow);
                            printf("\n");
                            break;
                    }
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("���û�������!\n\n");
                    break;
                }
            }
            break;

        case 3:
            printf("������Ҫɾ������Ϣ���û���:");
            scanf("%d",&numberTemp);
            for(pr=*head,pt=pr;pr;pt=pr,pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    if(pr->borrow.alBorrow==0)
                    {
                        if(pr==*head)
                        {
                            *head=pr->next;
                        }
                        else
                        {
                            pt->next=pr->next;
                        }

                        free(pr);
                        printf("ɾ���ɹ�!\n\n");
                        break;
                    }
                    else
                    {
                        printf("����δ����ɾ��ʧ��!\n");
                        break;
                    }
                }
                if(pr->next==NULL)
                {
                    printf("���û�������!\n\n");
                    break;
                }
            }
            break;

        case 4:
            printf("������Ҫ��ѯ���û�����:");
            scanf("%s",nameTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(strcmp(nameTemp,pr->borrow.name)==0)
                {
                    printf("--------------------------------------------------------------------------------\n");
                    printf(" ���ߺ�      ������      ��λ          ��ϵ��ʽ        �ɽ�����      �ѽ�����\n");
                    printf("--------------------------------------------------------------------------------\n");
                    printf(" %-12d%-12s%-14s%-16s%-14d%-11d\n",pr->userNumber,pr->borrow.name,pr->borrow.unit,
                           pr->borrow.phoneNumber,pr->borrow.canBorrow,pr->borrow.alBorrow);
                    printf("--------------------------------------------------------------------------------\n");
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("���û�������!\n\n");
                    break;
                }
            }
            break;

        case 5:
            printf("--------------------------------------------------------------------------------\n");
            printf(" ���ߺ�      ������      ��λ          ��ϵ��ʽ        �ɽ�����      �ѽ�����\n");
            printf("--------------------------------------------------------------------------------\n");
            for(pr=*head;pr;pr=pr->next)
            {
                printf(" %-12d%-12s%-14s%-16s%-14d%-11d\n",pr->userNumber,pr->borrow.name,pr->borrow.unit,
                       pr->borrow.phoneNumber,pr->borrow.canBorrow,pr->borrow.alBorrow);
            }
            printf("--------------------------------------------------------------------------------\n\n");
            break;

        case 6:
            return 1;
            break;

        default:
            break;
    }
}

int bookManager(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen)
{
    uiShow4();
    int sel=0,pend=0,temp=0,r=0,n=10;

    scanf("%d",&sel);
    printf("\n");

    switch(sel)
    {
        case 1:
            (*len)++;
            printf("���������:");
            scanf("%d",&main[*len].number);
            printf("����������:");
            scanf("%s",main[*len].name);
            printf("������������:");
            scanf("%s",main[*len].writer);
            printf("�����������:");
            scanf("%s",main[*len].publish);
            printf("�����������:");
            scanf("%d",&main[*len].haveNumber);
            while(1)
            {
                printf("����������:");
                scanf("%d",&main[*len].alNumber);

                if(main[*len].haveNumber<main[*len].alNumber)
                {
                    printf("������С�ڽ���������ٴ�����!\n");
                }
                else
                {
                    break;
                }
            }
            printf("\n");

            main[*len].point.point1=0;
            main[*len].point.point2=0;
            main[*len].point.point3=0;
            break;
        case 2:
            printf("������Ҫ�޸ĵ����:");
            scanf("%d",&temp);
            if(*len==-1)
            {
                printf("��Ų�����!\n\n");
            }
            for(int i=0;i<=*len;i++)
            {
                if(main[i].number==temp)
                {
                    printf("1.�޸Ĳ�����\n2.�޸Ľ����\n\n");
                    printf("��ѡ��Ҫʵ�ֵĹ���:");
                    scanf("%d",&sel);
                    switch(sel)
                    {
                        case 1:
                            printf("���������:");
                            scanf("%d",&main[i].haveNumber);
                            break;
                        case 2:
                            printf("��������:");
                            scanf("%d",&main[i].alNumber);
                            break;
                        default:
                            break;
                    }
                    printf("�޸ĳɹ�\n\n");
                    break;
                }
                if(i==*len)
                {
                    printf("��Ų�����!\n\n");
                }
            }
            break;
        case 3:
            while(1)
            {
                uiShow5();
                scanf("%d",&sel);
                printf("\n");
                pend=findBooks(main,sel,*len);
                if(pend==1)
                {
                    break;
                }
            }
            break;
        case 4:
            for(int i=0;i<=*len-1;i++)
            {
                for(int j=0;j<=*len-1-i;j++)
                {
                    books tmp;
                    if(main[j].number>main[j+1].number)
                    {
                        tmp=main[j];
                        main[j]=main[j+1];
                        main[j+1]=tmp;
                    }
                }
            }

            for(int i=0;i<=*len;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(strcmp(main[i].name,main[j].name)==0)
                    {
                        main[i].point.point1=j+1;
                    }

                    if(strcmp(main[i].writer,main[j].writer)==0)
                    {
                        main[i].point.point2=j+1;
                    }

                    if(strcmp(main[i].publish,main[j].publish)==0)
                    {
                        main[i].point.point3=j+1;
                    }
                }
            }
            printf("---------------------------------------------------------------------------------------------\n");
            printf(" ��¼��    ���    ����        ����    ������    ������    �����    ָ��1    ָ��2    ָ��3\n");
            for(int i=0;i<=*len;i++)
            {
                printf(" %-10d%-8d%-12s%-8s%-10s%-10d%-10d%-9d%-9d%-8d\n",i+1,main[i].number,main[i].name,main[i].writer,
                   main[i].publish,main[i].haveNumber,main[i].alNumber,main[i].point.point1,main[i].point.point2,
                   main[i].point.point3);
            }
            printf("---------------------------------------------------------------------------------------------\n\n");


            for(int i=0;i<=*len;i++)
            {
                int pend=1,p=0,l=0;
                for(int j=0;j<=*nlen;j++)
                {
                    if(strcmp(main[i].name,name[j].name)==0)
                    {
                        pend=0;
                    }
                }
                if(pend==1)
                {
                    p=i+1;
                    for(int j=i+1;j<=*len;j++)
                    {
                        if(strcmp(main[i].name,main[j].name)==0)
                        {
                            p=j+1;
                            l++;
                        }
                    }
                    (*nlen)++;
                    strcpy(name[*nlen].name,main[i].name);
                    name[*nlen].pointer.point=p;
                    name[*nlen].pointer.length=l;
                }
            }

            printf("------------------------------\n");
            printf("   ����    ��ͷָ��    ����\n");
            printf("------------------------------\n");
            for(int i=0;i<=*nlen;i++)
            {
                printf(" %-10s%-12d%-7d\n",name[i].name,name[i].pointer.point,name[i].pointer.length);
            }
            printf("------------------------------\n\n");

            for(int i=0;i<=*len;i++)
            {
                int pend=1,p=0,l=0;
                for(int j=0;j<=*wlen;j++)
                {
                    if(strcmp(main[i].writer,writer[j].name)==0)
                    {
                        pend=0;
                    }
                }
                if(pend==1)
                {
                    p=i+1;
                    for(int j=i+1;j<=*len;j++)
                    {
                        if(strcmp(main[i].writer,main[j].writer)==0)
                        {
                            p=j+1;
                            l++;
                        }
                    }
                    (*wlen)++;
                    strcpy(writer[*wlen].name,main[i].writer);
                    writer[*wlen].pointer.point=p;
                    writer[*wlen].pointer.length=l;
                }
            }

            printf("------------------------------\n");
            printf("  ������    ��ͷָ��    ����\n");
            printf("------------------------------\n");
            for(int i=0;i<=*wlen;i++)
            {
                printf(" %-10s%-12d%-6d\n",writer[i].name,writer[i].pointer.point,writer[i].pointer.length);
            }
            printf("------------------------------\n\n");

            for(int i=0;i<=*len;i++)
            {
                int pend=1,p=0,l=0;
                for(int j=0;j<=*plen;j++)
                {
                    if(strcmp(main[i].publish,pub[j].name)==0)
                    {
                        pend=0;
                    }
                }
                if(pend==1)
                {
                    p=i+1;
                    for(int j=i+1;j<=*len;j++)
                    {
                        if(strcmp(main[i].publish,main[j].publish)==0)
                        {
                            p=j+1;
                            l++;
                        }
                    }
                    (*plen)++;
                    strcpy(pub[*plen].name,main[i].publish);
                    pub[*plen].pointer.point=p;
                    pub[*plen].pointer.length=l;
                }
            }

            printf("------------------------------\n");
            printf("  ������    ��ͷָ��    ����\n");
            printf("------------------------------\n");
            for(int i=0;i<=*plen;i++)
            {
                printf(" %-10s%-12d%-6d\n",pub[i].name,pub[i].pointer.point,pub[i].pointer.length);
            }
            printf("------------------------------\n\n");
            break;
        case 5:
            return 1;
            break;
    }
    return 0;
}

int findBooks(books main[],int sel,int len)
{
    int temp,r;
    int left=0,right=len-1;
    char bookTemp[20],writerTemp[20],pubTemp[20];
    switch(sel)
    {
        case 1:
            printf("���������:");
            scanf("%d",&temp);
            while (left<=right)
            {
                int mid=left+(right-left)/2;
                if (main[mid].number<temp)
                {
                    left=mid+1;
                }
                else if (main[mid].number>temp)
                {
                    right=mid-1;
                }
                else
                {
                    r=mid;
                    break;
                }
            }
            if(left>right)
            {
                printf("��Ų�����!\n");
            }
            outputInformation(main,r);
            break;
        case 2:
            printf("����������:");
            scanf("%s",bookTemp);
            for(int i=0;i<=len;i++)
            {
                if(strcmp(bookTemp,main[i].name)==0)
                {
                    outputInformation(main,i);
                }
            }
            break;
        case 3:
            printf("����������:");
            scanf("%s",writerTemp);
            for(int i=0;i<=len;i++)
            {
                if(strcmp(writerTemp,main[i].writer)==0)
                {
                    outputInformation(main,i);
                }
            }
            break;
        case 4:
            printf("�����������:");
            scanf("%s",pubTemp);
            for(int i=0;i<=len;i++)
            {
                if(strcmp(pubTemp,main[i].publish)==0)
                {
                    outputInformation(main,i);
                }
            }
            break;
        case 5:
            return 1;
            break;
        case 6:
            printf("����������:");
            scanf("%d",&temp);
            r=temp-1;
            outputInformation(main,r);
            break;
        default:
            break;
    }
}

int lentManager(person **headA,lent **headB,books main[],int len)
{
    uiShow6();
    int sel=0,pend=0,userTemp=0,booksTemp=0;
    int year=0,month=0,day=0;
    person *pr=*headA;
    scanf("%d",&sel);
    printf("\n");

    switch(sel)
    {
        case 1:
            printf("�������������(��/��/��):");
            scanf("%d %d %d",&year,&month,&day);

            printf("�������û���:");
            scanf("%d",&userTemp);
            printf("\n");
            while(pr)
            {
                if(userTemp==pr->userNumber)
                {
                    int temp=((pr->borrow.canBorrow)-(pr->borrow.alBorrow));
                    if(temp>0)
                    {
                        pr->borrow.alBorrow++;
                        break;
                    }
                    else
                    {
                        printf("�����ɽ�����,�޷��ٽ�!\n");
                        return 0;
                    }
                }
                if(pr->next==NULL)
                {
                    printf("���û���������!\n\n");
                    return 0;
                }
                pr=pr->next;
            }

            printf("������Ҫ������:");
            scanf("%d",&booksTemp);
            printf("\n");
            for(int i=0;i<=len;i++)
            {
                if(booksTemp==main[i].number)
                {
                    if((main[i].haveNumber-main[i].alNumber)>0)
                    {
                        main[i].alNumber++;
                        printf("����ɹ�!\n\n");

                        lent *p=(lent*)malloc(sizeof(lent));//headB������
                        p->next=NULL;
                        p->userNumber=userTemp;
                        p->bookNumber=booksTemp;
                        p->leDay.year=year;p->leDay.month=month;p->leDay.day=day;
                        p->reDay.year=0;p->reDay.month=0;p->reDay.day=0;

                        if(*headB==NULL)
                        {
                            *headB=p;
                        }
                        else
                        {
                            lent *ps=*headB;
                            while(ps->next)
                            {
                                ps=ps->next;
                            }
                            ps->next=p;
                        }
                    }
                    else
                    {
                        printf("�����ѱ����!\n\n");
                    }
                    break;
                }
                if(i==len)
                {
                    printf("���鲻����!\n\n");
                }
            }
            break;
        case 2:
            printf("�������������(��/��/��):");
            scanf("%d %d %d",&year,&month,&day);
            printf("�������û���:");
            scanf("%d",&userTemp);
            printf("������Ҫ�������:");
            scanf("%d",&booksTemp);
            printf("\n");

            lent *ps=*headB;
            while(ps)
            {
                pend=0;
                if(ps->userNumber==userTemp)
                {
                    pend=1;
                }
                if((ps->bookNumber==booksTemp)&&pend==1)
                {
                    while(pr)
                    {
                        if(pr->userNumber==userTemp)
                        {
                            pr->borrow.alBorrow--;
                            break;
                        }
                        pr=pr->next;
                    }
                    ps->reDay.year=year;ps->reDay.month=month;ps->reDay.day=day;
                    printf("����ɹ�!\n");
                    break;
                }
                if(pend==1&&ps->next==NULL)
                {
                    printf("��û�н���Ȿ��!\n");
                }
                ps=ps->next;
            }
            break;
        case 3:
            outputState(*headB);
            break;
        case 4:
            return 1;
    }
}

void outputInformation(books main[],int i)
{
    printf("---------------------------------------------------------\n");
    printf(" ���    ����        ����    ������    ������    �����\n");
    printf(" %-8d%-12s%-8s%-10s%-10d%-8d\n",main[i].number,main[i].name,main[i].writer,
           main[i].publish,main[i].haveNumber,main[i].alNumber);
    printf("---------------------------------------------------------\n\n");
}

void outputState(lent *headB)
{
    lent *pr=headB;
    printf("---------------------------------------------------------------\n");
    printf(" ���ߺ�      ���        ��������        ��������      ��ע\n");
    printf("---------------------------------------------------------------\n");
    while(pr)
    {
        printf(" %-12d%-12d%-4d/%-2d/%-2d",pr->userNumber,pr->bookNumber,pr->leDay.year,pr->leDay.month,pr->leDay.day);
        if(pr->reDay.year==0)
        {
            printf("                    ����δ��\n");
        }
        else
        {
            printf("    %-4d/%-2d/%-2d\n",pr->reDay.year,pr->reDay.month,pr->reDay.day);
        }
        pr=pr->next;
    }
    printf("---------------------------------------------------------------\n");
}

void writeTofile(person **head)
{
    FILE *fp;
    if((fp=fopen("library.txt","w"))==NULL)
    {
        printf("�ļ���ʧ��!");
        exit(0);
    }

    person *pr=*head,*pt=NULL;
    while(pr)
    {
        fprintf(fp,"%d %d %s %s %s %s %d ",pr->type,pr->userNumber,pr->lock,pr->borrow.name,
                pr->borrow.unit,pr->borrow.phoneNumber,pr->borrow.alBorrow);
        pt=pr;
        pr=pr->next;
        free(pt);
    }
    *head=NULL;
    fclose(fp);
}

void readFromfile(person **head)
{
    FILE *fp;
    if((fp=fopen("library.txt","r"))==NULL)
    {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }

    getc(fp);
    if(feof(fp))
    {
        fclose(fp);
    }
    else
    {
        rewind(fp);

        while(!feof(fp))
        {
            person *pr=*head;
            person *p=(person*)malloc(sizeof(person));
            p->next=NULL;

            fscanf(fp,"%d %d %s %s %s %s %d ",&p->type,&p->userNumber,p->lock,p->borrow.name,
                   p->borrow.unit,p->borrow.phoneNumber,&p->borrow.alBorrow);

            if(*head==NULL)
            {
                *head=p;
            }
            else
            {
                while(pr->next)
                {
                    pr=pr->next;
                }
                pr->next=p;
            }
        }
        fclose(fp);
    }
}

void readFromfile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen)
{
    FILE *fp1,*fp2,*fp3,*fp4;
    if((fp1=fopen("main.txt","r"))==NULL||(fp2=fopen("name.txt","r"))==NULL||(fp3=fopen("writer.txt","r"))==NULL||(fp4=fopen("publish.txt","r"))==NULL)
    {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }

    getc(fp1);getc(fp2);getc(fp3);getc(fp4);
    if(feof(fp1)||feof(fp2)||feof(fp3)||feof(fp4))
    {
        fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);
    }
    else
    {
        rewind(fp1);rewind(fp2);rewind(fp3);rewind(fp4);
        while(!feof(fp1))
        {
            (*len)++;
            fscanf(fp1,"%d %s %s %s %d %d ",&main[*len].number,main[*len].name,main[*len].writer,
               main[*len].publish,&main[*len].haveNumber,&main[*len].alNumber);
        }
        while(!feof(fp2))
        {
            (*nlen)++;
            fscanf(fp2,"%s %d %d ",name[*nlen].name,&name[*nlen].pointer.point,&name[*nlen].pointer.length);
        }
        while(!feof(fp3))
        {
            (*wlen)++;
            fscanf(fp3,"%s %d %d ",writer[*wlen].name,&writer[*wlen].pointer.point,&writer[*wlen].pointer.length);
        }
        while(!feof(fp4))
        {
            (*plen)++;
            fscanf(fp4,"%s %d %d ",pub[*plen].name,&pub[*plen].pointer.point,&pub[*plen].pointer.length);
        }
    }
    fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);
}

void writeTofile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int len,int nlen,int wlen,int plen)
{
    FILE *fp1,*fp2,*fp3,*fp4;
    if((fp1=fopen("main.txt","w"))==NULL||(fp2=fopen("name.txt","w"))==NULL||(fp3=fopen("writer.txt","w"))==NULL||(fp4=fopen("publish.txt","w"))==NULL)
    {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }

    for(int i=0;i<=len;i++)
    {
        fprintf(fp1,"%d %s %s %s %d %d ",main[i].number,main[i].name,main[i].writer,
           main[i].publish,main[i].haveNumber,main[i].alNumber);
    }
    for(int i=0;i<=nlen;i++)
    {
        fprintf(fp2,"%s %d %d ",name[i].name,name[i].pointer.point,name[i].pointer.length);
    }
    for(int i=0;i<=wlen;i++)
    {
        fprintf(fp3,"%s %d %d ",writer[i].name,writer[i].pointer.point,writer[i].pointer.length);
    }
    for(int i=0;i<=plen;i++)
    {
        fprintf(fp4,"%s %d %d ",pub[i].name,pub[i].pointer.point,pub[i].pointer.length);
    }
    fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);
}

void writeTofile2(lent **head)
{
    FILE *fp;
    if((fp=fopen("lent.txt","w"))==NULL)
    {
        printf("�ļ���ʧ��!");
        exit(0);
    }

    lent *pr=*head;
    while(pr)
    {
        fprintf(fp,"%d %d %d %d %d %d %d %d",pr->userNumber,pr->bookNumber,pr->leDay.year,
                pr->leDay.month,pr->leDay.day,pr->reDay.year,pr->reDay.month,pr->reDay.day);
        pr=pr->next;
    }
    fclose(fp);
}

void readFromfile2(lent **head)
{
    FILE *fp;
    if((fp=fopen("lent.txt","r"))==NULL)
    {
        printf("�ļ���ʧ��!");
        exit(0);
    }

    getc(fp);
    if(feof(fp))
    {
        fclose(fp);
    }
    else
    {
        rewind(fp);
        while(!feof(fp))
        {
            lent *p=(lent*)malloc(sizeof(lent));
            fscanf(fp,"%d %d %d %d %d %d %d %d",&p->userNumber,&p->bookNumber,&p->leDay.year,
                &p->leDay.month,&p->leDay.day,&p->reDay.year,&p->reDay.month,&p->reDay.day);
            if(*head==NULL)
            {
                *head=p;
            }
            else
            {
                lent *pr=*head;
                while(pr->next)
                {
                    pr=pr->next;
                }
                pr->next=p;
            }
        }
    }
    fclose(fp);
}

void release(person **head)
{
    if(*head==NULL)
    {
        return ;
    }
    person *pr=*head,*pt=NULL;
    for(pt=pr;pr;pt=pr)
    {
        pr=pr->next;
        free(pt);
    }
    *head=NULL;
}
