#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElementType;
typedef struct{
    ElementType *top;
    ElementType *base;
    int StackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElementType *)malloc(STACK_INIT_SIZE * sizeof(ElementType));
    if (!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->StackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElementType e)
{
    if (s->top - s->base >= s->StackSize)
    {
       s->base = (ElementType*)realloc(s->base, (s->StackSize + STACK_INIT_SIZE) * sizeof(ElementType));
       s->top = s->base + s->StackSize;
    }
    *(s->top) = e;
    s->top ++;
}

void Pop(sqStack *s, ElementType *e)
{
    if (s->top == s->base)
    {
        exit(0);
    }
    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base)/sizeof(ElementType);
}

int main(void)
{
    ElementType c;
    sqStack s;
    int len, i, sum;

    InitStack(&s);

    scanf("%c", &c);
    getchar();
    while( c != '#')
    {
        Push(&s, c);
        scanf("%c", &c);
        getchar();
    }
    len = StackLen(s);
    printf("当前容量是：%d\n", len);
    sum = 0;
    for (i = 0; i < len; i++)
    {
        Pop(&s, &c);
        printf("pop:%d", c);
        sum +=  (c-48) * (pow(2, i));
    }
    printf("转换为：%d\n", sum);
}
