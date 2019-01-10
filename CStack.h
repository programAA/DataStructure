#ifndef CSTACK_H
#define CSTACK_H
#include <iostream>

template <typename T>
struct SNode {
	T Data;
	SNode<T>* Next;
	SNode(T data,SNode<T> *next) {
		Data = data;
		Next = next;
	}
};


template <typename T>
class Stack {
	int Size;
	SNode<T> *Head;//÷∏œÚ’ª∂•
public:
	Stack<T>() : Size(0), Head(NULL) {}
	Stack<T>(Stack<T> &S) {
		Size = S.Size;
		if (Size == 0)
			Head = NULL;
		else {
			Head = new SNode<T>(Head->Data, NULL);
			SNode<T> *Tp = Head;
			SNode<T> *Sp = S.Head->Next;
			while (Sp != NULL) {
				SNode<T> *temp = new SNode<T>(Sp->Data, NULL);
				Tp->Next = temp;
				Sp = Sp->Next;
			}
		}
	}
	void Push(T x);
	T Pop();
	bool IsEmpty();
	T GetTop();
	int GetLength();
};

template <typename T>
void Stack<T>::Push(T x) {
	SNode<T> *newP = new SNode<T>(x, Head);
	Head = newP;
	Size++;
}
template <typename T>
T Stack<T>::Pop() {
	if (Head == NULL) {
		std::cout << "TheStackIsEmpty" << std::endl;
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
int Stack<T>::GetLength() {
	return Size;
}
#endif