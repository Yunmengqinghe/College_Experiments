#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
    FILE *in,*out;
    char ch;
    if(argc!=3)
    {
        fprintf(stderr,"输入格式：filecopy 复制文件 目标文件\n");
        exit(EXIT_FAILURE);
    }
    if((in=fopen(argv[1],"rb"))==NULL)
    {
        fprintf(stderr,"打开%s文件失败\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if((out=fopen(argv[2],"wb"))==NULL)
    {
        fprintf(stderr,"打开%s文件失败\n",argv[2]);
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
        printf("读取%s文件失败\n",argv[1]);
    }
    if(ferror(out))
    {
        printf("写入%s文件失败\n",argv[2]);
    }

    printf("成功！\n");
    fclose(in);
    fclose(out);
}
