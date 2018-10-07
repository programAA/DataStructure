#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Stack.h"
using namespace std;
typedef int ElemType;
typedef struct TNode *Tree;
struct TNode {
	ElemType Data;
	struct TNode *left, *right;
};
Tree CreateTree()
{
	Tree T = (Tree)malloc(sizeof(struct TNode));
	T->left = NULL;
	T->right = NULL;
	return T;
}
Tree Insert(ElemType x, Tree T)
{
	if (T == NULL)
	{
		T = (Tree)malloc(sizeof(struct TNode));
		T->Data = x;
		T->left = NULL;
		T->right = NULL;
	}
	else
		if (x < T->Data)
			T->left = Insert(x, T->left);
		else if (x > T->Data)
			T->right = Insert(x, T->right);
	return T;
}
void Traverse1(Tree T)//ǰ��ݹ����
{
	if (T != NULL)
	{
		printf("%5d\n", T->Data);
		Traverse1(T->left);
		Traverse1(T->right);
	}
}
void Traverse11(Tree T)//ǰ��ǵݹ����
{
	Stack S = InitStack();
	while (T != NULL || !IsEmpty(S))
	{
		while (T != NULL)
		{
			cout << T->Data << endl;
			Push(S, T);
			T = T->left;
		}
		if (!IsEmpty(S))
		{
			T = Pop(S);
			T = T->right;
		}
	}
}

void Traverse22(Tree T)//����ǵݹ����
{
	Stack S = InitStack();
	while (T != NULL || !IsEmpty(S))
	{
		while (T != NULL)
		{
			Push(S, T);
			T = T->left;
		}
		if (!IsEmpty(S))
		{
			T=Pop(S);
			cout << T->Data << endl;
			T = T->right;
		}
	}
}

void Traverse2(Tree T)//����ݹ����
{
	if (T != NULL)
	{
		Traverse2(T->left);
		printf("%5d\n", T->Data);
		Traverse2(T->right);
	}
}
void Traverse3(Tree T)//����ݹ����
{
	if (T != NULL)
	{
		Traverse3(T->left);
		Traverse3(T->right);
		printf("%5d\n", T->Data);
	}
}

void Traverse33(Tree T)
{
	Stack S = InitStack();
	Tree pre = NULL;
	Tree cur;
	Push(S, T);
	while (!IsEmpty(S))
	{
		cur = GetTop(S);
		if ((cur->left == NULL && cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right)))
		{
			cout << cur->Data << endl;
			pre = cur;
			Pop(S);
		}
		else
		{
			if (cur->right != NULL)
				Push(S, cur->right);
			if (cur->left != NULL)
				Push(S, cur->left);
		}
	}
}

Tree Find(ElemType x, Tree T)
{
	if (T == NULL)
		return NULL;
	if (x > T->Data)
		return Find(x, T->right);
	else if (x < T->Data)
		return Find(x, T->left);
	else return T;
}

Tree Find2(ElemType x, Tree T)
{
	while (T) {
		if (x < T->Data)
			T = T->left;
		else if (x > T->Data)
			T = T->right;
		else
			return T;
	}
	return NULL;
}	
Tree FindMin(Tree T){
	if (T)
		while (T->left)  T = T->left;
	return T;
}
Tree FindMax(Tree T) {
	if (!T) return NULL;
	else if (!T->right) return T;
	else
		return FindMax(T->right);
}
Tree Insert(ElemType x, Tree T) {//��x�������������T��
	if (!T) {
		T = (Tree)malloc(sizeof(struct TNode));
		T->Data = x;
		T->left = T->right = NULL;
	}
	else {
		if (x > T->Data)
			T->right = Insert(x, T->right);
		else if (x < T->Data)
			T->left = Insert(x, T->left);
	}
	return T;
}
Tree Insert2(ElemType x, Tree T) {
	if (!T) {
		T = (Tree)malloc(sizeof(struct TNode));
		T->Data = x;
		T->left = T->right = NULL;
	}
	else {
		Tree t = T;
		while (1) {
			while (x > t->Data) {
				if (t->right)  t = t->right;
				else {
					t->right = (Tree)malloc(sizeof(struct TNode));
					t->right->Data = x;
					t->right->left = t->right->right = NULL;
					return T;
				}
			}
			while (x < t->Data) {
				if (t->left)  t = t->left;
				else {
					t->left = (Tree)malloc(sizeof(struct TNode));
					t->left->Data = x;
					t->left->left = t->left->right = NULL;
					return T;
				}
			}
		}
	}
	return T;
}
Tree Delete(ElemType x, Tree T) {//����T��ɾ��x����������ͷ���
	Tree t;
	if (!T) printf("��������");
	else if (x > T->Data)
		T->right = Delete(x, T->right);
	else if (x < T->Data)
		T->left = Delete(x, T->left);
	else {//�ҵ�Ҫɾ���Ľڵ�T
		if (T->left&&T->right) {//Ҫɾ���Ľڵ���������������
			t = FindMax(T->left);//����FindMin(T->right)
			T->Data = t->Data;
			T->left = Delete(T->Data, T->left);
		}
		else {//ֻ����һ���ӽڵ�򲻴����ӽڵ�
			t = T;
			if (!T->left)//�������ӽڵ�����ӽڵ�
				T = T->right;
			else if (!T->right)//�������ӻ����ӽڵ�
				T = T->left;
			free(t);
		}
	}
	return T;
}
#endif