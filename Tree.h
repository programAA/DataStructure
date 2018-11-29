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
void PreOrder1(Tree T)//前序递归遍历
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
void PreOrder3(Tree T)//前序非递归遍历
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
void MidOrder1(Tree T)//中序递归遍历
{
	if (T != NULL)
	{
		MidOrder1(T->left);
		printf("%5d\n", T->Data);
		MidOrder1(T->right);
	}
}
void MidOrder2(Tree T)//中序非递归遍历
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
void PostOrder1(Tree T)//后序递归遍历
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
	Tree pre = NULL;//前一个
	Tree cur;//当前
	Push(S, T);
	while (!IsEmpty(S)) {
		cur = GetTop(S);
		if ((cur->left == NULL && cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right)))
		{//当前节点的左右儿子均不存在或前一个访问的节点存在且是当前节点的左右儿子之一
			cout << cur->Data << endl;//打印当前节点
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
	//非二叉排序树二叉树查找
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
void Delete(Tree &T, TElemType x) {//从树T中删除x
	Tree t;
	if (T == NULL)
		cout << "删除失败" << endl;
	else if (x > T->Data)
		Delete(T->right, x);
	else if (x < T->Data)
		Delete(T->left, x);
	else {//找到要删除的节点T
		if (T->left&&T->right) {//要删除的节点左右子树都存在
			t = FindMax(T->left);//或者FindMin(T->right)
			T->Data = t->Data;
			Delete(T->left, T->Data);
		}
		else {//只存在一个子节点或不存在子节点
			t = T;
			if (T->left == NULL)//存在右子节点或无子节点
				T = T->right;
			else if (T->right == NULL)//存在左孩子或无子节点
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
//	Tree parent;//指向父节点，提供向前搜索
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
			cout << "动态内存不足" << endl;
			exit(1);
		}
		H->Data = NewP;
		H->MaxSize *= 2;
	}
	H->Data[H->len] = x;
	H->len++;
	int child = H->len - 1;//儿子节点
	int parent = (child - 1) / 2;//父亲节点
	while (child != 0) {
		if (x < H->Data[parent])//儿子节点小于父亲节点，不用调整
			break;
		H->Data[child] = H->Data[parent];//寻找x的合适位置
		child = parent;
		parent = (child - 1) / 2;
	}
	H->Data[child] = x;
}
#endif