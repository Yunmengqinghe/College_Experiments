#include<stdio.h>

int main()
{
    char ch;
    printf("请输入姓氏首字母：");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a':
            printf("安、艾");
            break;
        case 'b':
            printf("毕、白");
            break;
        case 'c':
            printf("陈、常");
            break;
        case 'd':
            printf("丁、党");
            break;
        case 'e':
            printf("鄂");
            break;
        default:
            printf("其他");
            break;
    }
    return 0;
}
