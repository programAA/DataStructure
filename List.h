#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <iomanip>
#define LIST_INIT_SIZE 32//���Ա�洢�ռ�ĳ�ʼ������

//��������ڴ���ʱ�����������
//1�������ǰ�ڴ�κ�������Ҫ���ڴ�ռ䣬��ֱ����չ����ڴ�ռ䣬realloc����ԭָ��
//2�������ǰ�ڴ�κ���Ŀ����ֽڲ�������ô��ʹ�ö��еĵ�һ���ܹ�������һҪ����ڴ��
//   ��Ŀǰ�����ݸ��Ƶ��µ�λ�ã�����ԭ�����ڴ���ͷŵ��������µ��ڴ��λ��
//3���������ʧ�ܣ�������NULL����ʱ��ԭ����ָ����Ȼ��Ч
template <typename T>
class List {
private:
	T * Elem;
	int Length;  //��ǰ����
	int Size;    //��ǰ����
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
	List(List &L) {//���ƹ��캯��
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
	~List() { //��������
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