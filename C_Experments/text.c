#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200

struct Student
{
	char num[20];		// ѧ��
	char name[50];		// ����
	double score[6];	// 6�ſεĳɼ�
	double total;		// �ܷ�
	double Average;         //ƽ����

}person;
char filename[20];

// ѧ�����飬������ѧ������ĳ��ȶ��峤һ��
struct Student stuList[N];

// ��ʵ��ѧ����Ŀ
int count = 0;

// �˵�
void menu()
{
	puts("=======================================");
    puts("1���ɼ���¼�������");
	puts("2��ɾ��");
	puts("3�������ܷ�");
	puts("4������ƽ����");
	puts("5�����ܷ�����");	// ����ѧ�����ܷ֣��Խṹ�����������
	puts("6��������ļ�");
	puts("7���������Ļ");
	puts("8�������Ļ");
	puts("9���˳�����");
	puts("=======================================");
}

void seachMenu()
{
	puts("=======================================");
	puts("1������ѧ������");
	puts("2��������������");
	puts("3���˳�");
	puts("=======================================");
}

void functionMenu()
{
    puts("=======================================");
	puts("1��ѧ����Ϣ�ļ�����");
	puts("2��ѧ����Ϣ������");
	puts("3���˳�");
	puts("=======================================");

}

void createListFromFile();		// ���ļ��ж�ȡѧ���ĳɼ�����
void calTotal();				// �����ܷ�
void average();                 // ����ƽ����
void sortListByScore();			// ���ܳɼ�������������ѡ�񷨡�
void outputToFile();			// ������������ļ�
void outputToScreen();			// �������������Ļ
void addScore();                // �ɼ���¼�������
void deleteDate();              // ɾ��

void searchBynum();             // ͨ��ѧ������ѧ��
void searchByname();            // ͨ����������ѧ��

void filepartSelect();
void searchpartSelect();

int main()
{
    char menuId;
    while (1)
	{
        functionMenu();
        menuId = getchar();
        getchar();
        switch(menuId)
        {
            case '1':
                createListFromFile();
                filepartSelect();
                break;
            case '2':
                seachMenu();
                break;
            default:
                break;
        }
	}
	return 0;
}

// ���ļ��ж�ȡѧ���ĳɼ�����
void createListFromFile()
{
    FILE *fp;
	char filename[10];
	while(1)
    {
        printf("\n�������������ڵ��ļ���:");
        gets(filename); // 1.txt


        if((fp = fopen(filename, "r")) == NULL)
        {
            printf("���ļ�ʧ��.\n");
        }
        else
        {
            break;
        }

    }


	int i = 0, j;

	while(!feof(fp))
	{
		fscanf(fp, "%s %s", stuList[i].num, stuList[i].name);

		for(j = 0; j <= 5; j++)
		{
			fscanf(fp, "%lf", &stuList[i].score[j]);
		}

		i++;
	}

	count = i;

	fclose(fp);
	puts("���ݼ��سɹ�.");
}

// �����ܷ�
void calTotal()
{
	int i, j, total = 0;
	for(i = 0; i < count; i++)
	{
		total = 0;
		for(j = 0; j <= 5; j++)
		{
			total += stuList[i].score[j];
		}
		stuList[i].total = total;
	}

	puts("�ּܷ���ɹ�.");
}
//����ƽ����
void average()
{
    int i, j;
    double Average, total = 0;
	for(i = 0; i < count; i++)
	{
		total = 0;
		for(j = 0; j <= 5; j++)
		{
			total += stuList[i].score[j];
		}
		stuList[i].total = total;
		Average=total/6.0;
		stuList[i].Average = Average;
			}
    puts("����ƽ���ֳɹ�");
}

// ���ܳɼ�������������ѡ�񷨡�
void sortListByScore()
{
	int i, j;

	for(i = 0; i < count; i++)
	{
		int k = i;	// �� k ����¼���ֵ���±�
		for(j = i + 1; j < count; j++)
		{
			if(stuList[j].total > stuList[k].total)
			{
				k = j;
			}
		}
		if(k != i)
		{
			struct Student temp = stuList[i];
			stuList[i] = stuList[k];
			stuList[k] = temp;
		}
	}

	puts("�������.");
}

// ������������ļ�

