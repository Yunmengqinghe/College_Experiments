#include<stdio.h>
#include<math.h>
int main()
{
    int Hour1,minute1,Hour2,minute2,x=0;
    scanf("%d:%d %d:%d",&Hour1,&minute1,&Hour2,&minute2);//��ʱ����ʽ������Ҫ�����ʱ��
    x=fabs(Hour1*60+minute1-Hour2*60+minute2);//��ʱ��ͳһ��λΪ���Ӳ��������ֵ����x���������
    printf("%d:%d",x/60,x%60);//��ʱ����ʽ���ʱ��
    return 0;
}
