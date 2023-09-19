#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
    srand(time(0));
    int r1,r2,r3;
    int i,j,k,l,a,b,c;
    int n,m,marks;
    double persent;

//第一个任务
    j=1,k=0;
    for(i=0;i<j;i++)
    {
        r1=rand()%10,r2=rand()%10;
        printf("%d*%d=?\nplease input your answer:",r1,r2);
        scanf("%d",&c);
            if(c==r1*r2)
            {
                printf("right\n");
            }
            else
            {
                printf("wrong!please try again.\n");
                j++;
            }
    }
    j=1,k=0;

//第二个任务
    j=1,k=0;
    for(i=0;i<j;i++)
    {
        r1=rand()%10,r2=rand()%10;
        printf("%d*%d=?\nplease input your answer:",r1,r2);
        scanf("%d",&c);
        if(c==r1*r2)
        {
            printf("right\n");
        }
        else
        {
            k++;
            if(k<=2)
            {
                j++;
                printf("wrong!please try again.\n");
            }

            if(k==3)
            {
                printf("wrong!you have tried three times!test over!\n");
                exit(0);
            }
        }
    }

//第三个任务
    marks=0,persent=0;
    for(i=1;i<=10;i++)
    {
        r1=rand()%10,r2=rand()%10;
        printf("%d*%d=?\nPlease input your answer:",r1,r2);
        scanf("%d",&c);
        if(c==r1*r2)
        {
            marks++;
            persent++;
            printf("right\n");
        }

        if(i==10)
        {
            printf("%d\n",marks*10);
            printf("%d%%\n",persent*100);
        }
    }
    marks=0,persent=0;

//第四个任务
    for(i=1;i<=10;i++)
    {
       r1=rand()%10,r2=rand()%10,r3=rand()%100;
       if(r3>=0&&r3<25)
       {
           printf("%d+%d=?\nPlease input your answer:",r1,r2);
           scanf("%d",&c);

           if(c==r1+r2)
           {
               printf("Right!\n");
               marks++;
               persent++;
           }
           else
           {
               printf("Wrong!");
           }
       }
       else if(r3>=25&&r3<50)
       {
           printf("%d-%d=?\nPlease input your answer:",r1,r2);
           scanf("%d",&c);

           if(c==r1-r2)
           {
               printf("Right!\n");
               marks++;
               persent++;
           }
           else
           {
               printf("Wrong!\n");
           }
       }
       else if(r3>=50&&r3<75)
       {
           printf("%d*%d=?\nPlease input your answer:",r1,r2);
           scanf("%d",&c);

           if(c==r1*r2)
           {
               printf("Right!\n");
               marks++;
               persent++;
           }
           else
           {
               printf("Wrong!\n");
           }
       }
       else if(r3>=75&&r3<100)
       {

           printf("%d/%d=?\nPlease input your answer:",r1,r2);
           scanf("%d",&c);

           if(c==r1/r2)
           {
               printf("Right!\n");
               marks++;
               persent++;
           }
           else
           {
               printf("Wrong!\n");
           }
       }

    }
            printf("%d\n",marks*10);
            printf("%.2lf%%\n",persent*10);
            marks=0,persent=0;

//第五个任务
        m=1,marks=0,persent=0;
        for(n=1;n<=m;n++)
        {
                for(i=1;i<=10;i++)
                {
                   r3=rand()%100;

                   if(r3>=0&&r3<25)
                   {
                       r1=rand()%10,r2=rand()%10;
                       printf("%d+%d=?\nPlease input your answer:",r1,r2);
                       scanf("%d",&c);

                       if(c==r1+r2)
                       {
                           printf("Right!\n");
                           marks++;
                           persent++;
                       }
                       else
                       {
                           printf("Wrong!");
                       }
                   }
                       else if(r3>=25&&r3<50)
                       {
                           r1=rand()%10,r2=rand()%10;
                           printf("%d-%d=?\nPlease input your answer:",r1,r2);
                           scanf("%d",&c);

                           if(c==r1-r2)
                           {
                               printf("Right!\n");
                               marks++;
                               persent++;
                           }
                           else
                           {
                               printf("Wrong!\n");
                           }
                       }

                           else if(r3>=50&&r3<75)
                           {
                               r1=rand()%10,r2=rand()%10;
                               printf("%d*%d=?\nPlease input your answer:",r1,r2);
                               scanf("%d",&c);

                               if(c==r1*r2)
                               {
                                   printf("Right!\n");
                                   marks++;
                                   persent++;
                               }
                               else
                               {
                                   printf("Wrong!\n");
                               }
                           }

                                   else if(r3>=75&&r3<100)
                                   {
                                       l=1;
                                       for(j=1;j<=l;j++)
                                       {
                                           r1=rand()%10,r2=rand()%10;
                                           if(r1<r2||r2==0||r1%r2!=0)
                                           {
                                               l++;
                                           }
                                       }
                                       printf("%d/%d=?\nPlease input your answer:",r1,r2);
                                       scanf("%d",&c);

                                       if(c==r1/r2)
                                       {
                                           printf("Right!\n");
                                           marks++;
                                           persent++;
                                       }
                                       else
                                       {
                                           printf("Wrong!\n");
                                       }
                                   }

                                }
                        printf("%d\n",marks*10);
                        printf("%.2lf%%\n",persent*10);
                        if(persent<7.5)
                        {
                            printf("\n");
                            m++;
                        }
                        marks=0,persent=0;



        }
        return 0;
}
