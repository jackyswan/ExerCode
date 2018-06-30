#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

node* CreateNode(int num)
{
    node* p;
    node* head;
    node* s;
    int n = 1;

    head = (node*)malloc(sizeof(node));
    p = head;
    p->val = n;

    while(n < num)
    {
        n++;
        s = (node*)malloc(sizeof(node));
        s->val = n;
        p->next = s;
        p = s;
    }
    p -> next = head;
    return p->next;
}

int main(void)
{
    int num=41;
    node* temp;
    int n;
    node* p;

    p = CreateNode(num);

    while(p != p->next->next)
    {
        for (n=1; n < 2; n++)
        {
            p = p->next;
        }
        temp = p->next;
        printf("Del %d\n", temp->val);
        p->next = temp->next;
        p = temp->next;
        free(temp);
    }

    for (n=1;n<3;n++)
    {
        printf("Res %d\n", p->val);
        p=p->next;
    }
}
