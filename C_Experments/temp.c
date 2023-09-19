#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct borrowState
{
    char name[12];
    char unit[10];
    int phoneNumber;
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

void writeTofile1(person **head)
{
    FILE *fp;
    if((fp=fopen("test.txt","w"))==NULL)
    {
        printf("文件打开失败!");
        exit(0);
    }

    person *pr=*head,*pt=NULL;
    while(pr)
    {
        fprintf(fp,"%d %d %s ",pr->type,pr->userNumber,pr->lock);
        pt=pr;
        pr=pr->next;
        free(pt);
    }
    fclose(fp);
}

void readFromfile1(person **head)
{
    FILE *fp;
    if((fp=fopen("test.txt","r"))==NULL)
    {
        printf("文件打开失败！");
        exit(0);
    }

    while(!feof(fp))
    {
        person *pr=*head;
        person *p=(person*)malloc(sizeof(person));
        p->next=NULL;

        fscanf(fp,"%d %d %s ",&p->type,&p->userNumber,p->lock);

        if(*head==NULL)
        {
            *head=p;
        }
        else
        {
            while(pr->next!=NULL)
            {
                pr=pr->next;
            }
            pr->next=p;
        }
    }
    fclose(fp);
}

void firstInput()
{
    FILE *fp;
    if((fp=fopen("test.txt","w"))==NULL)
    {
        printf("打开文件失败！");
        exit(0);
    }

    int type=0,userNumber=0;
    char lock[10];
    scanf("%d",&type);
    scanf("%d",&userNumber);
    scanf("%s",lock);

    fprintf(fp,"%d %d %s ",type,userNumber,lock);
    fclose(fp);
}
int main()
{
    return 0;
}
