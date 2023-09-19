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
        uiShow1();//显示选择的UI

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
                break;//用户管理
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
    printf("******************\n  1.用户管理\n  2.读者管理\n  3.图书管理\n  4.图书流通管理\n  5.退出系统\n******************\n你要选择的功能:");
}

void uiShow2()
{
    printf("******************\n  1.用户信息输入\n  2.用户信息修改\n  3.用户信息删除\n  4.用户信息显示\n  5.用户密码修改\n  6.返回主菜单\n******************\n你要选择的功能:");
}

void uiShow3()
{
    printf("******************\n  1.读者信息输入\n  2.读者信息修改\n  3.读者信息删除\n  4.读者信息查询\n  5.读者信息显示\n  6.返回主菜单\n******************\n你要选择的功能:");
}

void uiShow4()
{
    printf("******************\n  1.图书信息输入\n  2.图书信息修改\n  3.图书信息查询\n  4.汇总统计\n  5.返回主菜单\n******************\n你要选择的功能:");
}

void uiShow5()
{
    printf("******************\n  1.按书号查询\n  2.按书名查询\n  3.按作者查询\n  4.按出版社查询\n  5.返回主菜单\n 6.按索引查询\n******************\n你要选择的功能:");
}

void uiShow6()
{
    printf("******************\n  1.借书处理\n  2.还书处理\n  3.显示模块\n  4.返回主菜单\n******************\n你要选择的功能:");
}

