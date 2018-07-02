#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*总结规则
 * 1. 数字直接输出
 * 2. 右括号或者优先级低于栈顶符号的则出栈
 *    直到遇到左括号或者栈空将这个符号入栈*/
typedef double ElemtType;

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

void Pop(pStack s, ElemtType *n)
{
    n = s->top;
    s->top --;
}

void Push(pStack s, ElemtType *n)
{
    *n = *(s->top);
    s->top --;
}

int StackLen(pStack s)
{
    return (s->top - s->base)/sizeof(ElemtType);
}

Trans(char*)
{
    while(1)
    {
        switch(str[i])
        {
            case ')':
                Pop(sqStack, )
            case '*':
                Pop(sqStack, )
            default:
                Push(sqStack,)
        }
    }
}

int main(void)
{
    pStack sqStack;
    char c;
    ElemtType d, e;
    char str[10];
    int i = 0;

    printf("请按照逆波兰算法输入表达式，数据和运算符用空格隔开:\n");
    scanf("%c", &c);
    InitStack(sqStack, 20);
    
    while(c != '#')
    {
        while(isdigit(c) || c == '.')
        {
            str[i++] = c;
            str[i] = '\0'
            if ( i >= 10)
            {
                printf("输出的数据过大\n");
                return -1;
            }
            scanf("%c", &c);
            if (c == ' ')
            {
                d = atof(str);
                Push(sqStack, d);
                i = 0;
                break;
            }
        }
        switch (c)
        {
        case '+':
            Pop(sqStack, &d);
            Pop(sqStack, &e);
            Push(sqStack, e+d);
            break;
        case '-':
            Pop(sqStack, &d);
            Pop(sqStack, &e);
            Push(sqStack, e-d);
            break;
        case '*':
            Pop(sqStack, &d);
            Pop(sqStack, &e);
            Push(sqStack, e*d);
            break;
        case '/':
            Pop(sqStack, &d);
            Pop(sqStack, &e);
            if (d != 0)
            {
                Push(sqStack, e/d);
            }
            else
            {
                printf("除数不能为0!!!\n");
                return -1;
            }
            break;
        }
    }
    Pop(sqStack, &d);
    Printf("计算结果:%f\n", d);
    return 0;
}
