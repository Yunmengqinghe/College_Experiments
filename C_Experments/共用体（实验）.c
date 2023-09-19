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
}; //������������

struct marriedState
{
    struct date marryDay; //�������
    char spouseName[10]; //��ż����
    int children; //��Ů��
}; //�ѻ�״̬Ա���������

struct divorceState
{
    struct date divorceDay; //�������
    int children;//��Ů��
}; // ���״̬Ա���������

struct marritalState //�������״������������
{
    int marryFlag; //����״����־��1 ��ʾδ�飬2 ��ʾ�ѻ飬3 �����;
    union
    {
        struct marriedState married; //�ѻ�
        struct divorceState divorce; //���
    };
};

struct person //����ְ��������Ϣ�ṹ������
{
    int no;
    char name[10];
    char sex;
    int age;
    struct marritalState marital; //����״��
};

void input(struct person per[],int n);
void output(struct person per[],int n);

int main()
{
    int n;
    printf("������Ա����:");
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
        printf("�������%d��Ա�������� �Ա� ����:",i+1);
        scanf("%s %c %d",per[i].name,&per[i].sex,&per[i].age);
        printf("��ѡ���%d��Ա���Ļ���״̬��Ӧ�ĺ�(1~3):\n1.δ��\n2.�ѻ�\n3.���\n",i+1);
        getchar();
        scanf("%ld",&pending);
        switch(pending)
        {
            case 1:
                per[i].marital.marryFlag=1;
                break;
            case 2:
                per[i].marital.marryFlag=2;
                printf("��������������:");
                getchar();
                scanf("%d %d %d", &per[i].marital.married.marryDay.year,&per[i].marital.married.marryDay.month,&per[i].marital.married.marryDay.day);
                printf("��������ż����:");
                getchar();
                scanf("%s",per[i].marital.married.spouseName);
                printf("�����뺢����:");
                scanf("%d", &per[i].marital.married.children);
                break;
            case 3:
                per[i].marital.marryFlag=3;
                printf("����������������:");
                getchar();
                scanf("%d %d %d", &per[i].marital.divorce.divorceDay.year, &per[i].marital.divorce.divorceDay.month, &per[i].marital.divorce.divorceDay.day);
                printf("�����뺢����:");
                scanf("%d", &per[i].marital.divorce.children);

        }
    }
}

void output(struct person per[],int n)
{

    printf("Ա�����\t����\t�Ա�\t����\t����״̬\t�����������\t��ż����\t������\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%s\t%c\t%d\t", per[i].no, per[i].name, per[i].sex, per[i].age);
        switch(per[i].marital.marryFlag)
        {
            case 1:
                printf("δ��\n");
                break;
            case 2:
                printf("�ѻ�\t\t");
                printf("%d/%d/%d\t", per[i].marital.married.marryDay.year, per[i].marital.married.marryDay.month, per[i].marital.married.marryDay.day);
                printf("%s\t\t", per[i].marital.married.spouseName);
                printf("%d\n", per[i].marital.married.children);
                break;
            case 3:
                printf("����\t\t");
                printf("%d/%d/%d\t", per[i].marital.divorce.divorceDay.year, per[i].marital.divorce.divorceDay.month, per[i].marital.divorce.divorceDay.day);
                printf("\t\t\t");
                printf("%d\n", per[i].marital.divorce.children);
                break;
        }
    }
}
