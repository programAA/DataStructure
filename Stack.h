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
	//��������ڴ���ʱ�����������
	//1�������ǰ�ڴ�κ�������Ҫ���ڴ�ռ䣬��ֱ����չ����ڴ�ռ䣬realloc����ԭָ��
	//2�������ǰ�ڴ�κ���Ŀ����ֽڲ�������ô��ʹ�ö��еĵ�һ���ܹ�������һҪ����ڴ��
	//   ��Ŀǰ�����ݸ��Ƶ��µ�λ�ã�����ԭ�����ڴ���ͷŵ��������µ��ڴ��λ��
	//3���������ʧ�ܣ�������NULL����ʱ��ԭ����ָ����Ȼ��Ч
	SElemType *newbase = (SElemType *)realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(SElemType));
	if (newbase == NULL)
	{
		printf("��̬�ڴ�ռ䲻�㣬���ӷ���ʧ��\n");
		exit(1);//ִ�д˺�����ֹ��������
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
		cout << "��̬�ڴ治��" << endl;
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
		printf("��ջ,��Ԫ�س�ջ\n");
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
SElemType GetTop(Stack S)//���ջ���գ�����ջ��Ԫ��
{
	if (S->top == S->base)
	{
		printf("��ջ,��ջ��Ԫ��\n");
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
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	newP->data = x;
	newP->next = S;
	S = newP;
}
SElemType Pop(LStack &S) {
	if (S == NULL) {
		cout << "ջ�գ��޷�ɾ��" << endl;
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