void outputToFile()
{
	printf("ȷ�ϱ����ļ���y/n����");
	getchar();
	if(getchar()=='n')
        return;
	char filename[20];
	printf("������Ҫ����������ļ�:");
	scanf("%s",filename);
	FILE * fp;
	if((fp = fopen(filename, "w")) == NULL)
	{

		puts("���ļ�ʧ��.\n");
		return;
	}
	int i,ret;
	for (i = 0; i <count; i++)//��ӡ
	{
		ret=fprintf(fp,"%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%d\n",
			stuList[i].num,stuList[i].name,
			stuList[i].score[0],stuList[i].score[1],stuList[i].score[2],stuList[i].score[3],stuList[i].score[4],stuList[i].score[5],stuList[i].total,stuList[i].Average);
	}
	if (ret<0)
	{
		printf("�ļ�д��ʧ��\n");
	}
	else
	{
		printf("�ļ�д��ɹ�\n");
	}
	fclose(fp);		//�ر��ļ�ָ��
}
// �������������Ļ
void outputToScreen()
{
	int i, j;

	for(i = 0; i < count; i++)
	{
		printf("%s\t%s\t", stuList[i].num, stuList[i].name);
		for(j = 0; j <= 5; j++)
		{
			printf("%.0lf\t", stuList[i].score[j]);
		}
		printf("%.1lf\n", stuList[i].total);
	}

}
void searchBynum()
{
	char tempNum[20];
	int i = 0, j =0;
	printf("������ѧ��:");
	gets(tempNum);

	while (i < count)
	{
		if (strcmp(tempNum, stuList[i].num) == 0)
		{
			break;
		}
		i++;
	}

	printf("%s\t%s\t", stuList[i].num, stuList[i].name);
	for (j = 0; j <= 5; j++)
	{
		printf("%.0lf\t", stuList[i].score[j]);
	}
	printf("%.1lf\n", stuList[i].total);
}

void searchByname()
{
	char tempName[50];
	int i = 0, j = 0;

	printf("����������(֧��ֻ��������):");
	gets(tempName);

	while (i < count)
	{
		if (strcmp(tempName, stuList[i].name)==0)
		{
			printf("%s\t%s\t", stuList[i].num, stuList[i].name);
			for (j = 0; j <= 5; j++)
			{
				printf("%.0lf\t", stuList[i].score[j]);
			}
			printf("%.1lf\n", stuList[i].total);
			return;
		}
		i++;
	}

    i=0;
	while (i < count)
	{
		if (tempName[0] == stuList[i].name[0] && tempName[1] == stuList[i].name[1])
		{
			printf("%s\t%s\t", stuList[i].num, stuList[i].name);
			for (j = 0; j <= 5; j++)
			{
				printf("%.0lf\t", stuList[i].score[j]);
			}
			printf("%.1lf\n", stuList[i].total);
		}
		i++;
	}
}

void addScore()
{
	printf("������ѧ��:\n");
	scanf("%s",stuList[count].num);
	printf("����������:\n");
	scanf("%s",stuList[count].name);
	for(int i = 0;i < 6;i++)
	{
		printf("�������Ŀ%d:",i+1);
		scanf("%lf",&stuList[count].score[i]);
		stuList[count].total+=stuList[count].score[i];
	}
	count++;
	puts("���ӳɹ�\n");
	getchar();
}

void deleteDate()
{
	int i = 0,num = 0;
	char tempnum[20];
	printf("������Ҫɾ����ͬѧѧ��:");
    gets(tempnum);
	printf("ȷ��ɾ������y/n��:");
	char ensure = getchar();
	getchar();
	if(ensure == 'n')
	{
		system("cls");
		return;
	}
	while (i < count)
	{
		if (strcmp(tempnum, stuList[i].num) == 0)
		{
		    break;
		}

		i++;
	}
    if(i==count)
    {
        printf("�����ڴ�ѧ��\n");
        return;
    }
	num = i;
	for(i = num;i < count;i++)//����Ĳ���ǰ���
	{
		stuList[i]=stuList[i+1];
	}
	count--;
	printf("ɾ���ɹ�\n");
}

void filepartSelect()
{
    char select;
    while(1)
    {
        menu();
        printf("��ѡ����:");
        select = getchar();
        getchar();
        // switch ���Խ���ʲôֵ��ֻ�ܽ���ʲôֵ����������ʲô select Ϊ char Ϊʲô����? ASCII
        switch (select)
        {
            case '1':
                addScore();
                break;
            case '2':
                deleteDate();
                break;
            case '3':
                calTotal();
                break;
            case '4':
                average();
                break;
            case '5':
                sortListByScore();
                break;
            case '6':
                outputToFile();
                break;
            case '7':
                outputToScreen();
                break;
            case '8':
                system("cls");
                break;
            case '9':
                break;
            default:
                puts("��������밴�˵���ʽ����.");
                break;
        }
    }

}

void searchpartSelect()
{
    char select;
    while(1)
    {
        seachMenu();
        printf("��ѡ����:");
        select = getchar();
        getchar();

        switch (select)
        {
            case '1':
                searchBynum();
                break;
            case '2':
                searchByname();
                break;
            case '3':
                break;
            default:
                break;
        }
    }
    getchar();
}
