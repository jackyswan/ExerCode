#include <stdio.h>
#include <stdlib.h>

int EightQueen(int row, int n, int (*chess)[8] )
{
    int count, i, j;
    int chess2[n][n];

    for(i=0; i < n;)
}

int main(void)
{
    int chess[8][8], i, j;
    int count;

    for( i=0; i < 8; i++)
    {
        for( j=0; j < 8; j++)
        {
            chess[i][j] = 0;
        }
    }

    count = EightQueen(0, 8, chess);

    printf("总共有多少种方案：%d\n", count);
}


