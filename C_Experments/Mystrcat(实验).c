#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input(char*,char*);
void Mystrcat(char*,char*);

int main()
{
    char s1[1000],s2[1000];
    input(s1,s2);
    Mystrcat(s1,s2);
    puts(s1);
    return 0;
}

void input(char *p,char *q)
{
    gets(p);
    gets(q);
}

void Mystrcat(char *p,char *q)
{
    while(*p++!='\0');
    p--;
    while((*p++=*q++)!='\0');
}
