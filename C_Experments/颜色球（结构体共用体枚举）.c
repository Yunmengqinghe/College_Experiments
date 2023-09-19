#include <stdio.h>

void main()
{
    enum colour { red, yellow, blue, white, black };
    enum colour i, j, k;
    int m, n = 0,a[3];

    for (i = red; i < black; i=colour(i+1))
    {
        for (j = red; j < black;j=(colour)(j+1))
        {
            if (i != j)
            {
                for (k = red; k < black; k=(colour)(k+1))
                {
                    if (k != i && k != j)
                    {
                        n += 1;
                    }
                    a[0] = i;
                    a[1] = j;
                    a[2] = k;
                    printf("第%d个数:>", n);
                    for (int i = 0; i < 3; i++)
                    {
                        switch (a[i])
                        {
                        case red:printf("red\t"); break;
                        case yellow:  printf("yellow\t"); break;
                        case blue:  printf("blue\t"); break;
                        case white:printf("white\t"); break;
                        case black:   printf("black\t"); break;
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
    printf("总共有%d种排列方式:", n);

}
