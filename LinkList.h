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
		cout << "kֵ���Ϸ�,�����쳣�˳�" << endl;
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
		cout << "δ�ҵ�Ҫ���ҵ�ֵ" << endl;
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
		L = Q;//ָ��ı��ˣ�Ҫ��ָ�������
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
		return false;//iֵ���Ϸ���ɾ��ʧ��
	LinkList P, Q;
	if (pos == 1)
	{
		P = L;
		L = L->Next;//�ı��˴����ָ�룬Ҫ��ָ�������
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
