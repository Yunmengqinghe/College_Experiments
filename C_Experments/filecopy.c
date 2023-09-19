#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
    FILE *in,*out;
    char ch;
    if(argc!=3)
    {
        fprintf(stderr,"�����ʽ��filecopy �����ļ� Ŀ���ļ�\n");
        exit(EXIT_FAILURE);
    }
    if((in=fopen(argv[1],"rb"))==NULL)
    {
        fprintf(stderr,"��%s�ļ�ʧ��\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if((out=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"��%s�ļ�ʧ��\n",argv[2]);
        fclose(in);
        exit(EXIT_FAILURE);
    }

    while((ch=getc(in))!=EOF)
    {
        if(putc(ch,out)==EOF)
        {
            break;
        }
    }
    if(ferror(in))
    {
        printf("��ȡ%s�ļ�ʧ��\n",argv[1]);
    }
    if(ferror(out))
    {
        printf("д��%s�ļ�ʧ��\n",argv[2]);
    }

    printf("�ɹ���\n");
    fclose(in);
    fclose(out);
}
