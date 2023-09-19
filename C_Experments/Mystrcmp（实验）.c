#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void input(char*,char*);
int Mystrcmp(char*,char*);

int main()
{
    char s1[1000],s2[1000];
    int t;
    input(s1,s2);
    t=Mystrcmp(s1,s2);
    printf("%d",t);
    return 0;
}

void input(char *p,char *q)
{
    gets(p);
    gets(q);
}

int Mystrcmp(char *p,char *q)
{
    while(*p==*q)
    {
        if(*p=='\0')
        {
            return 0;
        }
        p++;
        q++;
    }
    return *p-*q;
}
