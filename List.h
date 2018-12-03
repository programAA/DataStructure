#ifndef LIST_H
#define LIST_H
#include <iostream>
#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LIST_INCREASE 10//线性表存储空间的分配增量
using namespace std;
typedef int ElemType;


typedef struct Node {
	ElemType *elem;//存储空间基址
	int size;//当前存储量
	int maxsize;//当前容量，以sizeof(ElemType)为单位
}*List;
void ReAssign(List L) {
	ElemType *newbase = (ElemType *)realloc(L->elem, (L->maxsize + LIST_INCREASE) * sizeof(ElemType));
	if (newbase == NULL)
	{
		printf("空间不足，增加分配失败\n");
		exit(1);//执行此函数终止程序运行
	}
	L->elem = newbase;
	L->maxsize += LIST_INCREASE;
}
List InitList()//创建一个空表
{
	List L = (List)malloc(sizeof(struct Node));
	if (L == NULL) {
		printf("空间不足");
		exit(1);
	}
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (L->elem == NULL) {
		printf("空间不足");
		exit(1);
	}
	L->size = 0;
	L->maxsize = LIST_INIT_SIZE;
	return L;
}
bool Empty(List L)//判空线性表
{
	return (L->size == 0) ? true : false;
}
int Length(List L)
{
	return L->size;
}
void Insert(List L, int pos, ElemType x)
{
	//在顺序线性表L中第pos个位置之前插入x
	//i的合法值为1—————L->size+1
	if (pos<1 || pos>Length(L) + 1)//pos值不合法
	{
		printf("pos值不合法");
		exit(1);
	}
	if (L->size >= L->maxsize)//表满，增加分配
		ReAssign(L);
	for (int i = L->size - 1; i >= pos - 1; i--)
		L->elem[i + 1] = L->elem[i];
	L->elem[pos - 1] = x;
	L->size++;
}
void InsertValue(List L, ElemType value) 
{
	//在线性表L中插入值value
	if (L->size == L->maxsize)
		ReAssign(L);
	if (Empty(L)) {
		Insert(L, 1, value);
		return;
	}
	int pos;
	for (pos = 0; pos < L->size; pos++) {
		if (value < L->elem[pos])
			break;
	}
	for (int i = L->size - 1; i >= pos; i--)
		L->elem[i + 1] = L->elem[i];
	L->elem[pos] = value;
	L->size++;
}
void ClearList(List L)//清空线性表
{
	L->size = 0;
}
void DestroyList(List &L)
{   //销毁线性表
	if (L->elem != NULL) {
		free(L->elem);
		L->elem = NULL;
	}
	if (L) {
		free(L);
		L = NULL;
	}
}
ElemType GetElem(List L, int pos)
{//返回线性表第i个元素
	if (pos<1 || pos>L->size) {
		printf("i值错误");
		exit(1);
	}
	return L->elem[pos - 1];
}
ElemType Delete(List L, int pos)
{//删除第i个元素，删除成功则返回这个元素
	if (pos<1 || pos>L->size) {
		printf("pos值错误");
		exit(1);
	}
	ElemType temp = L->elem[pos - 1];
	for (int i = pos; i < L->size; i++)
		L->elem[i - 1] = L->elem[i];
	L->size--;
	return temp;
}
bool DeleteValue(List L, int value) {
	int pos;
	for (pos = 0; pos < L->size; pos++)
		if (L->elem[pos] == value)
			break;
	if (pos == L->size) //未找到value，删除失败
		return false;
	for (int i = pos + 1; i < L->size; i++)
		L->elem[i - 1] = L->elem[i];
	L->size--;
	return true;
}
void Traverse(List L)
{//遍历线性表
	int i;
	for (i = 0; i < L->size; i++) {
		cout << L->elem[i];
		if (i % 10 == 0)
			cout << endl;
	}
}
List Merge(List L1, List L2) {
	//合并两个有序的线性表，合并后仍然有序
	List L3 = InitList();
	int i = 1, j = 1, k = 0;
	ElemType a, b;
	while (i <= L1->size&&j <= L2->size) {
		a=GetElem(L1, i);
		b=GetElem(L2, j);
		if (a <= b) {
			Insert(L3, k++, a);
			i++;
		}
		else {
			Insert(L3, k++, b);
			j++;
		}
	}
	while (i <= L1->size) {
		a = GetElem(L1, i);
		Insert(L3, k++, a);
	}
	while (j <= L2->size) {
		b = GetElem(L2, j);
		Insert(L3, k++, b);
	}
	return L3;
}


typedef struct LNode {
	ElemType Data;
	struct LNode*  Next;
}*LinkList;
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
	while (L)
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
ElemType DeletePos(LinkList &L, int pos)
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
void Traverse(LinkList L) {
	while (L != NULL) {
		cout << L->Data << endl;
		L = L->Next;
	}
}
LinkList Merge(LinkList &L1, LinkList &L2) {
	if (L1 == NULL && L2 == NULL)
		return NULL;
	LinkList L = (LinkList)malloc(sizeof(struct LNode));//L保存新链表头结点
	LinkList P1, P2;//P1指向新链表的尾节点,P2指向元素重复时要删除的节点
	P1 = L;
	while (L1 != NULL && L2 != NULL) {
		if (L1->Data < L2->Data) {
			P1->Next = L1;
			P1 = L1;
			L1 = L1->Next;
		}
		else if (L1->Data > L2->Data) {
			P1->Next = L2;
			P1 = L2;
			L2 = L2->Next;
		}
		else {//L1->Data = L2->Data,把L1中节点加入链表，删除L2中的节点
			P1->Next = L1;
			P1 = L1;
			L1 = L1->Next;
			P2 = L2;
			L2 = L2->Next;
			free(P2);
		}
	}
	if (L1 != NULL) {
		P1->Next = L1;
		L1 = NULL;
	}
	if (L2 != NULL) {
		P1->Next = L2;
		L2 = NULL;
	}
	P2 = L;
	L = L->Next;
	free(P2);
	return L;
}
LinkList FindMax(LinkList L) {
	ElemType max;
	LinkList maxNode;
	if (L != NULL) {
		max = L->Data;
		maxNode = L;
	}
	while (L->Next != NULL) {
		L = L->Next;
		if (L->Data > max) {
			max = L->Data;
			maxNode = L;
		}
	}
	return maxNode;
}
void Reverse(LinkList &L) {
	if (L == NULL)
		return;
	LinkList P1, P2, P3;//P2指向要改变结点，P1指向P2的前驱，P3指向P2的后继
	P1 = NULL;
	P2 = L;
	P3 = L->Next;
	while (P3 != NULL) {
		P2->Next = P1;
		P1 = P2;
		P2 = P3;
		P3 = P3->Next;
	}
	P2->Next = P1;
	L = P2;
}
#endif