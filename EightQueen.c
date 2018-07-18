#include <stdio.h>
#include <stdlib.h>

int count = 0;

int JudgeDanger(int row, int pos, int n, int(*chess)[8])
{
    int i, j;

    printf("judee\n");
    //左上方
    for (i = row ; i-1 >= 0 && pos-1 >= 0; i--)
    {
        if(*(*(chess+i-1)+pos-1))
            return 0;
        pos--;
    }
    //正上方
    for(i = row; i - 1 >= 0; i--)
    {
        if(*(*(chess+i-1)+pos))
            return 0;
    }
    //右上方
    for(i = row; i-1 >= 0 && pos + 1< n; i--)
    {
        if(*(*(chess+i-1)+pos+1))
            return 0;
        pos++;
    }

    return 1;
}

void EightQueen(int row, int n, int (*chess)[8])
{
    int i, j;
    int chess2[n][n];

    if (row == n)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                printf("%d ", *(*(chess+i)+j));
            }
        }

        count ++;
        printf("\n");
        printf("这是第%d种布局\n", count);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j ++)
            {
                chess2[i][j] = *(*(chess+i)+j);
            }
        }
        printf("eightqueen %d\n", row);
        for(j = 0; j < n; j++)
        {
            if (JudgeDanger(row, j, n, chess2))
            {
                chess2[row][j] = 1;
                EightQueen(row + 1, n, chess2);
            }
        }
    }
}

int main(void)
{
    int chess[8][8], i, j;

    for( i = 0; i < 8; i++)
    {
        for( j = 0; j < 8; j++)
        {
            chess[i][j] = 0;
        }
    }

    EightQueen(0, 8, chess);

    printf("总共有多少种方案：%d\n", count);
}


