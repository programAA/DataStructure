#pragma once
#include <iostream>
#include <iomanip>
#define INIT_SIZE 100
#define ADD_SIZE 10
using namespace std;
typedef int ElemType;
class Class_List {
private:
	ElemType * elem;
	int length;  //当前长度
	int size;    //当前容量
public:
	Class_List();                 //构造函数
	Class_List(Class_List &L);    //构造函数
	~Class_List() { free(elem); } //析构函数
	void Insert(int i, ElemType x);
	void Traverse();
	void Delete(int i);
	ElemType GetElem(int i);
	int Length() { return length; }
	bool Empty() { return (length == 0) ? true : false; }
	bool Full() { return (length >= size) ? true : false; }
};
Class_List::Class_List() {
	elem = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
	length = 0;
	size = INIT_SIZE;
}
Class_List::Class_List(Class_List &L) {
	elem = L.elem;
	length = L.length;
	size = L.size;
}
void Class_List::Traverse() {
	for (int i = 0; i < length; i++) {
		cout << setw(5) << left << elem[i];
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
}
void Class_List::Insert(int i, ElemType x) {
	if (i<1 || i>length + 1) {
		cout << "i值不合法" << endl;
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
void Class_List::Delete(int i)
{
	if (i<1 || i>length) {
		cout << "i值错误";
		return;
	}
	int j, p = i - 1;
	for (j = p; j < length - 1; j++)
		elem[j] = elem[j + 1];
	length--;
}
ElemType Class_List::GetElem(int i) {
	if (i<1 || i>length) {
		cout << "i值错误";
		return 0;
	}
	return elem[i - 1];
}