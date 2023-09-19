#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200

struct Student
{
	char num[20];		// 学号
	char name[50];		// 姓名
	double score[6];	// 6门课的成绩
	double total;		// 总分
	double Average;         //平均分

}person;
char filename[20];

// 学生数组，尽量将学生数组的长度定义长一点
struct Student stuList[N];

// 真实的学生数目
int count = 0;

// 菜单
void menu()
{
	puts("=======================================");
    puts("1、成绩的录入与添加");
	puts("2、删除");
	puts("3、计算总分");
	puts("4、计算平均分");
	puts("5、按总分排序");	// 基于学生的总分，对结构数组进行排序
	puts("6、输出到文件");
	puts("7、输出到屏幕");
	puts("8、清空屏幕");
	puts("9、退出程序");
	puts("=======================================");
}

void seachMenu()
{
	puts("=======================================");
	puts("1、按照学号搜索");
	puts("2、按照姓名搜索");
	puts("3、退出");
	puts("=======================================");
}

void functionMenu()
{
    puts("=======================================");
	puts("1、学生信息文件功能");
	puts("2、学生信息管理功能");
	puts("3、退出");
	puts("=======================================");

}

void createListFromFile();		// 从文件中读取学生的成绩数据
void calTotal();				// 计算总分
void average();                 // 计算平均分
void sortListByScore();			// 按总成绩进行排序【升序，选择法】
void outputToFile();			// 将数组输出到文件
void outputToScreen();			// 将数组输出到屏幕
void addScore();                // 成绩的录入与添加
void deleteDate();              // 删除

void searchBynum();             // 通过学号搜索学生
void searchByname();            // 通过名字搜索学生

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

// 从文件中读取学生的成绩数据
void createListFromFile()
{
    FILE *fp;
	char filename[10];
	while(1)
    {
        printf("\n请输入数据所在的文件名:");
        gets(filename); // 1.txt


        if((fp = fopen(filename, "r")) == NULL)
        {
            printf("打开文件失败.\n");
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
	puts("数据加载成功.");
}

// 计算总分
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

	puts("总分计算成功.");
}
//计算平均分
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
    puts("计算平均分成功");
}

// 按总成绩进行排序【升序，选择法】
void sortListByScore()
{
	int i, j;

	for(i = 0; i < count; i++)
	{
		int k = i;	// 用 k 来记录最大值的下标
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

	puts("排序完成.");
}

// 将数组输出到文件

void outputToFile()
{
	printf("确认保存文件（y/n）：");
	getchar();
	if(getchar()=='n')
        return;
	char filename[20];
	printf("请输入要保存的数据文件:");
	scanf("%s",filename);
	FILE * fp;
	if((fp = fopen(filename, "w")) == NULL)
	{

		puts("打开文件失败.\n");
		return;
	}
	int i,ret;
	for (i = 0; i <count; i++)//打印
	{
		ret=fprintf(fp,"%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%d\n",
			stuList[i].num,stuList[i].name,
			stuList[i].score[0],stuList[i].score[1],stuList[i].score[2],stuList[i].score[3],stuList[i].score[4],stuList[i].score[5],stuList[i].total,stuList[i].Average);
	}
	if (ret<0)
	{
		printf("文件写入失败\n");
	}
	else
	{
		printf("文件写入成功\n");
	}
	fclose(fp);		//关闭文件指针
}
// 将数组输出到屏幕
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
	printf("请输入学号:");
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

	printf("请输入名字(支持只输入姓氏):");
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
	printf("请输入学号:\n");
	scanf("%s",stuList[count].num);
	printf("请输入姓名:\n");
	scanf("%s",stuList[count].name);
	for(int i = 0;i < 6;i++)
	{
		printf("请输入科目%d:",i+1);
		scanf("%lf",&stuList[count].score[i]);
		stuList[count].total+=stuList[count].score[i];
	}
	count++;
	puts("增加成功\n");
	getchar();
}

void deleteDate()
{
	int i = 0,num = 0;
	char tempnum[20];
	printf("请输入要删除的同学学号:");
    gets(tempnum);
	printf("确定删除？（y/n）:");
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
        printf("不存在此学生\n");
        return;
    }
	num = i;
	for(i = num;i < count;i++)//后面的补上前面的
	{
		stuList[i]=stuList[i+1];
	}
	count--;
	printf("删除成功\n");
}

void filepartSelect()
{
    char select;
    while(1)
    {
        menu();
        printf("请选择功能:");
        select = getchar();
        getchar();
        // switch 可以接受什么值？只能接受什么值？整数，那什么 select 为 char 为什么可以? ASCII
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
                puts("输入错误，请按菜单格式输入.");
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
        printf("请选择功能:");
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
