#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void sta(int count);
int pend(int r1,int r2,int n,char c);
int judge(int r1,int r2);

int main()
{
    int a;
    while(~scanf("%d",&a))
    {
        switch(a)
        {
            case 1:
            task_1();
            break;

            case 2:
            task_2();
            break;

            case 3:
            task_3();
            break;

            case 4:
            task_4();
            break;

            case 5:
            task_5();
            break;
        }

    }
    return 0;
}

void task_1()
{
    srand(time(0));
    int r1,r2;
    int i,n;
    printf("第一个实验\n");
    do
    {
        r1=rand()%10+1;
        r2=rand()%10+1;
        printf("%dX%d=?请输入你的答案:",r1,r2);
        scanf("%d",&n);
    }while(n!=r1*r2);
    printf("结束了\n");

}

void task_2()
{
    srand(time(0));
    int r1,r2;
    int i,n,count;
    printf("第二个实验\n");
    count=0;
    do
    {
        r1=rand()%10+1;
        r2=rand()%10+1;
        printf("%dX%d=?请输入你的答案:",r1,r2);
        scanf("%d",&n);
        count++;
        if(count==3)
        {
            break;
        }
    }while(n!=r1*r2);
    printf("结束了\n");
}

void task_3()
{
    srand(time(0));
    int r1,r2;
    int i,n,count,p=0;
    printf("第三个实验\n");
    count=0;
    for(i=1;i<=10;i++)
    {
        r1=rand()%10+1;
        r2=rand()%10+1;
        printf("%dX%d=?请输入你的答案:",r1,r2);
        scanf("%d",&n);
        p=pend(r1,r2,n,'*');
        if(p==1)
        {
            count++;
        }

    }
    sta(count);
}

void task_4()
{
    srand(time(0));
    int r1,r2,r3;
    int i,j,n,m,o,p,count;
    printf("第四个实验\n");
    count=0;
    for(i=1;i<=10;i++)
    {
        r3=rand()%4+1;
        r1=rand()%10+1;
        r2=rand()%10+1;
        switch(r3)
        {
            case 1:
                printf("%d+%d=?请输入你的答案:",r1,r2);
                scanf("%d",&n);
                p=pend(r1,r2,n,'+');
                if(p==1)
                {
                    count++;
                }
                break;

            case 2:
                printf("%d-%d=?请输入你的答案:",r1,r2);
                scanf("%d",&n);
                p=pend(r1,r2,n,'-');
                if(p==1)
                {
                    count++;
                }
                break;

            case 3:
                printf("%dX%d=?请输入你的答案:",r1,r2);
                scanf("%d",&n);
                p=pend(r1,r2,n,'*');
                if(p==1)
                {
                    count++;
                }
                break;

            case 4:
                o=1;
                for(j=1;j<=o;j++)
                {
                    r1=rand()%10+1;
                    r2=rand()%10+1;
                    m=judge(r1,r2);
                    if(m==1)
                    {
                        printf("%d/%d=?请输入你的答案:",r1,r2);
                        scanf("%d",&n);
                        p=pend(r1,r2,n,'/');
                        if(p==1)
                        {
                            count++;
                        }
                    }
                    else
                    {
                       o++;
                    }
                }
                break;

        }
    }
    sta(count);
    printf("结束了\n");

}

void task_5()
{
    srand(time(0));
    int r1,r2,r3,o;
    int i,n,m,j,k,p,l,count;
    printf("第五个实验\n");
    k=1;
    for(j=1;j<=k;j++)
    {
        count=0;
        for(i=1;i<=10;i++)
        {
            r1=rand()%10+1;
            r2=rand()%10+1;
            r3=rand()%4+1;
            switch(r3)
            {
                case 1:
                    printf("%d+%d=?请输入你的答案:",r1,r2);
                    scanf("%d",&n);
                    p=pend(r1,r2,n,'+');
                    if(p==1)
                    {
                        count++;
                    }
                    break;

                case 2:
                    printf("%d-%d=?请输入你的答案:",r1,r2);
                    scanf("%d",&n);
                    p=pend(r1,r2,n,'-');
                    if(p=1)
                    {
                        count++;
                    }
                    break;

                case 3:
                    printf("%dX%d=?请输入你的答案:",r1,r2);
                    scanf("%d",&n);
                    p=pend(r1,r2,n,'*');
                    if(p==1)
                    {
                        count++;
                    }
                    break;

                case 4:
                    o=1;
                    for(j=1;j<=o;j++)
                    {
                        r1=rand()%10+1;
                        r2=rand()%10+1;
                        m=judge(r1,r2);
                        if(m==1)
                        {
                            printf("%d/%d=?请输入你的答案:",r1,r2);
                            scanf("%d",&n);
                            p=pend(r1,r2,n,'/');
                            if(p==1)
                            {
                                count++;
                            }
                        }
                        else
                        {
                           o++;
                        }
                    }
                    break;

            }
        }
        if(count*10<75)
        {
            k++;
            printf("重来\n");
        }
        sta(count);
    }
}
void sta(int count)
{
    int m;
    m=count*10;
    printf("分数:%d\n正确率:%d%%\n",m,m);
}

int pend(int r1,int r2,int n,char c)
{
    int count=0;
    switch(c)
    {
        case '+':
        if(n==r1+r2)
        {
            printf("正确\n");
            count=1;
        }
        else
        {
            printf("错误\n");
            count=0;
        }
        break;

        case '-':
        if(n==r1-r2)
        {
            printf("正确\n");
            count=1;
        }
        else
        {
            printf("错误\n");
            count=0;
        }
        break;

        case '*':
        if(n==r1*r2)
        {
            printf("正确\n");
            count=1;
        }
        else
        {
            printf("错误\n");
            count=0;
        }
        break;

        case '/':
            if(n==r1/r2)
        {
            printf("正确\n");
            count=1;
        }
        else
        {
            printf("错误\n");
            count=0;
        }
        break;
    }
    return count;
}
int judge(int r1,int r2)
{
    int count=0;
    if(r1>r2&&r1%r2==0&&r2!=0)
    {
        count=1;
    }
    else
    {
        count=0;
    }
    return count;
}

