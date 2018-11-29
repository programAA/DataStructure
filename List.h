#ifndef LIST_H
#define LIST_H
#include <iostream>
#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREASE 10//���Ա�洢�ռ�ķ�������
using namespace std;
typedef int ElemType;


typedef struct Node {
	ElemType *elem;//�洢�ռ��ַ
	int size;//��ǰ�洢��
	int maxsize;//��ǰ��������sizeof(ElemType)Ϊ��λ
}*List;
void ReAssign(List L) {
	ElemType *newbase = (ElemType *)realloc(L->elem, (L->maxsize + LIST_INCREASE) * sizeof(ElemType));
	if (newbase == NULL)
	{
		printf("�ռ䲻�㣬���ӷ���ʧ��\n");
		exit(1);//ִ�д˺�����ֹ��������
	}
	L->elem = newbase;
	L->maxsize += LIST_INCREASE;
}
List InitList()//����һ���ձ�
{
	List L = (List)malloc(sizeof(struct Node));
	if (L == NULL) {
		printf("�ռ䲻��");
		exit(1);
	}
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (L->elem == NULL) {
		printf("�ռ䲻��");
		exit(1);
	}
	L->size = 0;
	L->maxsize = LIST_INIT_SIZE;
	return L;
}
bool Empty(List L)//�п����Ա�
{
	return (L->size == 0) ? true : false;
}
int Length(List L)
{
	return L->size;
}
void Insert(List L, int pos, ElemType x)
{
	//��˳�����Ա�L�е�pos��λ��֮ǰ����x
	//i�ĺϷ�ֵΪ1����������L->size+1
	if (pos<1 || pos>Length(L) + 1)//posֵ���Ϸ�
	{
		printf("posֵ���Ϸ�");
		exit(1);
	}
	if (L->size >= L->maxsize)//���������ӷ���
		ReAssign(L);
	for (int i = L->size - 1; i >= pos - 1; i--)
		L->elem[i + 1] = L->elem[i];
	L->elem[pos - 1] = x;
	L->size++;
}
void InsertValue(List L, ElemType value) 
{
	//�����Ա�L�в���ֵvalue
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
void ClearList(List L)//������Ա�
{
	L->size = 0;
}
void DestroyList(List &L)
{   //�������Ա�
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
{//�������Ա��i��Ԫ��
	if (pos<1 || pos>L->size) {
		printf("iֵ����");
		exit(1);
	}
	return L->elem[pos - 1];
}
ElemType Delete(List L, int pos)
{//ɾ����i��Ԫ�أ�ɾ���ɹ��򷵻����Ԫ��
	if (pos<1 || pos>L->size) {
		printf("posֵ����");
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
	if (pos == L->size) //δ�ҵ�value��ɾ��ʧ��
		return false;
	for (int i = pos + 1; i < L->size; i++)
		L->elem[i - 1] = L->elem[i];
	L->size--;
	return true;
}
void Traverse(List L)
{//�������Ա�
	int i;
	for (i = 0; i < L->size; i++) {
		cout << L->elem[i];
		if (i % 10 == 0)
			cout << endl;
	}
}
List Merge(List L1, List L2) {
	//�ϲ�������������Ա��ϲ�����Ȼ����
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
ElemType DeletePos(LinkList &L, int pos)
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
void Traverse(LinkList L) {
	while (L != NULL) {
		cout << L->Data << endl;
		L = L->Next;
	}
}
LinkList Merge(LinkList &L1, LinkList &L2) {
	LinkList L, P1, P2;//L����ͷ���
	if (L1 == NULL && L2 == NULL)
		return NULL;
	if (L1 == NULL) {//L1Ϊ������L2�ǿ�
		L = L2;
		L2 = L2->Next;
	}
	else {//L1�ǿգ�L2����Ϊ�գ����ܷǿ�
		if (L2 == NULL || L1->Data <= L2->Data) {
			L = L1;
			L1 = L1->Next;
		}
		else {//L1,L2���ǿ���L1->Data>L2->Data
			L = L2;
			L2 = L2->Next;
		}
	}
	P1 = L;//P����������칤��
	while (L1 != NULL && L2 != NULL) {
		//��L1��L2�Ľڵ㰴�����й���������ֱ������һ���ڵ�����
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
		else {//L1->Data = L2->Data,ɾ������һ��
			P2 = L2;
			L2 = L2->Next;
			free(P2);
		}
	}
	while (L1 != NULL) {//��L1ʣ�ಿ�ּ���������
		P1->Next = L1;
		P1 = L1;
		L1 = L1->Next;
	}
	while (L2 != NULL) {//��L2ʣ�ಿ�ּ���������
		P1->Next = L2;
		P1 = L2;
		L2 = L2->Next;
	}
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
	LinkList Head;//��������ͷ
	LinkList P1, P2;//P2ָ��Ҫ�ı��㣬P1ָ��ı��P2Ҫָ��Ľ��
	Head = L;
	while (L->Next != NULL) {//ѭ��������Lָ������β������ת�������ͷ
		L = L->Next;
	}
	P2 = L;
	P1 = Head;
	while (P2 != Head) {//�����һ�������ǰһ��һ���ĸı�
		if (P1->Next == P2) {
			P2->Next = P1;
			P2 = P1;
			P1 = Head;
		}
		else
			P1 = P1->Next;
	}
	Head->Next = NULL;
}
void MakeNULL(LinkList &L) {
	LinkList P;
	if (L->Next == L)//ֻ��һ��ͷ���Ŀ�����
		return;
	L = L->Next;//ָ��ͷ���
	P = L->Next;//ָ��ͷ�������Ԫ��
	while (L->Next != L) {
		L->Next = P->Next;
		free(P);
		P = L->Next;
	}
}
bool Judge(LinkList L) {
	return L->Next == L ? true : false;
}
void EnQueue(LinkList &L, ElemType x) {
	LinkList NewP = (LinkList)malloc(sizeof(struct LNode));
	if (NewP == NULL) {
		cout << "��̬�ڴ治��,�����˳�" << endl;
		exit(1);
	}
	NewP->Data = x;
	NewP->Next = L->Next;
	L->Next = NewP;
	L = NewP;
}
ElemType DeQueue(LinkList &L) {
	LinkList P1, P2;
	ElemType temp;
	if (L->Next == L) {
		cout << "����Ϊ�գ��޷�����" << endl;
		exit(1);
	}
	P1 = L->Next;//ָ��ͷ���
	P2 = P1->Next;//ָ��Ҫ���ӵĽ��
	P1->Next = P2->Next;
	temp = P2->Data;
	free(P2);
	if (P1->Next == P1)
		L = P1;
	return temp;
}
#endif