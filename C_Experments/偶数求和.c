#include<stdio.h>
void main()
{
	int n,m,he=0,i;
	while(~scanf("%d %d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			if(n%m==0)
			{
				he=i*(i+1)-(i-m)*(i-m+1);   //���õȲ�������͹�ʽ
				if(i==m)
					printf("%d",he/m);
				else
					printf(" %d",he/m);
			}
		}
            if(n%m!=0)  //����m���������
            {
                he=n*(n+1)-(n-n%m)*(n-n%m+1);
                printf(" %d",he/(n%m));
            }
		printf("\n");
	}
}

