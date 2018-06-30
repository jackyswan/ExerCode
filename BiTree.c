#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
    char data;
    PointerTag lTag;
    PointerTag rTag;
    struct BiThrNode *lNode, *rNode;
}BiNode,*Bitree;

BiTree pre;

void CreatTree(Bitree *t)
{
    char ch;
    scanf("%c", &ch);
    if (ch == "#")
    {
        t = null;
    }
    else
    {
        t = (BiTree)malloc(sizeof(BiNode));
        if (t == null)
        {
            return;
        }
        t->data = ch;
        CreatTree(t->lNode);
        CreatTree(t->rNode);
    }
}

InOrderBiTree(Bitree* t)
{

}
