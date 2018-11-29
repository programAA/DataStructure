#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#define K 5
using namespace std;
typedef int TElemType;


typedef struct TNode {
	TElemType Data;
	struct TNode *left, *right;
}*Tree;
Tree InitTree() {
	return NULL;
}
void PreOrder1(Tree T)//ǰ��ݹ����
{
	if (T != NULL)
	{
		cout << T->Data << endl;
		PreOrder1(T->left);
		PreOrder1(T->right);
	}
}
void PreOrder2(Tree T) {
	LStack S = InitLStack();
	Tree P;
	if (T != NULL)
		Push(S, T);
	while (!IsEmpty(S)) {
		P=Pop(S);
		cout << P->Data << endl;
		if (P->right != NULL)
			Push(S, P->right);
		if (P->left != NULL)
			Push(S, P->left);
	}
}
void PreOrder3(Tree T)//ǰ��ǵݹ����
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
void MidOrder1(Tree T)//����ݹ����
{
	if (T != NULL)
	{
		MidOrder1(T->left);
		printf("%5d\n", T->Data);
		MidOrder1(T->right);
	}
}
void MidOrder2(Tree T)//����ǵݹ����
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
void PostOrder1(Tree T)//����ݹ����
{
	if (T != NULL)
	{
		PostOrder1(T->left);
		PostOrder1(T->right);
		printf("%5d\n", T->Data);
	}
}
void PostOrder2(Tree T)
{
	Stack S = InitStack();
	Tree pre = NULL;//ǰһ��
	Tree cur;//��ǰ
	Push(S, T);
	while (!IsEmpty(S)) {
		cur = GetTop(S);
		if ((cur->left == NULL && cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right)))
		{//��ǰ�ڵ�����Ҷ��Ӿ������ڻ�ǰһ�����ʵĽڵ�������ǵ�ǰ�ڵ�����Ҷ���֮һ
			cout << cur->Data << endl;//��ӡ��ǰ�ڵ�
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
void LayerOrder(Tree T) {
	Tree P;
	LQueue Q = InitLQueue();
	if (T != NULL)
		EnQueue(Q, T);
	while (!IsEmpty(Q)) {
		P = DeQueue(Q);
		cout << P->Data << endl;
		if (P->left != NULL)
			EnQueue(Q, P->left);
		if (P->right != NULL)
			EnQueue(Q, P->right);
	}
}
Tree Find1(Tree T, TElemType x) {
	if (T == NULL)
		return NULL;
	else {
		if (x = T->Data)
			return T;
		else if (x > T->Data)
			return Find1(T->right, x);
		else
			return Find1(T->left, x);
	}
}
Tree Find2(Tree T, TElemType x) {
	while (T != NULL) {
		if (x < T->Data)
			T = T->left;
		else if (x > T->Data)
			T = T->right;
		else
			return T;
	}
	return NULL;
}
Tree Find3(Tree T, TElemType x) {
	//�Ƕ�������������������
	if (T == NULL)
		return NULL;
	else {
		if (T->Data == x)
			return T;
		else {
			Tree P;
			if (P = Find3(T->left, x))
				return P;
			if (P = Find3(T->right, x))
				return P;
			return NULL;
		}
	}
}
Tree FindMin(Tree T) {
	if (T != NULL)
		while (T->left != NULL)  T = T->left;
	return T;
}
Tree FindMax(Tree T) {
	if (T == NULL || T->right == NULL)
		return T;
	else
		return FindMax(T->right);
}
void Insert(Tree &T, TElemType x) {
	if (T == NULL) {
		T = (Tree)malloc(sizeof(struct TNode));
		T->Data = x;
		T->left = T->right = NULL;
	}
	else {
		if (x < T->Data)
			Insert(T->left, x);
		else
			Insert(T->right, x);
	}
}
void Delete(Tree &T, TElemType x) {//����T��ɾ��x
	Tree t;
	if (T == NULL)
		cout << "ɾ��ʧ��" << endl;
	else if (x > T->Data)
		Delete(T->right, x);
	else if (x < T->Data)
		Delete(T->left, x);
	else {//�ҵ�Ҫɾ���Ľڵ�T
		if (T->left&&T->right) {//Ҫɾ���Ľڵ���������������
			t = FindMax(T->left);//����FindMin(T->right)
			T->Data = t->Data;
			Delete(T->left, T->Data);
		}
		else {//ֻ����һ���ӽڵ�򲻴����ӽڵ�
			t = T;
			if (T->left == NULL)//�������ӽڵ�����ӽڵ�
				T = T->right;
			else if (T->right == NULL)//�������ӻ����ӽڵ�
				T = T->left;
			free(t);
		}
	}
}
int  Depth(Tree T) {
	if (T == NULL)
		return 0;
	else {
		int dep1 = Depth(T->left);
		int dep2 = Depth(T->right);
		if (dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}


typedef struct KTNode {
	TElemType Data;
	struct KTNode* P[K];
//	Tree parent;//ָ�򸸽ڵ㣬�ṩ��ǰ����
}*KTree;
void PreOrder(KTree T) {
	if (T != NULL) {
		cout << T->Data;
		for (int i = 0; i < K; i++)
			PreOrder(T->P[i]);
	}
}
void PostOrder(KTree T) {
	if (T != NULL) {
		for (int i = 0; i < K; i++)
			PostOrder(T->P[i]);
		cout << T->Data << endl;
	}
}
KTree Find(KTree T, TElemType x) {
	if (T == NULL)
		return NULL;
	else {
		KTree P;
		if (T->Data == x)
			return T;
		for (int i = 0; i < K; i++)
			if (P = Find(T->P[i], x))
				return P;
		return NULL;
	}
}


typedef struct HeapNode {
	TElemType *Data;
	int len;
	int MaxSize;
}*Heap;
void MaxInsert(Heap H, TElemType x) {
	if (H->len == H->MaxSize) {
		TElemType* NewP = (TElemType *)realloc(H->Data, 2 * H->MaxSize * sizeof(TElemType));
		if (NewP == NULL) {
			cout << "��̬�ڴ治��" << endl;
			exit(1);
		}
		H->Data = NewP;
		H->MaxSize *= 2;
	}
	H->Data[H->len] = x;
	H->len++;
	int child = H->len - 1;//���ӽڵ�
	int parent = (child - 1) / 2;//���׽ڵ�
	while (child != 0) {
		if (x < H->Data[parent])//���ӽڵ�С�ڸ��׽ڵ㣬���õ���
			break;
		H->Data[child] = H->Data[parent];//Ѱ��x�ĺ���λ��
		child = parent;
		parent = (child - 1) / 2;
	}
	H->Data[child] = x;
}
#endif