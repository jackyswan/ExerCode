#include <stdio.h>

#define LH 1
#define EH 0
#define RH -1

typedef struct BiTNode
{
    int data;
    int bf;// 根据balance factor来检测平衡状态
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void R_Rotate(BiTree *p)
{
    BiTree L;
    L = (*p)->lchild;
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    *p = L;
}

void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;

    switch (L->bf)
    {
        case LH:
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            Lr = L->rchild;
            switch(Lr->bf)
            {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L -> bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate();
            R_Rotate();
    }
}

void RightBalance(BiTree *T)
{
}

int InsertAVL(BiTree* T, int e, int *taller)
{
    if ( !*T )
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = true;
    }
    else
    {
        if (e == (*T)->data)
        {
            *taller = false;
            return false;
        }
        if (e < (*T)->data)
        {
            if (!InsertAVL(&(*T)->lchild, e, taller))
            {
                return false;
            }
            if (*taller)
            {
                switch((*T)->bf)
                {
                    case LH:
                        LeftBalance(T);
                        *taller = false;
                        break;
                    case EH:
                        (*T)->bf = LH;
                        *taller = true;
                        break;
                    case RH:
                        (*T)->bf = EH;
                        *taller = false;
                        break;
                }
            }
        }
        else
        {
            if (!InsertAVL(&(*T)->rchild, e, taller))
            {
                return false;
            }
            if (*taller)
            {
                switch ((*T)->bf)
                {
                    case LH:
                        (*T)->bf = EH;
                        *taller = false;
                        break;
                    case EH:
                        (*T)->bf = RH;
                        *taller = true;
                        break;
                    case RH:
                        RightBalance(T);
                        *taller = false;
                        break;
                }
            }
        }
    }
}

int main(void)
{

}
