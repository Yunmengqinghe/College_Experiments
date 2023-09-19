#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int Deck[][13],int len);
void deal(int Deck[][13],char *suit[],char *value[]);
int main()
{
    srand(time(NULL));
    int Deck[4][13];
    int len=sizeof(Deck);
    char *suit[4]={"红桃","方片","草花","黑桃"};
    char *value[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    shuffle(Deck,len);
    deal(Deck,suit,value);
    return 0;
}
void shuffle(int Deck[][13],int len)
{
    int row,column;
    memset(Deck,0,len);
    for(int i=1;i<=52;i++)
    {
        do{
            row=rand()%4;
            column=rand()%13;
        }while(Deck[row][column]!=0);
        Deck[row][column]=i;
    }
}
void deal(int Deck[][13],char *suit[],char *value[])
{
    int row,column;
    printf("       玩家1        玩家2        玩家3        玩家4\n");
    for(int i=1;i<=52;i++)
    {
        for(row=0;row<=3;row++)
        {
            for(column=0;column<=12;column++)
            {
                if(Deck[row][column]==i)
                {
                    printf("%10s%3s",suit[row],value[column]);
                }
            }
        }
        if(i%4==0)
            printf("\n");
    }
}
