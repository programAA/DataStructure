#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Tree.h"
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
using namespace std;
typedef struct TNode* SElemType;


typedef struct stack {
	SElemType *base;
	SElemType *top;
	int stacksize;
}*Stack;
void ReAssign(Stack S) {
	//将分配的内存变大时，有以下情况
	//1、如果当前内存段后面有需要的内存空间，则直接扩展这段内存空间，realloc返回原指针
	//2、如果当前内存段后面的空闲字节不够，那么就使用堆中的第一个能够满足这一要求的内存块
	//   将目前的数据复制到新的位置，并将原来的内存块释放掉，返回新的内存块位置
	//3、如果申请失败，将返回NULL，此时，原来的指针仍然有效
	SElemType *newbase = (SElemType *)realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(SElemType));
	if (newbase == NULL)
	{
		printf("动态内存空间不足，增加分配失败\n");
		exit(1);//执行此函数终止程序运行
	}
	S->base = newbase;
	S->top = S->base + (S->stacksize - 1);
	S->stacksize += STACK_INCREMENT;
}
Stack InitStack()
{
	Stack S = (Stack)malloc(sizeof(struct stack));
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (S->base == NULL) {
		cout << "动态内存不足" << endl;
		exit(1);
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return S;
}
void Push(Stack S, SElemType x)
{
	if (S->top - S->base == S->stacksize - 1)
		ReAssign(S);
	*(S->top) = x;
	S->top++;
}
SElemType Pop(Stack S)
{
	if (S->base == S->top)
	{
		printf("空栈,无元素出栈\n");
		exit(1);
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
SElemType GetTop(Stack S)//如果栈不空，返回栈顶元素
{
	if (S->top == S->base)
	{
		printf("空栈,无栈顶元素\n");
		exit(1);
	}
	else
		return *(S->top - 1);
}


typedef struct SNode {
	SElemType data;
	struct SNode* next;
}*LStack;
LStack InitLStack() {
	return NULL;
}
void Push(LStack &S, SElemType x) {
	LStack newP = (LStack)malloc(sizeof(struct SNode));
	if (newP == NULL) {
		cout << "动态内存不足" << endl;
		exit(1);
	}
	newP->data = x;
	newP->next = S;
	S = newP;
}
SElemType Pop(LStack &S) {
	if (S == NULL) {
		cout << "栈空，无法删除" << endl;
		exit(1);
	}
	SElemType temp = S->data;
	LStack P = S;
	S = S->next;
	free(P);
	return temp;
}
bool IsEmpty(LStack S) {
	return S == NULL ? true : false;
}
SElemType GetTop(LStack S) {
	return S->data;
}
#endif