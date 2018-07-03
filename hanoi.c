#include <stdio.h>
#include <stdlib.h>

void move(int n, char x, char y, char z)
{
    if ( 1 == n)
    {
        printf("%c ---> %c\n", x, z);
    }
    else
    {
        move(n-1, x, z, y);
        printf("%c ---> %c\n", x, z);
        move(n-1, y, x, z);
    }
}

int main(void)
{
    int n;

    printf("请输入汉诺塔的层数：\n");
    scanf("%d", &n);
    printf("移动的过程如下:\n");
    move(n, 'x', 'y', 'z');
}
