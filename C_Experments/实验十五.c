#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct PNode//多项式节点
{
    float coef;//系数
    int expn;//指数    //数据域
    struct PNode* next;
} PNode;

/*
函数功能：输入节点并插入链表
入口参数：头指针，要创建的节点数
返回值：可能被更改的头指针
*/
PNode* creatPoly(PNode* head, int n)
{
    printf("请输入多项式各项的系数与指数：");
    while (n--)
    {
        PNode* p = NULL, * pr = head, * temp = NULL;//p指向新开辟的节点，pr用来遍历链表，temp用来记忆pr的位置
        p = (PNode*)malloc(sizeof(PNode));
        p->next = NULL;
        scanf("%f", &p->coef);
        scanf("%d", &p->expn);
        if (head == NULL)//如果为空链表
        {
            head = p;//那就是头节点
        }
        else
        {
            while (pr->expn < p->expn && pr->next != NULL)
            {
                temp = pr;//保存当前节点的位置
                pr = pr->next;//让pr指向下一个节点
            }
            if (pr->expn >= p->expn)//插入的元素不在表尾
            {
                if (pr == head)//若在头节点之前插入新节点
                {
                    p->next = head;
                    head = p;
                }
                else//在中间插入
                {
                    pr = temp;
                    p->next = pr->next;//将新节点的指针域指向下一节点
                    pr->next = p;
                }
            }
            else//若插入的元素在表尾
            {
                pr->next = p;
            }
        }
    }
    return head;
}

/*
函数功能：遍历并输出链表内容
入口参数：头指针
返回值：无
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
    PNode* temp = headA;//给记忆器temp赋值头指针的含义在多项式A的指数大于B的指数中有提及

    p1 = p = headA;
    p2 = headB;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expn == p2->expn)//指数相等时
        {
            if (p1->coef + p2->coef != 0)//同类项不能相消时
            {
                p1->coef += p2->coef;//系数相加

                temp = p2;//p2指向多项式B的下一项，temp删除用完的上一项
                p1 = p1->next;
                p2 = p2->next;
                free(temp);
            }
            else//同类项能相消时仍需考虑三种情况
            {
                if (p1 == p)//头删
                {
                    temp = p1;
                    p1 = p1->next;
                    free(temp);
                    temp = p2;
                    p2 = p2->next;
                    free(temp);
                    if (p1 != NULL)
                        p = p1;//此时头指针已被改变
                    else//进这个else说明多项式A被删没了
                        p = p2;
                }
                else if (p1->next == NULL)//尾删
                {
                    temp = p;
                    while (temp->next != p1)
                    {
                        temp = temp->next;//先让temp找到p1的前一项
                    }
                    temp->next = p2->next;
                    temp = p1;
                    p1 = p1->next;
                    free(temp);
                    temp = p2;
                    p2 = p2->next;
                    free(temp);
                }
                else//中间删
                {
                    temp = p;
                    while (temp->next != p1)
                    {
                        temp = temp->next;//先让temp找到p1的前一项
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
            if (p1->expn < p2->expn)//多项式A的指数小于B的指数
            {
                while (p1->expn < p2->expn && p1 != NULL)
                {
                    temp = p1;
                    p1 = p1->next;
                    if (p1->expn == p2->expn)//直接跳出执行指数相等的操作
                        break;
                    else if (p1->expn > p2->expn)
                    {
                        temp->next = p2;
                        temp = p2->next;//记忆
                        p2->next = p1;
                        p2 = temp;
                    }
                }
                if (p1 == NULL)
                {
                    p1 = temp;//p1回溯
                    p1->next = p2;
                    return p;//即可直接结束
                }
            }
            else//多项式A的指数大于B的指数
            {
                if (temp == headA)//说明需要进行头插
                {
                    temp = p2->next;
                    p = p2;//头指针被改变
                    p2->next = headA;
                    p2 = temp;
                }
                else//中间插
                {
                    temp->next = p2;
                    temp = p2;
                    p2->next = p1;
                    p2 = temp->next;
                }
            }
        }
    }
    return p;//别忘返回可能被改变的头指针
}


int main()
{
    PNode* headA = NULL;
    PNode* headB = NULL;
    int a, b;
    printf("请输入多项式A的项数：");
    scanf("%d", &a);
    headA = creatPoly(headA, a);
    printf("输出多项式A：");
    Output(headA);
    printf("请输入多项式B的项数：");
    scanf("%d", &b);
    headB = creatPoly(headB, b);
    printf("输出多项式B：");
    Output(headB);


    printf("输出两个多项式相加后的结果多项式A：");
    headA = addPoly(headA, headB);
    if (headA == NULL)
        printf("0 0\n");
    else
        Output(headA);
    return 0;
}
