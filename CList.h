#pragma once
#include <iostream>
#include <iomanip>
#define INIT_SIZE 100
#define ADD_SIZE 10
using namespace std;
typedef int ElemType;
class List {
private:
	ElemType * elem;
	int length;  //��ǰ����
	int size;    //��ǰ����
public:
	List();                 //���캯��
	List(List &L);    //���ƹ��캯��
	~List() { free(elem); } //��������
	void Insert(int i, ElemType x);
	void Traverse();
	void Delete(int i);
	ElemType GetElem(int i);
	int Length() { return length; }
	bool Empty() { return (length == 0) ? true : false; }
	bool Full() { return (length >= size) ? true : false; }
};
List::List() {
	elem = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
	length = 0;
	size = INIT_SIZE;
}
List::List(List &L) {
	elem = L.elem;
	length = L.length;
	size = L.size;
}
void List::Traverse() {
	for (int i = 0; i < length; i++) {
		cout << setw(5) << left << elem[i];
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}
void List::Insert(int i, ElemType x) {
	if (i<1 || i>length + 1) {
		cout << "iֵ���Ϸ�" << endl;
		return;
	}
	if (length >= size) {
		ElemType *newbase = (ElemType*)realloc(elem, (size + ADD_SIZE) * sizeof(ElemType));
		elem = newbase;
		size += ADD_SIZE;
	}
	int j, p = i - 1;
	for (j = length - 1; j >= p; j--)
		elem[j + 1] = elem[j];
	elem[p] = x;
	length++;
}
void List::Delete(int i)
{
	if (i<1 || i>length) {
		cout << "iֵ����";
		return;
	}
	int j, p = i - 1;
	for (j = p; j < length - 1; j++)
		elem[j] = elem[j + 1];
	length--;
}
ElemType List::GetElem(int i) {
	if (i<1 || i>length) {
		cout << "iֵ����";
		return 0;
	}
	return elem[i - 1];
}