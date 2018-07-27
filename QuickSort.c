#include <stdio.h>

void swap(int k[] , int m, int n)
{
    int temp;
    temp = k[m];
    k[m] = k[n];
    k[n] = temp;
}

int Partition(int k[], int low, int high)
{
    int point;

    point = k[low];

    while(low < high)
    {
        while(k[high] >= point && high > low)
        {
            high--;
        }
        if(high <= low )
        {
            break;
        }
        swap(k, low, high);
        while(k[low] <= point && high > low)
        {
            low++;
        }
        if (high <= low)
        {
            break;
        }
        swap(k, low, high);
    }
    return low;
}

void Qsort(int k[], int low, int high)
{
    int point;

    if (low < high)
    {
        point = Partition(k, low, high);
        Qsort(k, low, point);
        Qsort(k, point + 1, high);
    }
}

void QuickSort(int k[], int n)
{
    Qsort(k, 0, n-1);
}

int main(void)
{
    int i, a[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

    QuickSort(a, 10);

    printf("排序的结果是：");
    for ( i=0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    return 0;
}
