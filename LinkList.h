#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode *LinkList;


struct LNode {
	ElemType Data;
	LinkList Next;
};

LinkList InitLinkList() {
	return NULL;
}

int Length(LinkList L)
{
	LinkList P = L;
	int size = 0;
	while(P)
	{
		P = P->Next;
		size++;
	}
	return size;
}


LinkList FindKth(int k, LinkList L)
{
	if (k<1 || k>Length(L)) {
		cout << "k值不合法,程序异常退出" << endl;
		exit(1);
	}
	LinkList P = L;
	int i = 1;
	while (P != NULL && i < k)
	{
		P = P->Next;
		i++;
	}
	return P;

}

LinkList Find(ElemType x, LinkList L)
{
	LinkList P = L;
	while (P != NULL && P->Data != x)
		P = P->Next;
	if (P == NULL) {
		cout << "未找到要查找的值" << endl;
	}
	return P;
}

bool Insert(ElemType x, int pos, LinkList &L)
{
	if (pos<1 || pos>Length(L) + 1)
		return false;
	if (L == NULL) {
		L = (LinkList)malloc(sizeof(struct LNode));
		L->Data = x;
		L->Next = NULL;
		return true;
	}
	LinkList P = L;
	LinkList Q = (LinkList)malloc(sizeof(struct LNode));
	Q->Data = x;
	if (pos == 1)
	{
		Q->Next = P;
		L = Q;//指针改变了，要用指针的引用
		return true;
	}
	int i = 1;
	while (i < pos-1)
	{
		P = P->Next;
		i++;
	}
	Q->Next = P->Next;
	P->Next = Q;
	return true;
}
bool Delete(int pos, LinkList &L)
{
	if (pos<1 || pos>Length(L))
		return false;//i值不合法，删除失败
	LinkList P, Q;
	if (pos == 1)
	{
		P = L;
		L = L->Next;//改变了传入的指针，要用指针的引用
		free(P);
		return true;
	}
	P = L;
	int j = 1;
	while (j < pos-1)
	{
		P = P->Next;
		j++;
	}
	Q = P->Next;
	P->Next = Q->Next;
	free(Q);
	return true;
}
#endif
