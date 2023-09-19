#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
    int type;
    struct person *next;
}person;

void test(person **head)
{
    for(person *p1=*head;p1;p1=p1->next)
    {
        for(person *p2=*head,*p3=p2->next;p2;p2=p2->next,p3=p2->next)
        {
            if(p2->type<p3->type)
            {
                if(p2==*head)
                {
                    *head=p3;
                    p2->next=p3->next;
                    p3->next=p2;
                }
                else
                {
                    person *pr=*head;
                    while(pr->next!=p2)
                    {
                        pr=pr->next;
                    }
                    pr->next=p3;
                    p2->next=p3->next;
                    p3->next=p2;
                }
            }

        }
    }
}

void test2(person **head)
{
    person *p=(person*)malloc(sizeof(person));
    p->next=NULL;
    if(p==NULL)
    {
        printf("创建链表失败\n");
        exit(0);
    }

    for(person *pr=*head;pr->next;pr=pr->next)
    {
        for(person *pt=*head;pt->next;pt=pt->next)
        {
            person *ps=pt->next;
            if(ps->type < pt->type)
            {
                p->type=ps->type;
                ps->type=pt->type;
                pt->type=p->type;
            }
        }
    }
}

int main()
{
    person *head=NULL;
    int x;
    while(1)
    {
        printf("输入:");
        scanf("%d",&x);
        if(x==0)
        {
            break;
        }
        person *p=(person*)malloc(sizeof(person));
        if(p==NULL)
        {
            printf("创建失败!\n");
            exit(0);
        }
        p->next=NULL;
        p->type=x;
        person *pr=head;

        if(head==NULL)
        {
            head=p;
        }
        else
        {
            while(pr->next)
            {
                pr=pr->next;
            }
            pr->next=p;
        }

        pr=head;
        while(pr)
        {
            printf("%d\n",pr->type);
            pr=pr->next;
        }
        printf("\n");
    }

    test2(&head);

    person *pr=head;
    while(pr)
    {
        printf("%d\n",pr->type);
        pr=pr->next;
    }
    return 0;
}

//    person *p=(person*)malloc(sizeof(person));
//    for(person *pr=*head;pr->next;pr=pr->next)
//    {
//        for(person *pt=*head;pt->next;pt=pt->next)
//        {
//            person *ps=pt->next;
//            if(strcmp(ps->borrow.name,pt->borrow.name)<0)
//            {
//                p->type=ps->type;p->userNumber=ps->userNumber;strcpy(p->lock,ps->lock);strcpy(p->borrow.name,ps->borrow.name);
//                strcpy(p->borrow.unit,ps->borrow.unit);strcpy(p->borrow.phoneNumber,ps->borrow.phoneNumber);
//                p->borrow.alBorrow=ps->borrow.alBorrow;
//
//                ps->type=pt->type;ps->userNumber=pt->userNumber;strcpy(ps->lock,pt->lock);strcmp(ps->borrow.name,pt->borrow.name);
//                strcpy(ps->borrow.unit,pt->borrow.unit);strcpy(ps->borrow.phoneNumber,pt->borrow.phoneNumber);
//                ps->borrow.alBorrow=pt->borrow.alBorrow;
//
//                pt->type=p->type;pt->userNumber=p->userNumber;strcpy(pt->lock,p->lock);strcpy(pt->borrow.name,p->borrow.name);
//                strcpy(pt->borrow.unit,p->borrow.unit);strcpy(pt->borrow.phoneNumber,p->borrow.phoneNumber);
//                pt->borrow.alBorrow=p->borrow.alBorrow;
//            }
//        }
//    }

