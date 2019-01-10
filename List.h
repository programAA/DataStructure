#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <iomanip>
#define LIST_INIT_SIZE 32//线性表存储空间的初始分配量

//将分配的内存变大时，有以下情况
//1、如果当前内存段后面有需要的内存空间，则直接扩展这段内存空间，realloc返回原指针
//2、如果当前内存段后面的空闲字节不够，那么就使用堆中的第一个能够满足这一要求的内存块
//   将目前的数据复制到新的位置，并将原来的内存块释放掉，返回新的内存块位置
//3、如果申请失败，将返回NULL，此时，原来的指针仍然有效
template <typename T>
class List {
private:
	T * Elem;
	int Length;  //当前长度
	int Size;    //当前容量
public:
	List() {
		Elem = (T*)malloc(LIST_INIT_SIZE * sizeof(T));
		if (Elem == NULL) {
			std::cout << "InsufficientDynamicMemory" << std::endl;
			exit(1);
		}
		Length = 0;
		Size = LIST_INIT_SIZE;
	}
	List(List &L) {//复制构造函数
		Length = L.Length;
		Size = L.Size;
		Elem = (T*)malloc(Size * sizeof(T));
		if (Elem == NULL) {
			std::cout << "InsufficientDynamicMemory" << std::endl;
			exit(1);
		}
		for (int i = 0; i < Length; i++) {
			Elem[i] = L.Elem[i];
		}
	}
	~List() { //析构函数
		free(Elem);
	}
	void ReAssign() {
		T *newbase = (T*)realloc(Elem, Size * 2 * sizeof(T));
		if (newbase == NULL) {
			std::cout << "InsufficientDynamicMemory" << std::endl;
			exit(1);
		}
		Elem = newbase;
		Size *= 2;
	}
	int GetLength() { return Length; }
	int GetSize() { return Size; }
	bool IsEmpty() { return (Length == 0) ? true : false; }
	bool Full() { return (Length == Size) ? true : false; }
	void InsertHead(T x);
	void InsertLast(T x);
	void InsertPos(int pos, T x);
	void InsertOrder(T x);
	void DeleteHead();
	void DeleteLast();
	void DeletePos(int pos);
	void DeleteValue(T x);
	T GetElem(int pos);
	List<T> Merge(const List &L1);
	void Traverse();
};

template <typename T>
void List<T>::InsertHead(T x) {
	if (Length == Size) {
		ReAssign();
	}
	for (int i = Length - 1; i >= 0; i--)
		Elem[i + 1] = Elem[i];
	Elem[0] = x;
	Length++;
}
template <typename T>
void List<T>::InsertLast(T x) {
	if (Length == Size) {
		ReAssign();
	}
	Elem[Length] = x;
	Length++;
}
template <typename T>
void List<T>::InsertPos(int pos, T x) {
	if (pos<1 || pos>Length + 1) {
		std::cout << "UnlawfulIndexValue" << std::endl;
	}
	else {
		if (Length == Size) {
			ReAssign();
		}
		int j, p = pos - 1;
		for (j = Length - 1; j >= p; j--)
			Elem[j + 1] = Elem[j];
		Elem[p] = x;
		Length++;
	}
}
template <typename T>
void List<T>::InsertOrder(T x) {
	if (Length == Size) {
		ReAssign();
	}
	else if (IsEmpty()) {
		InsertHead(x);
	}
	else {
		int pos;
		for (pos = 0; pos < Length; pos++) {
			if (x < Elem[pos])
				break;
		}
		for (int i = Length - 1; i >= pos; i--)
			Elem[i + 1] = Elem[i];
		Elem[pos] = x;
		Length++;
	}
}
template <typename T>
void List<T>::DeleteHead() {
	if (Length != 0) {
		for (int i = 0; i < Length - 1; i++)
			Elem[i] = Elem[i + 1];
		Length--;
	}
}
template <typename T>
void List<T>::DeleteLast() {
	if (Length != 0) {
		Length--;
	}
}
template <typename T>
void List<T>::DeletePos(int pos) {
	if (pos<1 || pos>Length) {
		std::cout << "UnlawfulIndexValue" << std::endl;
	}
	else {
		int j, p = pos - 1;
		for (j = p; j < Length - 1; j++)
			Elem[j] = Elem[j + 1];
		Length--;
	}
}
template <typename T>
void List<T>::DeleteValue(T x) {
	int pos;
	for (pos = 0; pos < Length; pos++) {
		if (x == Elem[pos])
			break;
	}
	if (pos == Length) {
		std::cout << "ValueNotExist" << endl;
	}
	else {
		for (int i = pos; i < Length - 1; i++) {
			Elem[i] = Elem[i + 1];
		}
		Length--;
	}
}
template <typename T>
T List<T>::GetElem(int pos) {
	if (pos<1 || pos>Length) {
		std::cout << "UnlawfulIndexValue" << std::endl;
		exit(1);
	}
	return Elem[pos - 1];
}
template <typename T>
List<T> List<T>::Merge(const List &L) {
	List<T> L2;
	int a = 0, b = 0;
	while (a < Length && b < L.Length) {
		if (Elem[a] < L.Elem[b]) {
			L2.InsertLast(Elem[a]);
			a++;
		}
		else if (Elem[a] == L.Elem[b]) {
			L2.InsertLast(Elem[a]);
			a++;
			b++;
		}
		else {
			L2.InsertLast(L.Elem[b]);
			b++;
		}
	}
	while (a < Length) {
		L2.InsertLast(Elem[a]);
		a++;
	}
	while (b < L.Length) {
		L2.InsertLast(L.Elem[b]);
		b++;
	}
	return L2;
}
template <typename T>
void List<T>::Traverse() {
	for (int i = 0; i < Length; i++) {
		std::cout << std::setw(5) << std::left << Elem[i];
		if ((i + 1) % 10 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}
#endif