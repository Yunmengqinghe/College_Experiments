#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct PNode//����ʽ�ڵ�
{
    float coef;//ϵ��
    int expn;//ָ��    //������
    struct PNode* next;
} PNode;

/*
�������ܣ�����ڵ㲢��������
��ڲ�����ͷָ�룬Ҫ�����Ľڵ���
����ֵ�����ܱ����ĵ�ͷָ��
*/
PNode* creatPoly(PNode* head, int n)
{
    printf("���������ʽ�����ϵ����ָ����");
    while (n--)
    {
        PNode* p = NULL, * pr = head, * temp = NULL;//pָ���¿��ٵĽڵ㣬pr������������temp��������pr��λ��
        p = (PNode*)malloc(sizeof(PNode));
        p->next = NULL;
        scanf("%f", &p->coef);
        scanf("%d", &p->expn);
        if (head == NULL)//���Ϊ������
        {
            head = p;//�Ǿ���ͷ�ڵ�
        }
        else
        {
            while (pr->expn < p->expn && pr->next != NULL)
            {
                temp = pr;//���浱ǰ�ڵ��λ��
                pr = pr->next;//��prָ����һ���ڵ�
            }
            if (pr->expn >= p->expn)//�����Ԫ�ز��ڱ�β
            {
                if (pr == head)//����ͷ�ڵ�֮ǰ�����½ڵ�
                {
                    p->next = head;
                    head = p;
                }
                else//���м����
                {
                    pr = temp;
                    p->next = pr->next;//���½ڵ��ָ����ָ����һ�ڵ�
                    pr->next = p;
                }
            }
            else//�������Ԫ���ڱ�β
            {
                pr->next = p;
            }
        }
    }
    return head;
}

/*
�������ܣ������������������
��ڲ�����ͷָ��
����ֵ����
*/
void Output(PNode* head)
{
    PNode* p = head;
    for (; p->next != NULL; p = p->next)
    {
        printf("%.2f %d,  ", p->coef, p->expn);
    }
    printf("%.2f %d\n", p->coef, p->expn);
}

PNode* addPoly(PNode* headA, PNode* headB)
{
    PNode* p1, * p2, * p;
    PNode* temp = headA;//��������temp��ֵͷָ��ĺ����ڶ���ʽA��ָ������B��ָ�������ἰ

    p1 = p = headA;
    p2 = headB;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expn == p2->expn)//ָ�����ʱ
        {
            if (p1->coef + p2->coef != 0)//ͬ���������ʱ
            {
                p1->coef += p2->coef;//ϵ�����

                temp = p2;//p2ָ�����ʽB����һ�tempɾ���������һ��
                p1 = p1->next;
                p2 = p2->next;
                free(temp);
            }
            else//ͬ����������ʱ���迼���������
            {
                if (p1 == p)//ͷɾ
                {
                    temp = p1;
                    p1 = p1->next;
                    free(temp);
                    temp = p2;
                    p2 = p2->next;
                    free(temp);
                    if (p1 != NULL)
                        p = p1;//��ʱͷָ���ѱ��ı�
                    else//�����else˵������ʽA��ɾû��
                        p = p2;
                }
                else if (p1->next == NULL)//βɾ
                {
                    temp = p;
                    while (temp->next != p1)
                    {
                        temp = temp->next;//����temp�ҵ�p1��ǰһ��
                    }
                    temp->next = p2->next;
                    temp = p1;
                    p1 = p1->next;
                    free(temp);
                    temp = p2;
                    p2 = p2->next;
                    free(temp);
                }
                else//�м�ɾ
                {
                    temp = p;
                    while (temp->next != p1)
                    {
                        temp = temp->next;//����temp�ҵ�p1��ǰһ��
                    }
                    temp->next = p1->next;
                    temp = p1;
                    p1 = p1->next;
                    free(temp);
                    temp = p2;
                    p2 = p2->next;
                    free(temp);
                }
            }
        }
        else
        {
            if (p1->expn < p2->expn)//����ʽA��ָ��С��B��ָ��
            {
                while (p1->expn < p2->expn && p1 != NULL)
                {
                    temp = p1;
                    p1 = p1->next;
                    if (p1->expn == p2->expn)//ֱ������ִ��ָ����ȵĲ���
                        break;
                    else if (p1->expn > p2->expn)
                    {
                        temp->next = p2;
                        temp = p2->next;//����
                        p2->next = p1;
                        p2 = temp;
                    }
                }
                if (p1 == NULL)
                {
                    p1 = temp;//p1����
                    p1->next = p2;
                    return p;//����ֱ�ӽ���
                }
            }
            else//����ʽA��ָ������B��ָ��
            {
                if (temp == headA)//˵����Ҫ����ͷ��
                {
                    temp = p2->next;
                    p = p2;//ͷָ�뱻�ı�
                    p2->next = headA;
                    p2 = temp;
                }
                else//�м��
                {
                    temp->next = p2;
                    temp = p2;
                    p2->next = p1;
                    p2 = temp->next;
                }
            }
        }
    }
    return p;//�������ؿ��ܱ��ı��ͷָ��
}


int main()
{
    PNode* headA = NULL;
    PNode* headB = NULL;
    int a, b;
    printf("���������ʽA��������");
    scanf("%d", &a);
    headA = creatPoly(headA, a);
    printf("�������ʽA��");
    Output(headA);
    printf("���������ʽB��������");
    scanf("%d", &b);
    headB = creatPoly(headB, b);
    printf("�������ʽB��");
    Output(headB);


    printf("�����������ʽ��Ӻ�Ľ������ʽA��");
    headA = addPoly(headA, headB);
    if (headA == NULL)
        printf("0 0\n");
    else
        Output(headA);
    return 0;
}
