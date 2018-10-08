#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LIST_INCREASE 10//线性表存储空间的分配增量
typedef int ElemType;
struct Node {
	ElemType *elem;//存储空间基址
	int size;//当前存储量
	int maxsize;//当前容量，以sizeof(ElemType)为单位
};
typedef struct Node *List;

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
#endif