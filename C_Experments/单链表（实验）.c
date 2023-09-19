#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct PNode
{
     float coef;//系数
     int expn;//指数
     struct PNode *next;
}pnode;

void createPoly(pnode **head);
pnode* addPoly(pnode *headA,pnode *headB);
void output(pnode *head);

int main()
{
    pnode *headA=NULL;
    pnode *headB=NULL;
    pnode *headC=NULL;
    int n;

    printf("请输入多项式 A 的项数:");
    scanf("%d",&n);
    printf("请输入多项式 A 各项的系数与指数:");
    for(int i=0;i<n;i++)
    {
        createPoly(&headA);
    }
    printf("输出多项式 A:\n");
    output(headA);

    printf("请输入多项式 B 的项数:");
    scanf("%d",&n);
    printf("请输入多项式 B 各项的系数与指数:");
    for(int i=0;i<n;i++)
    {
        createPoly(&headB);
    }
    printf("输出多项式 B:\n");
    output(headB);

    headC=addPoly(headA,headB);
    output(headC);
    return 0;
}

void createPoly(pnode **head)
{
    pnode *pr=*head,*pt=NULL;
    pnode *p=(pnode *)malloc(sizeof(pnode));
    p->next=NULL;

    if(p==NULL)
    {
        exit(0);
    }

    scanf("%f %d",&p->coef,&p->expn);

    if(*head==NULL)
    {
        *head=p;
    }
    else
    {
        while(p->expn > pr->expn && pr->next != NULL)
        {
            pt=pr;
            pr=pr->next;
        }

        if(pr->expn >= p->expn)
        {
            if(pr==*head)
            {
                p->next=pr;
                *head=p;
            }
            else
            {
                p->next=pt->next;
                pt->next=p;
            }
        }
        else
        {
            pr->next=p;
            p->next=NULL;
        }
    }
}

void output(pnode *head)
{
    pnode *p=NULL;
    for(p=head;p;p=p->next)
    {
        printf("%.2f %d",p->coef,p->expn);
        printf("\n");
    }
}

//void addPoly(pnode **headA,pnode **headB)
//{
//    pnode *p1=*headA,*p2=*headB,*p3=NULL,*pr=NULL;
//    *headA=NULL;
//
//    while(1)
//    {
//        if(p1&&p2)
//        {
//            if(p1->expn==p2->expn)
//            {
//                int sum=p1->coef+p2->coef;
//
//                if(sum==0)
//                {
//                    p1=p1->next;
//                    p2=p2->next;
//                }
//                else
//                {
//                    p1->coef=sum;
//                    p3->next=p1;
//                    p3=p1;
//                    p1=p1->next;
//                    p2=p2->next;
//                }
//            }
//            else
//            {
//                if(p1->expn<p2->expn)
//                {
//                    if(p3!=NULL)
//                    {
//                        p3->next=p1;
//                        p3=p1;
//                        p1=p1->next;
//                    }
//                    else
//                    {
//                        p3=p1;
//                        p1=p1->next;
//                        p3->next=NULL;
//                    }
//                }
//                else
//                {
//                    if(p3!=NULL)
//                    {
//                        p3->next=p2;
//                        p3=p2;
//                        p2=p2->next;
//                    }
//                    else
//                    {
//                        p3=p2;
//                        p2=p2->next;
//                        p3->next=NULL;
//                    }
//                }
//            }
//        }
//        else
//        {
//            if(p1!=NULL)
//            {
//                p3->next=p1;
//            }
//            else
//            {
//                p3->next=p2;
//            }
//            break;
//        }
//    }
//    *headA=p3;
//}

pnode* addPoly(pnode *a,pnode *b)
{
	pnode *c,*p1,*p2,*p3,*r;
	int sum;

	p1=a->next;
	p2=b->next;
	c=a;
	p3=c;
	while(p1&&p2)
	{
		if(p1->expn<p2->expn)
		{
			p3->next=p1;
			p3=p1;
			p1=p1->next;
		}
		else if(p1->expn>p2->expn)
		{
			p3->next=p2;
			p3=p2;
			p2=p2->next;
		}
		else
		{
			sum=p1->coef+p2->coef;
			if(sum!=0)
			{
				p1->coef=sum;
				p3->next=p1;
				p3=p1;
				p1=p1->next;
				r=p2;
				p2=p2->next;
				free(r);
			}
			else
			{
				r=p1;
				p1=p1->next;
				free(r);

				r=p2;
				p2=p2->next;
                free(r);
			}
		}
	}

	if(p1)
	{
		p3->next=p1;
	}
	else
	{
		p3->next=p2;
	}
	free(b);
	return c;
}

