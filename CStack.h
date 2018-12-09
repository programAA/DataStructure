#ifndef CSTACK_H
#define CSTACK_H
#include <iostream>


template <typename T>
struct SNode {
	T Data;
	SNode<T>* Next;
};
template <typename T>
class Stack {
	int Size;
	SNode<T> *Head;//÷∏œÚ’ª∂•
public:
	Stack<T>() : Size(0), Head(NULL) {}
	void Push(T x);
	T Pop();
	bool IsEmpty();
	T GetTop();
	int GetSize();
};

template <typename T>
void Stack<T>::Push(T x) {
	SNode<T> *newP = new SNode<T>;
	newP->Data = x;
	newP->Next = Head;
	Head = newP;
	Size++;
}
template <typename T>
T Stack<T>::Pop() {
	if (Head == NULL) {
		std::cout << "’ªø’,≥ˆ’ª ß∞‹£°" << std::endl;
		exit(1);
	}
	T temp = Head->Data;
	SNode<T>* P = Head;
	Head = Head->Next;
	delete P;
	Size--;
	return temp;
}
template <typename T>
bool Stack<T>::IsEmpty() {
	return Head == NULL ? true : false;
}
template <typename T>
T Stack<T>::GetTop() {
	return Head->Data;
}
template <typename T>
int Stack<T>::GetSize() {
	return Size;
}
#endif