#include<stdio.h>
#include<math.h>
int main()
{
    int Hour1,minute1,Hour2,minute2,x=0;
    scanf("%d:%d %d:%d",&Hour1,&minute1,&Hour2,&minute2);//以时间形式输入需要计算的时间
    x=fabs(Hour1*60+minute1-Hour2*60+minute2);//将时间统一单位为分钟并将其绝对值存入x这个变量中
    printf("%d:%d",x/60,x%60);//以时间形式输出时差
    return 0;
}
