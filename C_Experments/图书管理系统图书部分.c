#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Point1
{
    int point1;
    int point2;
    int point3;
};

typedef struct Books
{
    int number;
    char name[15];
    char writer[15];
    char publish[15];
    int haveNumber;
    int alNumber;
    struct Point1 point;
}books;

struct Point2
{
    int point;
    int length;
};

typedef struct NameIndex
{
    char name[20];
    struct Point2 pointer;
}nameindex;

typedef struct WriterIndex
{
    char name[20];
    struct Point2 pointer;
}writerindex;

typedef struct PubIndex
{
    char name[20];
    struct Point2 pointer;
}pubindex;

void uiShow4();
void uiShow5();

int bookManager(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen);
int findBooks(books main[],int sel,int n);
void sortBooks(books main[],nameindex name[],writerindex writer[],pubindex pub[],int len);

void outputInformation(books main[],int i);
void outputAll(books main[],int len);

void readFromfile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen);
void writeTofile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int len,int nlen,int wlen,int plen);

int main()
{
    int sel=0,flag=0,pend=0,n=10;
    int len=-1,nlen=-1,wlen=-1,plen=-1;
    books main[n];
    nameindex name[n];
    writerindex writer[n];
    pubindex pub[n];

    readFromfile1(main,name,writer,pub,&len,&nlen,&wlen,&plen);
    while(1)
    {
        pend=bookManager(main,name,writer,pub,&len,&nlen,&wlen,&plen);
        if(pend==1)
        {
            writeTofile1(main,name,writer,pub,len,nlen,wlen,plen);
            break;
        }

    }
    return 0;
}

void uiShow4()
{
    printf("******************\n");
    printf("  1.ͼ����Ϣ����\n");
    printf("  2.ͼ����Ϣ�޸�\n");
    printf("  3.ͼ����Ϣ��ѯ\n");
    printf("  4.����ͳ��\n");
    printf("  5.�������˵�\n");
    printf("******************\n");
    printf("��Ҫѡ��Ĺ���:");
}

void uiShow5()
{
    printf("******************\n");
    printf("  1.����Ų�ѯ\n");
    printf("  2.��������ѯ\n");
    printf("  3.�����߲�ѯ\n");
    printf("  4.���������ѯ\n");
    printf("  5.�������˵�\n");
    printf("******************\n");
    printf("��Ҫѡ��Ĺ���:");
}

