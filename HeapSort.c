#include <stdio.h>

void swap(int k[] , int m, int n)
{
    int temp;
    temp = k[m];
    k[m] = k[n];
    k[n] = temp;
}

void HeapAdjust(int k[], int s, int n)
{
    int i, temp;

    temp = k[s];

    for( i=2*s; i<=n; i*=2 )
    {
        if( i < n && k[i] < k[i+1])
        {
            i ++;
        }

        if( temp >= k[i])
        {
            break;
        }
        k[s] = k[i];//如果不是较大的那么就遍历后面的叶节点找到对应的下标
        s = i;
    }

    k[s] = temp;
}

void HeapSort(int k[], int n)
{
    int i;

    for(i = n /2; i > 0; i --)
    {
        HeapAdjust(k, i, n);//从后面往前排
    }

    for( i=n; i > 1; i--)
    {
        swap(k, 1, i);// 将较大的数排到最后
        HeapAdjust(k, 1, i-1); //重新排成大堆
    }
}

int main()
{
    int i, a[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

    HeapSort(a, 9);

    printf("排序的结果是：");
    for ( i=0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    return 0;
}
