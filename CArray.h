#pragma once
#include <iostream>
//�ɱ��С������
class CArray {
	int Capacity;
	int Size;
	int *ptr;
public:
	CArray(int s = 0);
	CArray(CArray &a);//�������캯��
	~CArray();
	void push_back(int V);
	CArray &operator=(const CArray &a);//��Ҫ���
	int size() { return Size; }
	int capacity() { return Capacity; }
	int &operator[](int i) {
		return ptr[i];
	}
};
CArray::CArray(int s) :Capacity(s),Size(0){
	if (s == 0)
		ptr = NULL;
	else
		ptr = new int[s];
}
CArray::CArray(CArray &a) {//���ƹ��캯��
	if (!a.ptr) {//a.ptrΪ��ָ��
		ptr = NULL;
		Size = 0;
		Capacity = 0;
		return;
	}
	ptr = new int[a.Capacity];
	memcpy(ptr, a.ptr, sizeof(int)*a.Size);
	Size = a.Size;
	Capacity = a.Capacity;
}
CArray::~CArray() {
	if (ptr) delete[]ptr;//ptr��Ϊ��,�ͷſռ�
}
CArray &CArray::operator=(const CArray &a){
	if (ptr == a.ptr)
		return *this;
	if (a.ptr == NULL) {
		if (ptr) delete[]ptr;
		ptr = NULL;
		Size = 0;
		Capacity = 0;
		return *this;
	}
	if (Capacity!=a.Capacity) {
		if (ptr) delete[]ptr;
		ptr = new int[a.Capacity];
	}
	memcpy(ptr, a.ptr, sizeof(int)*a.Size);
	Size = a.Size;
	Capacity = a.Capacity;
	return *this;
}
void CArray::push_back(int v) {
	if(ptr==NULL){
		ptr = new int[32];
		Capacity += 32;
	}
	else{
		if (Size == Capacity) {
			int *temptr = new int[Capacity * 2];
			memcpy(temptr, ptr, sizeof(int)*Size);
			delete[]ptr;
			ptr = temptr;
			Capacity *= 2;
		}
	}
	ptr[Size++] = v;
}