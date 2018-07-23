#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String{
    int num;
    char* pStr;
} pString*;
/*失配的时候用T串中的哪个元素进行下一轮匹配
 *用next数组来保存匹配串的特性
 */

void get_next(pString T, int *next)
{
    int j = 0;
    int i = 1;
    next[1] = 0;

    while ( i < T[0])
    {
        if ( T[i] == T[j] || j == 0)
        {
            i ++;
            j ++;
            if ( T[i] != T[j])
            {
                next[i] = j;
            }
            else
            {
                next[i] = next[j];
            }
        }
        else
        {
            j = next[j];// 在子串的j位置失配从next[j]位置开始适配
        }
    }
}

int Index_KMP( String S, String T)
{
    int i = 0;
    int j = 1;
    int next[255];

    get_next(T, next);

    while(i<S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];
        }
    }

    if(j > T[0])
    {
        return i - T[0];
    }
    else
    {
        return 0;
    }
}

int main (void)
{
    char str[255] = " ababaaaba";
    int i;
    char T[5]=" aaba";
    T[0] = 4;

    str[0] = 9;
    printf("%d\n", str[0]);
    i = Index_KMP(str, T);
    printf("位置在%d\n", i);
}
