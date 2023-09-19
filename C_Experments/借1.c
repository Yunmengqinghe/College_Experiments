#include <stdio.h>
#include <stdlib.h>
void write_to_file(char *c)
{
    FILE *fp;
    if((fp=fopen("char.txt","w"))==NULL)
    {
        printf("Failure to open char.txt\n");
        exit(0);
    }
    fprintf(fp,"%s",c);
    fclose(fp);
}
void read_from_file()
{
    FILE *fp;
    char c[10];
    if((fp=fopen("char.txt","r"))==NULL)
    {
        printf("Failure to open char.txt\n");
        exit(0);
    }
    fscanf(fp,"%s\n",c);
    for(int i=0;i<5;i++)
    printf("%c",c[i]);
    fclose(fp);
}
int main()
{
    char c[10];
    scanf("%s",c);
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]>='a'&&c[i]<='z')
        {
            c[i]=c[i]-32;
        }
    }
    write_to_file(c);
    read_from_file(c);

    return 0;
}

