#include <stdio.h>
#include <stdlib.h>

typedef char ElemtType;

typedef struct stack{
    ElemtType *top;
    ElemtType *base;
    int StackSize;
}stack,*pStack;

void InitStack(stack *s, int nSize)
{
    s->base = (ElemtType*)malloc(sizeof(ElemtType)*nSize);
    s->top = s->base;
    s->StackSize = nSize;
}

pStack Pop(pStack s, ElemtType *n)
{
    n = s->top;
    s->top --;
}

int StackLen(pStack s)
{
    return (s->top - s->base)/sizeof(ElemtType);
}

int main(void)
{
    pStack sqStack;
    char c;

    printf("请按照逆波兰算法输入表达式，数据和运算符用空格隔开:\n");
    scanf("%c", c);

    InitStack(sqStack);
    
    int i;


}
