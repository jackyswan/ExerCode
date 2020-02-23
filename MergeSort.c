#include <stdio.h>

#define MAXSIZE 10

void Merging(int list1[], int list1_Size, int list2[], int list2_Size)
{
    int temp[MAXSIZE];
    int i = 0, j = 0, n = 0;

    while(i < list1_Size && j < list2_Size)
    {
        if (list1[i] < list2[j])
        {
            temp[n++] = list1[i++];
        }
        else
        {
            temp[n++] = list2[j++];
        }
    }

    while ( i < list1_Size)
    {
        temp[n++] = list1[i++];
    }

    while ( j < list2_Size)
    {
        temp[n++] = list2[j++];
    }

    for(n = 0; n < (list1_Size + list2_Size); n++)
    {
        list1[n] = temp[n];
    }
}

void MergeSort(int k[], int n)
{
    int i = 0;
    int list1_Size;
    int* list1;
    int list2_Size;
    int* list2;

    if(n > 1)
    {
        list1_Size = n/2;
        list1 = k;
        list2_Size = n - n/2;
        list2 = k + list1_Size;

        MergeSort(list1, list1_Size);
        MergeSort(list2, list2_Size);
        Merging(list1, list1_Size, list2, list2_Size);
    }
}

int main(void)
{
    int i, a[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

    MergeSort(a, 10);

    printf("排序的结果是：");
    for ( i=0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    return 0;
}
