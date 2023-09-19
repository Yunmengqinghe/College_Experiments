#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    long ID;
    char Name[20];
    char Sex;
    int old;
    int Score_c;
    struct student *next;
} STU;
/*  �������ܣ�����һ��ѧ���Ļ�����Ϣ��
    ������ڲ���������ͷָ��
    ��������ֵ������ͷָ��
*/
STU *AppendNode(STU *head)
{
    STU *p=head,*pr=head,*temp=NULL;
    long addID;
    p=(STU*)malloc(sizeof(STU));
    if(p==NULL)
    {
        exit(0);
    }
    p->next=NULL;;
    scanf("%ld",&p->ID);
    addID=p->ID;
    scanf("%s",p->Name);
    scanf(" %c",&p->Sex);
    scanf("%d",&p->old);
    scanf("%d",&p->Score_c);
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        while(pr->ID<addID&&pr->next!=NULL)
        {
            temp=pr;
            pr=pr->next;
        }
        if(pr->ID>=addID)
        {
            if(pr==head)
            {
                p->next=head;
                head=p;
            }
            else
            {
                pr=temp;
                p->next=pr->next;
                pr->next=p;
            }
        }
        else
        {
            pr->next=p;
        }
    }
    return head;
}
/*  �������ܣ����һ��ѧ���Ļ�����Ϣ��
    ������ڲ���������ͷָ��
    ��������ֵ������ͷָ��
*/
void DisplyNode(STU *head)
{
    STU *p=head;
    int j=1;
    while(p!=NULL)
    {
        printf("%d",j);
        printf("%10ld",p->ID);
        printf("%8s",p->Name);
        printf("%5c",p->Sex);
        printf("%5d",p->old);
        printf("%5d\n",p->Score_c);
        p=p->next;
        j++;
    }
}
/*  �������ܣ�ɾ��һ��ѧ���Ļ�����Ϣ��
    ������ڲ���������ͷָ��
    ��������ֵ������ͷָ��
*/
STU *DeleteNode(STU *head)
{
    STU *p=head,*pr=NULL;
    long DeleID;
    scanf("%ld",&DeleID);
    if(head==NULL)
    {
        printf("Linked table is empty\n");
        return head;
    }
    while(p->ID!=DeleID&&p->next!=NULL)
    {
             pr=p;
        p=p->next;
    }
    if(p->ID==DeleID)
    {
        if(p==head)
        {
            head=p->next;
        }
        else
        {
            pr->next=p->next;
        }
        free(p);
    }
    else
    {
        printf("Not been found\n");
    }
    return head;
}

int main()
{
    int i=0;
    int a;
    STU *head=NULL;
    while(1)
    {
        printf("(1)����һ��ѧ���Ļ�����Ϣ��\n");
        printf("(2)����ѧ�ţ�ɾ��һ��ѧ���Ļ�����Ϣ��\n");
        printf("(3)���ѧ���Ļ�����Ϣ��\n");
        scanf("%d",&a);
        if(a==1)
            head=AppendNode(head);
        if(a==3)
            DisplyNode(head);
        if(a==2)
            head=DeleteNode(head);
        if(a==4)
            break;
    }
    return 0;
}
/*
20215760 hu m 40 90
20215761 xiang m 11 91
20215762 yu m 12 90
20215763 yu2 m 15 85
*/
