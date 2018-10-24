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
		cout << "k值不合法,程序异常退出" << endl;
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
		cout << "k值不合法，程序异常退出" << endl;
	}
	return L->Data;
}

LinkList FindKLinkList(LinkList L, ElemType x)
{
	LinkList P = L;
	while (P != NULL && P->Data != x)
		P = P->Next;
	if (P == NULL) {
		cout << "未找到要查找的值" << endl;
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
	if (L == NULL)//pos值大于Length(L)
		return false;
	L->Data = x;
	return true;
}

void InsertFirst(LinkList &L, int x) {
	LinkList P = (LinkList)malloc(sizeof(struct LNode));
	if (P == NULL) {
		cout << "动态内存不足，程序退出" << endl;
		exit(1);
	}
	P->Data = x;
	P->Next = L;
	L = P;
}

void InsertLast(LinkList &L, int x) {

	LinkList P = (LinkList)malloc(sizeof(struct LNode));
	if (P == NULL) {
		cout << "动态内存不足，程序退出" << endl;
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
		return false;//pos值错误
	LinkList P = (LinkList)malloc(sizeof(struct LNode));
	if (P == NULL) {
		cout << "动态内存不足，程序退出" << endl;
		exit(1);
	}
	P->Data = x;
	P->Next = NULL;
	if (pos == 1) {//插在表头
		P->Next = L;
		L = P;
		return true;
	}
	else {
		LinkList P1 = L;
		int i = 1;
		while (i < pos - 1)//P指向第i个节点
		{//退出循环时i=pos-1,i后面即为第pos个位置
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
		cout << "动态内存不足，程序退出" << endl;
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
	//删除表头，返回删除节点的数据
	if (L == NULL) {
		cout << "删除失败，程序退出" << endl;
		exit(1);
	}
	ElemType temp = L->Data;
	LinkList P = L;
	L = L->Next;
	free(P);
	return temp;
}

ElemType DeleteLast(LinkList &L) {
	//删除表尾，返回删除的数据
	if (L == NULL) {//空表
		cout << "删除失败，程序退出" << endl;
		exit(1);
	}
	ElemType temp;
	LinkList P1 = NULL;
	LinkList P2 = L;
	while (P2->Next != NULL) {
		P1 = P2;
		P2 = P2->Next;
	}
	if (P1 == NULL)//表中只有一个元素，表头指针修改为NULL
		L = L->Next;
	else//修改表尾
		P1->Next = NULL;
	temp = P2->Data;
	free(P2);
	return temp;
}


ElemType DeletePos( LinkList &L,int pos)
{
	if (pos < 1 || L == NULL) {
		cout << "pos值非法或表为空，程序退出" << endl;
		exit(1);
	}
	ElemType temp;
	LinkList P1 = NULL;
	LinkList P2 = L;
	int i = 1;
	/*从单链表中查找第pos个结点，找到后由P2指向该节点，由P1指向其前驱结点*/  
	while (P2 != NULL) {  
		if (i == pos) 
			break;   
		i++;
		P1 = P2;
		P2 = P2->Next;
	}
	if (P2 == NULL) {//表中没有第pos个节点
		cout << "pos值非法，程序退出" << endl;
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
	/*初始化P1和P2指针，使P2指向表头结点，使P1为空*/
	LinkList P1 = NULL;
	LinkList P2 = L;
	/*从单链表中查找值为x的结点，找到后由P2指向该结点，由P1指向其前驱结点*/
	while (P2 != NULL) {
		if (P2->Data == x)
			break;
		P1 = P2;
		P2 = P2->Next;
	}
	/*若查找失败，即单链表中不存在值为x的结点,则返回false*/
	if (P2 == NULL)
		return false;
	/*对删除的是表头或非表头分别进行处理*/
	if (P1 == NULL)
		L = L->Next;
	else
		P1->Next = P2->Next;
	free(P2);
	/*返回true表示删除成功*/  
	return true;
}
#endif