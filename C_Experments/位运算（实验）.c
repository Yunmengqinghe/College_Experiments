#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
char toBinary();
int judge(char M,int i,char arr[][5]);
char move(char M,int i);
void change(char M);

int main()
{
    int k,t,c;
    char M,jud;
    char arr[][5]={"�ײ�","��","��"};
    srand((unsigned)time(NULL));
    M=toBinary();

    while(1)
    {
        printf("��Ҫ������\n");
        scanf("%c",&jud);
        getchar();
        if(jud=='y')
        {
            k=rand()%3+1;
            switch(k)
            {
                case 1:
                    printf("k=1 ");
                    c=judge(M,k,arr);
                    if(c==1)
                    {
                        printf("ũ���%s�ƶ����԰���״̬�� ",arr[k-1]);
                        M=move(M,k);
                        change(M);
                    }
                    break;

                case 2:
                    printf("k=2 ");
                    c=judge(M,k,arr);
                    if(c==1)
                    {
                        printf("ũ���%s�ƶ����԰���״̬�� ",arr[k-1]);
                        M=move(M,k);
                        change(M);
                    }
                    break;

                case 3:
                    printf("k=3 ");
                    c=judge(M,k,arr);
                    if(c==1)
                    {
                        printf("ũ���%s�ƶ����԰���״̬�� ",arr[k-1]);
                        M=move(M,k);
                        change(M);
                    }
                    break;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

char toBinary()
{
    srand((unsigned)time(NULL));
    char M,N;
    int t=1;
    while(1)
    {
        M=rand()%15+1;
        if(M==3 || (M>=6 && M<=9) || M==12)
        {

        }
        else
        {
            break;
        }
    }
    printf("M��ʼ״̬ʮ���Ʊ�ʾ��%d\n",M);
    printf("M��ʼ״̬�����Ʊ�ʾ��");
    change(M);
    return M;
}

int judge(char M,int i,char arr[][5])
{
    char x=M,y;
    x=x<<(4-i);
    x=x&8;
    y=M&8;
    char c=x^y;
    if(c==0)
    {
        printf("ũ���%s��ͬ��\n",arr[i-1]);
        return 1;
    }
    else
    {
        printf("ũ���%s����ͬ��\n",arr[i-1]);
        return 0;
    }
}

char move(char M,int i)
{
    char b=1;
    b=b<<(i-1);
    b=b|8;
    M=M^b;
    return M;
}

void change(char M)
{
    char b;
    b=1u<<3;
    for(;b;b >>= 1)
    {
      printf("%d",M & b?1:0);
    }
    printf("\n");
}
