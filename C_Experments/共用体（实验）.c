#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
struct date
{
    int year;
    int month;
    int day;
}; //定义日期类型

struct marriedState
{
    struct date marryDay; //结婚日期
    char spouseName[10]; //配偶姓名
    int children; //子女数
}; //已婚状态员工相关数据

struct divorceState
{
    struct date divorceDay; //离婚日期
    int children;//子女数
}; // 离婚状态员工相关数据

struct marritalState //定义婚姻状况公用体类型
{
    int marryFlag; //婚姻状况标志，1 表示未婚，2 表示已婚，3 表离婚;
    union
    {
        struct marriedState married; //已婚
        struct divorceState divorce; //离婚
    };
};

struct person //定义职工个人信息结构体类型
{
    int no;
    char name[10];
    char sex;
    int age;
    struct marritalState marital; //婚姻状况
};

void input(struct person per[],int n);
void output(struct person per[],int n);

int main()
{
    int n;
    printf("请输入员工数:");
    scanf("%d",&n);
    struct person per[n];
    input(per,n);
    output(per,n);
    return 0;
}

void input(struct person per[],int n)
{
    long pending;
    for(int i=0;i<n;i++)
    {
        per[i].no=i+1;
        printf("请输入第%d个员工的姓名 性别 年龄:",i+1);
        scanf("%s %c %d",per[i].name,&per[i].sex,&per[i].age);
        printf("请选择第%d个员工的婚姻状态对应的号(1~3):\n1.未婚\n2.已婚\n3.离婚\n",i+1);
        getchar();
        scanf("%ld",&pending);
        switch(pending)
        {
            case 1:
                per[i].marital.marryFlag=1;
                break;
            case 2:
                per[i].marital.marryFlag=2;
                printf("请输入结婚年月日:");
                getchar();
                scanf("%d %d %d", &per[i].marital.married.marryDay.year,&per[i].marital.married.marryDay.month,&per[i].marital.married.marryDay.day);
                printf("请输入配偶姓名:");
                getchar();
                scanf("%s",per[i].marital.married.spouseName);
                printf("请输入孩子数:");
                scanf("%d", &per[i].marital.married.children);
                break;
            case 3:
                per[i].marital.marryFlag=3;
                printf("请输入离异年月日:");
                getchar();
                scanf("%d %d %d", &per[i].marital.divorce.divorceDay.year, &per[i].marital.divorce.divorceDay.month, &per[i].marital.divorce.divorceDay.day);
                printf("请输入孩子数:");
                scanf("%d", &per[i].marital.divorce.children);

        }
    }
}

void output(struct person per[],int n)
{

    printf("员工编号\t姓名\t性别\t年龄\t婚姻状态\t结婚或离婚日期\t配偶姓名\t孩子数\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%s\t%c\t%d\t", per[i].no, per[i].name, per[i].sex, per[i].age);
        switch(per[i].marital.marryFlag)
        {
            case 1:
                printf("未婚\n");
                break;
            case 2:
                printf("已婚\t\t");
                printf("%d/%d/%d\t", per[i].marital.married.marryDay.year, per[i].marital.married.marryDay.month, per[i].marital.married.marryDay.day);
                printf("%s\t\t", per[i].marital.married.spouseName);
                printf("%d\n", per[i].marital.married.children);
                break;
            case 3:
                printf("离异\t\t");
                printf("%d/%d/%d\t", per[i].marital.divorce.divorceDay.year, per[i].marital.divorce.divorceDay.month, per[i].marital.divorce.divorceDay.day);
                printf("\t\t\t");
                printf("%d\n", per[i].marital.divorce.children);
                break;
        }
    }
}
