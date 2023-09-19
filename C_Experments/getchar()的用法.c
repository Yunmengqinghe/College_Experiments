#include<stdio.h>
#include<stdlib.h>
int main()
{
    char arr;
    int a=0,b=0,c=0,d=0,len,i;
    while((arr=getchar())!='\n')
    {
            if((arr>='A'&&arr<='Z')||(arr>='a'&&arr<='z'))
            {
                a++;
            }
            else if(arr>='1'&&arr<='9')
            {
                b++;
            }
            else if(arr==' ')
            {
                c++;
            }
            else
            {
                d++;
            }
    }
    printf("%d %d %d %d\n",a,b,c,d);
    return 0;
}
