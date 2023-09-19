#include<stdio.h>
#include<malloc.h>
#include<strings.h>
#include<stdlib.h>
typedef struct Student
{
    int num;
    int age;
    char name[10];
    char sexual;
    int mark;
    struct Student *next;
}stu;

void insert(stu **head);
void del(stu **phead);
void output(stu *head);

int main()
{
    stu *head=NULL;
    int number;
    do
    {
        printf("请输入指令1，2，3，4（分别为输入信息，删除信息，输出，停止输入）：");
        scanf("%d",&number);
        switch(number)
        {
            case 1:
                insert(&head);
                break;
            case 2:
                del(&head);
                break;
            case 3:
                output(head);
                break;
            case 4:
                break;
        }
    }while(number!=4);
    return 0;
}

void insert(stu **phead)
{
    stu *last=*phead,*temp=NULL;
    stu *p=(stu *)malloc(sizeof(stu));
    if(p==NULL)
    {
        exit(0);
    }

    scanf("%d",&p->num);
    scanf("%d",&p->age);
    scanf("%s",p->name);
    scanf(" %c",&p->sexual);
    scanf("%d",&p->mark);
    p->next=NULL;

    if(*phead==NULL)
    {
        *phead=p;
    }
    else
    {
        while(last->num<p->num && last->next!=NULL)
        {
            temp=last;
            last=last->next;
        }
        if(last->num>=p->num)
        {
            if(last==*phead)
            {
                p->next=last;
                *phead=p;
            }
            else
            {
                p->next=temp->next;
                temp->next=p;
            }
        }
        else
        {
            last->next=p;
            p->next=NULL;
        }
    }

}

void del(stu **phead)
{
    stu *last=*phead,*temp=NULL;
    int number;
    printf("输入学号：");
    scanf("%d",&number);
    for(last=*phead;last;temp=last,last=last->next)
    {
        if(last->num==number)
        {
            if(temp)
            {
                temp->next=last->next;
            }
            else
            {
                *phead=last->next;
            }
            free(last);
        }
    }
}

void output(stu *head)
{
    stu *p;
    for(p=head;p;p=p->next)
    {
        printf("%d %d %s %c %d\n",p->num,p->age,p->name,p->sexual,p->mark);
    }
}
