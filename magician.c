#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}sqList, *pLinkList;

pLinkList CreateList(int num)
{
    pLinkList head = NULL;
    pLinkList s,r;
    int i;
    
    head = (pLinkList)malloc(sizeof(sqList));
    r = head;

    for(i=1;i<=num;i++)
    {
        s = (pLinkList)malloc(sizeof(sqList));
        r -> next = s;
        s -> val = 0;
        r = s;
    }
    s -> next = head->next;
    free(head);
    return s->next;
}

int main(void)
{
    int i,n;
    pLinkList s,r,head;

    s = CreateList(13);
    head = s;
    s->val = 1;
    i=2;

    while(1)
    {
        for (n = 1;n <= i; n++)
        {
            s=s->next;
            if (s->val != 0)
            {
                n--;
            }
        }

        s->val = i;
        i++;

        if (i == 14)
        {
            break;
        }
    }

    for(i = 0; i<13;i++)
    {
        printf("%d   ", head->val);
        head = head->next;
    }
}
