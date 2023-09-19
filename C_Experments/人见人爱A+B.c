#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n,i;
    int AH,AM,AS;
    int BH,BM,BS;
    int CH,CM,CS;
    int sum,num1,num2;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&AH,&AM,&AS);
            scanf("%d %d %d",&BH,&BM,&BS);
            num1=3600*AH+60*AM+AS;
            num2=3600*BH+60*BM+BS;
            sum=abs(num1+num2);

            CH=sum/3600;
            CM=(sum-3600*CH)/60;
            CS=(sum-3600*CH)%60;

            printf("%d %d %d\n",CH,CM,CS);
        }

    }
    return 0;
}