int bookManager(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen)
{
    uiShow4();
    int sel=0,pend=0,temp=0,r=0,n=10;

    scanf("%d",&sel);
    printf("\n");

    switch(sel)
    {
        case 1:
            (*len)++;
            printf("���������:");
            scanf("%d",&main[*len].number);
            printf("����������:");
            scanf("%s",main[*len].name);
            printf("������������:");
            scanf("%s",main[*len].writer);
            printf("�����������:");
            scanf("%s",main[*len].publish);
            printf("�����������:");
            scanf("%d",&main[*len].haveNumber);
            printf("����������:");
            scanf("%d",&main[*len].alNumber);
            printf("\n");

            main[*len].point.point1=0;
            main[*len].point.point2=0;
            main[*len].point.point3=0;
            break;
        case 2:
            printf("������Ҫ�޸ĵ����:");
            scanf("%d",&temp);
            for(int i=0;i<=*len;i++)
            {
                if(main[i].number==temp)
                {
                    printf("1.�޸Ĳ�����\n2.�޸Ľ����\n\n");
                    printf("��ѡ��Ҫʵ�ֵĹ���:");
                    scanf("%d",&sel);
                    switch(sel)
                    {
                        case 1:
                            printf("���������:");
                            scanf("%d",&main[i].haveNumber);
                            break;
                        case 2:
                            printf("��������:");
                            scanf("%d",&main[i].alNumber);
                            break;
                        default:
                            break;
                    }
                    break;
                }
            }
            printf("�޸ĳɹ�\n\n");
            break;
        case 3:
            while(1)
            {
                uiShow5();
                scanf("%d",&sel);
                printf("\n");
                pend=findBooks(main,sel,*len);
                if(pend==1)
                {
                    break;
                }
            }
            break;
        case 4:
            for(int i=0;i<=*len-1;i++)
            {
                for(int j=0;j<=*len-1-i;j++)
                {
                    books tmp;
                    if(main[j].number>main[j+1].number)
                    {
                        tmp=main[j];
                        main[j]=main[j+1];
                        main[j+1]=tmp;
                    }
                }
            }

            for(int i=0;i<=*len;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(strcmp(main[i].name,main[j].name)==0)
                    {
                        main[i].point.point1=j+1;
                    }

                    if(strcmp(main[i].writer,main[j].writer)==0)
                    {
                        main[i].point.point2=j+1;
                    }

                    if(strcmp(main[i].publish,main[j].publish)==0)
                    {
                        main[i].point.point3=j+1;
                    }
                }
            }
            printf("---------------------------------------------------------------------------------------------\n");
            printf(" ��¼��    ���    ����        ����    ������    ������    �����    ָ��1    ָ��2    ָ��3\n");
            for(int i=0;i<=*len;i++)
            {
                printf(" %-10d%-8d%-12s%-8s%-10s%-10d%-10d%-9d%-9d%-8d\n",i+1,main[i].number,main[i].name,main[i].writer,
                   main[i].publish,main[i].haveNumber,main[i].alNumber,main[i].point.point1,main[i].point.point2,
                   main[i].point.point3);
            }
            printf("---------------------------------------------------------------------------------------------\n\n");


            for(int i=0;i<=*len;i++)
            {
                int pend=1,p=0,l=0;
                for(int j=0;j<=*nlen;j++)
                {
                    if(strcmp(main[i].name,name[j].name)==0)
                    {
                        pend=0;
                    }
                }
                if(pend==1)
                {

                    for(int j=i+1;j<=*len;j++)
                    {
                        if(strcmp(main[i].name,main[j].name)==0)
                        {
                            p=j+1;
                            l++;
                        }
                    }
                    (*nlen)++;
                    strcpy(name[*nlen].name,main[i].name);
                    name[*nlen].pointer.point=p;
                    name[*nlen].pointer.length=l;
                }
            }

            printf("------------------------------\n");
            printf("   ����    ��ͷָ��    ����\n");
            printf("------------------------------\n");
            for(int i=0;i<=*nlen;i++)
            {
                printf(" %-10s%-12d%-7d\n",name[i].name,name[i].pointer.point,name[i].pointer.length);
            }
            printf("------------------------------\n\n");

            for(int i=0;i<=*len;i++)
            {
                int pend=1,p=0,l=0;
                for(int j=0;j<=*wlen;j++)
                {
                    if(strcmp(main[i].writer,writer[j].name)==0)
                    {
                        pend=0;
                    }
                }
                if(pend==1)
                {

                    for(int j=i+1;j<=*len;j++)
                    {
                        if(strcmp(main[i].writer,main[j].writer)==0)
                        {
                            p=j+1;
                            l++;
                        }
                    }
                    (*wlen)++;
                    strcpy(writer[*wlen].name,main[i].writer);
                    writer[*wlen].pointer.point=p;
                    writer[*wlen].pointer.length=l;
                }
            }

            printf("------------------------------\n");
            printf("  ������    ��ͷָ��    ����\n");
            printf("------------------------------\n");
            for(int i=0;i<=*wlen;i++)
            {
                printf(" %-10s%-12d%-6d\n",writer[i].name,writer[i].pointer.point,writer[i].pointer.length);
            }
            printf("------------------------------\n\n");

            for(int i=0;i<=*len;i++)
            {
                int pend=1,p=0,l=0;
                for(int j=0;j<=*plen;j++)
                {
                    if(strcmp(main[i].publish,pub[j].name)==0)
                    {
                        pend=0;
                    }
                }
                if(pend==1)
                {

                    for(int j=i+1;j<=*len;j++)
                    {
                        if(strcmp(main[i].publish,main[j].publish)==0)
                        {
                            p=j+1;
                            l++;
                        }
                    }
                    (*plen)++;
                    strcpy(pub[*plen].name,main[i].publish);
                    pub[*plen].pointer.point=p;
                    pub[*plen].pointer.length=l;
                }
            }

            printf("------------------------------\n");
            printf("  ������    ��ͷָ��    ����\n");
            printf("------------------------------\n");
            for(int i=0;i<=*plen;i++)
            {
                printf(" %-10s%-12d%-6d\n",pub[i].name,pub[i].pointer.point,pub[i].pointer.length);
            }
            printf("------------------------------\n\n");
            break;
        case 5:
            return 1;
            break;
    }
    return 0;
}

