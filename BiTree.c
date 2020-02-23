#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef enum {Link, Thread} PointerTag;
typedef enum {false, true} Status;

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

void InOrderBiTree(Bitree* t)
{

}

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T)
    {
        *p = f;
        return false;
    }
    else if ( key == T->data)
    {
        *p = T;
        return true;
    }
    else if (key < T->data)
    {
        return SearchBST(T->lNode, key, T, p);
    }
    else if (key > T->data)
    {
        return SearchBST(T->rNode, key, T, p);
    }
}

Status InsertBST(BiTree T, int key)
{
    BiTree *p. *s;
    if (!SearchBST(T, key, NULL, p)) // 在这里已经遍历到应该放置的位置
    {
        s = (BiTree*)malloc(sizeof(BiTree));
        s->data = key;
        s->lNode = s->rNode = NULL;

        if (!p)
        {
            *T = s;
        }
        else if ( key < p->data)
        {
            p->lNode = s;
        }
        else if ( key > p->data)
        {
            p->rNode = s;
        }
        return true;
    }
    else
    {
        return false;
    }
}

Status Delete(BiTree *p)
{
    BiTree q,s;

    if ((*p)->lNode == NULL)
    {
        q = *p;
        *p = (*p)->rNode;
        free(q)
    }
    else if ((*p)p->rNode == NULL)
    {
        q = *p;
        *p = (*p)->lNode;
        free(q)
    }
    else
    {
        q = *p;
        s = (*p)->lNode;

        while(!s->rNode)// 寻找左子树中最大的节点
        {
            s = s->rNode;
        }
        if (s->lNode != NULL)
        {
            
        }
        (*p) -> data = s->data;
    }
}

Status DelBST(BiTree T, int key)
{
    if (!T)
    {
        return false;
    }
    else
    {
        if (key == T->data)
        {
            return Delete(T);
        }
        else if ( key < T->data)
        {
            return DelBST(T->lNode, key);
        }
        else if ( key > T->rNode)
        {
            return DelBST(T->rNode, key);
        }
    }
}
