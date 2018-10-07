#ifndef STACK_H
#define STACK_H
#include <iostream>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;
typedef char SElemType;
typedef struct stack *Stack;
struct stack {
	SElemType *base;
	SElemType *top;
	int stacksize;
};
Stack InitStack()
{
	Stack S = (Stack)malloc(sizeof(struct stack));
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (S->base == NULL)
		return NULL;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return S;
}
SElemType GetTop(Stack S)//Èç¹ûÕ»²»¿Õ£¬·µ»ØÕ»¶¥ÔªËØ
{
	if (S->top == S->base)
	{
		printf("¿ÕÕ»");
		return 0;
	}
	else
		return *(S->top - 1);
}
void Push(Stack S, SElemType x)
{
	if (S->top - S->base >= S->stacksize - 1)
	{
		SElemType *newbase = (SElemType *)realloc(S->base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
		if (newbase == NULL)
		{
			printf("·ÖÅäÊ§°Ü");
			return;
		}
		S->base = newbase;
		S->top = S->base + (S->stacksize - 1);
		S->stacksize += STACKINCREMENT;
	}
	*(S->top) = x;
	S->top++;
}
SElemType Pop(Stack S)
{
	if (S->base == S->top)
	{
		printf("¿ÕÕ»");
		return NULL;
	}
	S->top--;
	return *(S->top);
}

bool IsEmpty(Stack S)
{
	if (S->base == S->top)
		return true;
	else
		return false;
}
#endif