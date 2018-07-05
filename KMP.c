#include <stdio.h>
#include <stdlib.h>


/*失配的时候用哪个元素进行下一轮匹配
 *用next数组来保存匹配串的特性
 */

void get_next(String T, int *next)
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
            j = next[j];
        }
    }
}