int logIn(person **head)
{
    if(*head==NULL)
    {
        FILE *fp;
        if((fp=fopen("library.txt","w"))==NULL)
        {
            printf("文件打开失败!");
            exit(0);
        }

        person *p=(person*)malloc(sizeof(person));
        p->next=NULL;
        printf("********注册********\n");
        printf("请输入用户类型:");
        scanf("%d",&p->type);
        printf("请输入用户名:");
        scanf("%d",&p->userNumber);
        printf("请输入密码:");
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
        printf("********登录********\n");

        printf("输入用户名:");
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
                printf("输入密码:");
                scanf("%s",lockTemp);
                if(strcmp(pr->lock,lockTemp)==0)
                {
                    printf("登录成功\n\n");
                    return pr->type;
                }
                else
                {
                    count--;
                    printf("密码错误!剩余次数%d\n\n",count);
                    if(count==0)
                    {
                        printf("登录失败!\n\n");
                        return 0;
                    }
                }
            }
            if(pr->next==NULL)
            {
                printf("用户名不存在!\n\n");
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
        printf("创建链表失败\n");
        exit(0);
    }

    scanf("%d",&sel);
    printf("\n");

    switch (sel)
    {
        case 1:
            printf("请输入用户名:");
            scanf("%d", &numberTemp);

            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("此用户已存在,无法输入！\n");
                    break;
                }
                else
                {
                    p->userNumber=numberTemp;
                    printf("请输入用户类型:");
                    scanf("%d", &p->type);
                    printf("请输入用户密码:");
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

                    printf("输入成功!\n\n");
                    break;
                }
            }
            break;

        case 2:
            printf("请输入要修改信息的原用户名:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("******************\n");
                    printf(" 1.用户名修改\n");
                    printf(" 2.密码修改\n");
                    printf(" 3.用户类型修改\n");
                    printf("******************\n");
                    printf("你要选择的功能:");
                    scanf("%d",&sel);
                    printf("\n");

                    switch(sel)
                    {
                        case 1:
                            printf("请输入用户名:");
                            scanf("%d",&pr->userNumber);
                            printf("\n");
                            break;
                        case 2:
                            printf("请输入密码:");
                            scanf("%s",pr->lock);
                            printf("\n");
                            break;
                        case 3:
                            printf("请输入用户类型:");
                            scanf("%d",&pr->type);
                            printf("\n");
                            break;
                    }
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("此用户不存在!\n\n");
                    break;
                }
            }
            break;

        case 3:
            printf("请输入要删除的信息的用户名:");
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
                        printf("删除成功!\n\n");
                        break;
                    }
                    else
                    {
                        printf("有书未还，删除失败!\n");
                        break;
                    }
                }
                if(pr->next==NULL)
                {
                    printf("此用户不存在!\n\n");
                    break;
                }
            }
            break;

        case 4:
            printf("--------------------------------------------------\n");
            printf(" 用户名(读者号)      用户密码      用户类型\n");
            printf("--------------------------------------------------\n");
            for(pr=*head;pr;pr=pr->next)
            {
                printf(" %-20d%-14s%d",pr->userNumber,pr->lock,pr->type);
                switch(pr->type)
                {
                case 1:
                    printf("(用户管理员)\n");
                    break;
                case 2:
                    printf("(图书管理员)\n");
                    break;
                case 3:
                    printf("(普通读者)\n");
                    break;
                default:
                    break;
                }
            }
            printf("--------------------------------------------------\n\n");
            break;

        case 5:
            printf("请输入用户名:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("请输入要修改的密码:");
                    scanf("%s",pr->lock);
                    printf("\n");
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("此用户不存在!\n\n");
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
        printf("创建链表失败\n");
        exit(0);
    }

    scanf("%d",&sel);
    printf("\n");

    switch(sel)
    {
        case 1:
            printf("请输入用户名:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    free(p);
                    printf("请输入读者名:");
                    scanf("%s",pr->borrow.name);
                    printf("请输入读者单位:");
                    scanf("%s",pr->borrow.unit);
                    printf("请输入读者联系电话:");
                    scanf("%s",pr->borrow.phoneNumber);
                    printf("请输入已借书数:");
                    scanf("%d",&pr->borrow.alBorrow);

                    printf("输入成功!\n\n");
                    break;
                }

                if(pr->next==NULL)
                {
                    p->userNumber=numberTemp;

                    printf("请输入用户类型:");
                    scanf("%d", &p->type);
                    printf("请输入用户密码:");
                    scanf("%s",p->lock);
                    printf("请输入读者名:");
                    scanf("%s",p->borrow.name);
                    printf("请输入读者单位:");
                    scanf("%s",p->borrow.unit);
                    printf("请输入读者联系电话:");
                    scanf("%s",p->borrow.phoneNumber);
                    printf("请输入已借书数:");
                    scanf("%d",&p->borrow.alBorrow);

                    printf("输入成功!\n\n");

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
            printf("请输入要修改信息的原读者号:");
            scanf("%d",&numberTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(numberTemp==pr->userNumber)
                {
                    printf("******************\n");
                    printf(" 1.读者号修改\n");
                    printf(" 2.读者名修改\n");
                    printf(" 3.单位修改\n");
                    printf(" 4.联系方式修改\n");
                    printf(" 5.已借书数修改\n");
                    printf("******************\n");
                    printf("你要选择的功能:");
                    scanf("%d",&sel);
                    printf("\n");

                    switch(sel)
                    {
                        case 1:
                            printf("请输入读者号:");
                            scanf("%d",&pr->userNumber);
                            printf("\n");
                            break;
                        case 2:
                            printf("请输入读者名:");
                            scanf("%s",pr->borrow.name);
                            printf("\n");
                            break;
                        case 3:
                            printf("请输入单位:");
                            scanf("%s",pr->borrow.unit);
                            printf("\n");
                            break;
                        case 4:
                            printf("请输入联系方式:");
                            scanf("%s",pr->borrow.phoneNumber);
                            printf("\n");
                            break;
                        case 5:
                            printf("请输入已借书数:");
                            scanf("%d",&pr->borrow.alBorrow);
                            printf("\n");
                            break;
                    }
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("此用户不存在!\n\n");
                    break;
                }
            }
            break;

        case 3:
            printf("请输入要删除的信息的用户名:");
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
                        printf("删除成功!\n\n");
                        break;
                    }
                    else
                    {
                        printf("有书未还，删除失败!\n");
                        break;
                    }
                }
                if(pr->next==NULL)
                {
                    printf("此用户不存在!\n\n");
                    break;
                }
            }
            break;

        case 4:
            printf("请输入要查询的用户姓名:");
            scanf("%s",nameTemp);
            for(pr=*head;pr;pr=pr->next)
            {
                if(strcmp(nameTemp,pr->borrow.name)==0)
                {
                    printf("--------------------------------------------------------------------------------\n");
                    printf(" 读者号      读者名      单位          联系方式        可借书数      已借书数\n");
                    printf("--------------------------------------------------------------------------------\n");
                    printf(" %-12d%-12s%-14s%-16s%-14d%-11d\n",pr->userNumber,pr->borrow.name,pr->borrow.unit,
                           pr->borrow.phoneNumber,pr->borrow.canBorrow,pr->borrow.alBorrow);
                    printf("--------------------------------------------------------------------------------\n");
                    break;
                }
                if(pr->next==NULL)
                {
                    printf("此用户不存在!\n\n");
                    break;
                }
            }
            break;

        case 5:
            printf("--------------------------------------------------------------------------------\n");
            printf(" 读者号      读者名      单位          联系方式        可借书数      已借书数\n");
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
            printf("请输入书号:");
            scanf("%d",&main[*len].number);
            printf("请输入书名:");
            scanf("%s",main[*len].name);
            printf("请输入作者名:");
            scanf("%s",main[*len].writer);
            printf("请输入出版社:");
            scanf("%s",main[*len].publish);
            printf("请输入藏书量:");
            scanf("%d",&main[*len].haveNumber);
            while(1)
            {
                printf("请输入借出量:");
                scanf("%d",&main[*len].alNumber);

                if(main[*len].haveNumber<main[*len].alNumber)
                {
                    printf("藏书量小于借出量，请再次输入!\n");
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
            printf("请输入要修改的书号:");
            scanf("%d",&temp);
            if(*len==-1)
            {
                printf("书号不存在!\n\n");
            }
            for(int i=0;i<=*len;i++)
            {
                if(main[i].number==temp)
                {
                    printf("1.修改藏书量\n2.修改借出量\n\n");
                    printf("请选择要实现的功能:");
                    scanf("%d",&sel);
                    switch(sel)
                    {
                        case 1:
                            printf("输入藏书量:");
                            scanf("%d",&main[i].haveNumber);
                            break;
                        case 2:
                            printf("输入借出量:");
                            scanf("%d",&main[i].alNumber);
                            break;
                        default:
                            break;
                    }
                    printf("修改成功\n\n");
                    break;
                }
                if(i==*len)
                {
                    printf("书号不存在!\n\n");
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
            printf(" 记录号    书号    书名        作者    出版社    藏书量    借出数    指针1    指针2    指针3\n");
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
            printf("   书名    链头指针    长度\n");
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
            printf("  作者名    链头指针    长度\n");
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
            printf("  出版社    链头指针    长度\n");
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
            printf("请输入书号:");
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
                printf("书号不存在!\n");
            }
            outputInformation(main,r);
            break;
        case 2:
            printf("请输入书名:");
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
            printf("请输入作者:");
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
            printf("请输入出版社:");
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
            printf("请输入索引:");
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
            printf("请输入今日日期(年/月/日):");
            scanf("%d %d %d",&year,&month,&day);

            printf("请输入用户名:");
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
                        printf("超过可借书量,无法再借!\n");
                        return 0;
                    }
                }
                if(pr->next==NULL)
                {
                    printf("此用户名不存在!\n\n");
                    return 0;
                }
                pr=pr->next;
            }

            printf("请输入要借的书号:");
            scanf("%d",&booksTemp);
            printf("\n");
            for(int i=0;i<=len;i++)
            {
                if(booksTemp==main[i].number)
                {
                    if((main[i].haveNumber-main[i].alNumber)>0)
                    {
                        main[i].alNumber++;
                        printf("借书成功!\n\n");

                        lent *p=(lent*)malloc(sizeof(lent));//headB链表创建
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
                        printf("此书已被借出!\n\n");
                    }
                    break;
                }
                if(i==len)
                {
                    printf("此书不存在!\n\n");
                }
            }
            break;
        case 2:
            printf("请输入今日日期(年/月/日):");
            scanf("%d %d %d",&year,&month,&day);
            printf("请输入用户名:");
            scanf("%d",&userTemp);
            printf("请输入要还的书号:");
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
                    printf("还书成功!\n");
                    break;
                }
                if(pend==1&&ps->next==NULL)
                {
                    printf("您没有借过这本书!\n");
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
    printf(" 书号    书名        作者    出版社    藏书量    借出数\n");
    printf(" %-8d%-12s%-8s%-10s%-10d%-8d\n",main[i].number,main[i].name,main[i].writer,
           main[i].publish,main[i].haveNumber,main[i].alNumber);
    printf("---------------------------------------------------------\n\n");
}

void outputState(lent *headB)
{
    lent *pr=headB;
    printf("---------------------------------------------------------------\n");
    printf(" 读者号      书号        借书日期        还书日期      备注\n");
    printf("---------------------------------------------------------------\n");
    while(pr)
    {
        printf(" %-12d%-12d%-4d/%-2d/%-2d",pr->userNumber,pr->bookNumber,pr->leDay.year,pr->leDay.month,pr->leDay.day);
        if(pr->reDay.year==0)
        {
            printf("                    借书未还\n");
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
        printf("文件打开失败!");
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
        printf("文件打开失败！");
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
        printf("文件打开失败！");
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
        printf("文件打开失败！");
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
        printf("文件打开失败!");
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
        printf("文件打开失败!");
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