int findBooks(books main[],int sel,int len)
{
    int temp,r;
    char bookTemp[20],writerTemp[20],pubTemp[20];
    switch(sel)
    {
        case 1:
            printf("���������:");
            scanf("%d",&temp);
            if(main[len/2].number>=temp)
            {
                for(int i=len/2;i<=len;i++)
                {
                    if(temp==main[i].number)
                        r=i;
                }
            }
            else
            {
                for(int i=len/2;i>=0;i--)
                {
                    if(temp==main[i].number)

                        r=i;
                }
            }
            outputInformation(main,r);
            break;
        case 2:
            printf("����������:");
            scanf("%s",bookTemp);
            for(int i=0;i<=len;i++)
            {
                if(strcmp(bookTemp,main[i].name)==0)
                {
                    outputInformation(main,i);
                }
            }
            break;
        case 3:
            printf("����������:");
            scanf("%s",writerTemp);
            for(int i=0;i<=len;i++)
            {
                if(strcmp(writerTemp,main[i].writer)==0)
                {
                    outputInformation(main,i);
                }
            }
            break;
        case 4:
            printf("�����������:");
            scanf("%s",pubTemp);
            for(int i=0;i<=len;i++)
            {
                if(strcmp(pubTemp,main[i].publish)==0)
                {
                    outputInformation(main,i);
                }
            }
            break;
        case 5:
            return 1;
            break;
        default:
            break;
    }
}

void outputInformation(books main[],int i)
{
    printf("---------------------------------------------------------\n");
    printf(" ���    ����        ����    ������    ������    �����\n");
    printf(" %-8d%-12s%-8s%-10s%-10d%-8d\n",main[i].number,main[i].name,main[i].writer,
           main[i].publish,main[i].haveNumber,main[i].alNumber);
    printf("---------------------------------------------------------\n\n");
}

void readFromfile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int *len,int *nlen,int *wlen,int *plen)
{
    FILE *fp1,*fp2,*fp3,*fp4;
    if((fp1=fopen("main.txt","r"))==NULL||(fp2=fopen("name.txt","r"))==NULL||(fp3=fopen("writer.txt","r"))==NULL||(fp4=fopen("publish.txt","r"))==NULL)
    {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }

    getc(fp1);getc(fp2);getc(fp3);getc(fp4);
    if(feof(fp1)||feof(fp2)||feof(fp3)||feof(fp4))
    {
        fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);
    }
    else
    {
        rewind(fp1);rewind(fp2);rewind(fp3);rewind(fp4);
        while(!feof(fp1))
        {
            (*len)++;
            fscanf(fp1,"%d %s %s %s %d %d ",&main[*len].number,main[*len].name,main[*len].writer,
               main[*len].publish,&main[*len].haveNumber,&main[*len].alNumber);
        }
        while(!feof(fp2))
        {
            (*nlen)++;
            fscanf(fp2,"%s %d %d ",name[*nlen].name,&name[*nlen].pointer.point,&name[*nlen].pointer.length);
        }
        while(!feof(fp3))
        {
            (*wlen)++;
            fscanf(fp3,"%s %d %d ",writer[*wlen].name,&writer[*wlen].pointer.point,&writer[*wlen].pointer.length);
        }
        while(!feof(fp4))
        {
            (*plen)++;
            fscanf(fp4,"%s %d %d ",pub[*plen].name,&pub[*plen].pointer.point,&pub[*plen].pointer.length);
        }
    }
    fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);
}

void writeTofile1(books main[],nameindex name[],writerindex writer[],pubindex pub[],int len,int nlen,int wlen,int plen)
{
    printf("%d %d %d %d\n",len,nlen,wlen,plen);
    FILE *fp1,*fp2,*fp3,*fp4;
    if((fp1=fopen("main.txt","w"))==NULL||(fp2=fopen("name.txt","w"))==NULL||(fp3=fopen("writer.txt","w"))==NULL||(fp4=fopen("publish.txt","w"))==NULL)
    {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }

    for(int i=0;i<=len;i++)
    {
        fprintf(fp1,"%d %s %s %s %d %d ",main[i].number,main[i].name,main[i].writer,
           main[i].publish,main[i].haveNumber,main[i].alNumber);
    }
    for(int i=0;i<=nlen;i++)
    {
        fprintf(fp2,"%s %d %d ",name[i].name,name[i].pointer.point,name[i].pointer.length);
    }
    for(int i=0;i<=wlen;i++)
    {
        fprintf(fp3,"%s %d %d ",writer[i].name,writer[i].pointer.point,writer[i].pointer.length);
    }
    for(int i=0;i<=plen;i++)
    {
        fprintf(fp4,"%s %d %d ",pub[i].name,pub[i].pointer.point,pub[i].pointer.length);
    }
    fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);
}
