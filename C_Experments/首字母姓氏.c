#include<stdio.h>

int main()
{
    char ch;
    printf("��������������ĸ��");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a':
            printf("������");
            break;
        case 'b':
            printf("�ϡ���");
            break;
        case 'c':
            printf("�¡���");
            break;
        case 'd':
            printf("������");
            break;
        case 'e':
            printf("��");
            break;
        default:
            printf("����");
            break;
    }
    return 0;
}
