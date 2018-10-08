#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREASE 10//���Ա�洢�ռ�ķ�������
typedef int ElemType;
struct Node {
	ElemType *elem;//�洢�ռ��ַ
	int size;//��ǰ�洢��
	int maxsize;//��ǰ��������sizeof(ElemType)Ϊ��λ
};
typedef struct Node *List;

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
#endif