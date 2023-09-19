#include<stdio.h>
#include<stdlib.h>
int a[15];
void intput();
void find(int n);
void output();

int main()
{
    int n;
    printf("请输入排好序的数组:")；
    input();
    printf("请输入要查找的数:")；
    scanf("%d",&n);
    find(n);
    output();
    return 0;
}
