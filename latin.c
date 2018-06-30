#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}sqList,*pList;

pList CreateList(int num)
{
    int i;
    pList s,r,head;

    head = (pList)malloc(sizeof(sqList));
    r = head;

    for(i = 1; i <= num; i++)
    {
        s = (pList)malloc(sizeof(sqList));
        s->val = i;
        r->next = s;
        r = s;
        }
        s->next = head->next;
        free(head);
        return s->next;
    }

    int main(void)
    {
        int i;
        int num;
        int n;
    pList s;

    printf("请输入拉丁矩阵的大小：");
    scanf("%d", &num);
    getchar();

    s = CreateList(num);

    for (i=0; i<num; i++)
    {
        for(n=0; n<num; n++)
        {
            printf("%d ", s->val);
            s=s->next;
        }
        s=s->next;
        printf("\n");
    }
}
