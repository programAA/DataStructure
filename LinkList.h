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

void ClearLinkList(LinkList &L) {
	LinkList P;
	while (L != NULL) {
		P = L;
		L = L->Next;
		free(P);
	}
}

int Length(LinkList L)
{
	int size = 0;
	while(L)
	{
		L = L->Next;
		size++;
	}
	return size;
}

bool IsEmptyLinkList(LinkList L) {
	if (L == NULL)
		return true;
	else
		return false;
}

ElemType GetElem(LinkList L, int k)
{
	if (k < 1) {
		cout << "kֵ���Ϸ�,�����쳣�˳�" << endl;
		exit(1);
	}
	int pos = 1;
	while (L != NULL) {
		if (pos == k)
			break;
		L = L->Next;
		pos++;
	}
	if (L == NULL) {
		cout << "kֵ���Ϸ��������쳣�˳�" << endl;
	}
	return L->Data;
}

LinkList FindKLinkList(LinkList L, ElemType x)
{
	LinkList P = L;
	while (P != NULL && P->Data != x)
		P = P->Next;
	if (P == NULL) {
		cout << "δ�ҵ�Ҫ���ҵ�ֵ" << endl;
	}
	return P;
}

bool UpdatePosLinkList(LinkList L, int pos, ElemType x) {
	int i = 1;
	if (pos < 1)
		return false;
	while (L) {
		if (pos == i)
			break;
		L = L->Next;
		i++;
	}
	if (L == NULL)//posֵ����Length(L)
		return false;
	L->Data = x;
	return true;
}

void InsertFirst(LinkList &L, int x) {
	LinkList P = (LinkList)malloc(sizeof(struct LNode));
	if (P == NULL) {
		cout << "��̬�ڴ治�㣬�����˳�" << endl;
		exit(1);
	}
	P->Data = x;
	P->Next = L;
	L = P;
}

void InsertLast(LinkList &L, int x) {

	LinkList P = (LinkList)malloc(sizeof(struct LNode));
	if (P == NULL) {
		cout << "��̬�ڴ治�㣬�����˳�" << endl;
		exit(1);
	}
	P->Data = x;
	P->Next = NULL;
	if (L == NULL)
		L = P;
	else {
		LinkList P1 = L;
		while (P1->Next) {
			P1 = P1->Next;
		}
		P1->Next = P;
	}
}


bool InsertPos(LinkList &L, int pos, ElemType x)
{
	if (pos < 1 || pos>Length(L) + 1)
		return false;//posֵ����
	LinkList P = (LinkList)malloc(sizeof(struct LNode));
	if (P == NULL) {
		cout << "��̬�ڴ治�㣬�����˳�" << endl;
		exit(1);
	}
	P->Data = x;
	P->Next = NULL;
	if (pos == 1) {//���ڱ�ͷ
		P->Next = L;
		L = P;
		return true;
	}
	else {
		LinkList P1 = L;
		int i = 1;
		while (i < pos - 1)//Pָ���i���ڵ�
		{//�˳�ѭ��ʱi=pos-1,i���漴Ϊ��pos��λ��
			P1 = P1->Next;
			i++;
		}
		P->Next = P1->Next;
		P1->Next = P;
		return true;
	}
}

void InsertOrder(LinkList &L, ElemType x) {
	LinkList P = (LinkList)malloc(sizeof(struct LNode));
	if (P == NULL) {
		cout << "��̬�ڴ治�㣬�����˳�" << endl;
		exit(1);
	}
	P->Data = x;
	if (L == NULL || L->Data > x) {
		P->Next = L;
		L = P;
		return;
	}
	else {
		LinkList P1 = L;
		LinkList P2 = L->Next;
		while (P2 != NULL && P2->Data < x) {
			P1 = P2;
			P2 = P2->Next;
		}
		P->Next = P2;
		P1->Next = P;
	}
}

ElemType DeleteFirst(LinkList &L) {
	//ɾ����ͷ������ɾ���ڵ������
	if (L == NULL) {
		cout << "ɾ��ʧ�ܣ������˳�" << endl;
		exit(1);
	}
	ElemType temp = L->Data;
	LinkList P = L;
	L = L->Next;
	free(P);
	return temp;
}

ElemType DeleteLast(LinkList &L) {
	//ɾ����β������ɾ��������
	if (L == NULL) {//�ձ�
		cout << "ɾ��ʧ�ܣ������˳�" << endl;
		exit(1);
	}
	ElemType temp;
	LinkList P1 = NULL;
	LinkList P2 = L;
	while (P2->Next != NULL) {
		P1 = P2;
		P2 = P2->Next;
	}
	if (P1 == NULL)//����ֻ��һ��Ԫ�أ���ͷָ���޸�ΪNULL
		L = L->Next;
	else//�޸ı�β
		P1->Next = NULL;
	temp = P2->Data;
	free(P2);
	return temp;
}


ElemType DeletePos( LinkList &L,int pos)
{
	if (pos < 1 || L == NULL) {
		cout << "posֵ�Ƿ����Ϊ�գ������˳�" << endl;
		exit(1);
	}
	ElemType temp;
	LinkList P1 = NULL;
	LinkList P2 = L;
	int i = 1;
	/*�ӵ������в��ҵ�pos����㣬�ҵ�����P2ָ��ýڵ㣬��P1ָ����ǰ�����*/  
	while (P2 != NULL) {  
		if (i == pos) 
			break;   
		i++;
		P1 = P2;
		P2 = P2->Next;
	}
	if (P2 == NULL) {//����û�е�pos���ڵ�
		cout << "posֵ�Ƿ��������˳�" << endl;
		exit(1);
	}
	if (pos == 1)
		L = L->Next;
	else
		P1->Next = P2->Next;
	temp = P2->Data;
	free(P2);
	return temp;
}

bool DeteteValue(LinkList &L, ElemType x) {
	/*��ʼ��P1��P2ָ�룬ʹP2ָ���ͷ��㣬ʹP1Ϊ��*/
	LinkList P1 = NULL;
	LinkList P2 = L;
	/*�ӵ������в���ֵΪx�Ľ�㣬�ҵ�����P2ָ��ý�㣬��P1ָ����ǰ�����*/
	while (P2 != NULL) {
		if (P2->Data == x)
			break;
		P1 = P2;
		P2 = P2->Next;
	}
	/*������ʧ�ܣ����������в�����ֵΪx�Ľ��,�򷵻�false*/
	if (P2 == NULL)
		return false;
	/*��ɾ�����Ǳ�ͷ��Ǳ�ͷ�ֱ���д���*/
	if (P1 == NULL)
		L = L->Next;
	else
		P1->Next = P2->Next;
	free(P2);
	/*����true��ʾɾ���ɹ�*/  
	return true;
}
#endif