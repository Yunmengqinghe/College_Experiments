#include<stdio.h>
int main()
{
    int n,count=0;
    double a=0.0,b=0.0,c=0.0,d=0.0,m;
    scanf("%d",&n);
    while(count<n)
    {
       scanf("%lf",&m);

       if(0<=m&&m<=18)
       a+=1;
       else if(19<=m&&m<=35)
       b+=1;
       else if(36<=m&&m<=60)
       c+=1;
       else if(m>=61)
       d+=1;
       count++;
    }
    double a1,a2,a3,a4;
    a1=a/n*100.00;
    a2=b/n*100.00;
    a3=c/n*100.00;
    a4=d/n*100.00;
    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%",a1,a2,a3,a4);//try again

}
