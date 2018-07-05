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

void visit(char data, int level)
{
    printf("%c in level:%d\n", data, level);
}

PreOrderTraverse(BiTree T, int level)
{
    if (T)
    {
        visit(T->data, level);
        PreOrderTraverse(T->lNode, level + 1);
        PreOrderTraverse(T->rNode, level + 1);
    }
}

InOrderBiTree(Bitree* t)
{

}
