#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode *LinkList;
struct LNode {
	ElemType Data;
	LinkList next;
};
LinkList CreateList()
{
	return NULL;
}
int Length(LinkList L)
{
	LinkList p = L;
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}
LinkList FindKth(int k, LinkList L)
{
	LinkList p = L;
	int i = 1;
	while (p != NULL && i < k)
	{
		p = p->next;
		i++;
	}
	return p;

}
LinkList Find(ElemType x, LinkList L)
{
	LinkList p = L;
	while (p != NULL && p->Data != x)
		p = p->next;
	return p;
}
LinkList Insert(ElemType x, int i, LinkList L)
{
	if (i<1 || i>Length(L) + 1)
	{
		printf("位置错误");
		return NULL;
	}
	LinkList p = L;
	LinkList q = (LinkList)malloc(sizeof(struct LNode));
	q->Data = x;
	if (i == 1)
	{
		q->next = p;
		return q;
	}
	int j = 1;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (i - 1 == j)
	{
		q->next = p->next;
		p->next = q;
	}
	return L;
}
LinkList Delete(int i, LinkList Ptrl)
{
	if (i<1 || i>Length(Ptrl))
	{
		printf("节点不存在");
		return NULL;
	}
	LinkList p, q;
	if (i == 1)
	{
		p = Ptrl;
		Ptrl = Ptrl->next;
		free(p);
		return Ptrl;
	}
	p = Ptrl;
	q = p->next;
	int j = 1;
	while (j < i - 1)
	{
		p = q;
		q = q->next;
		j++;
	}
	p->next = q->next;
	free(q);
	return Ptrl;
}
#endif
