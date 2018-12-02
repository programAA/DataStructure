#ifndef CQUEUE_H
#define CQUEUE_H
#include <iostream>
template <class T>
struct QNode {
	T Data;
	QNode<T> *Next;
};
template <class T>
class Queue {
	QNode<T>* Front;
	QNode<T>* Rear;
	int Size;
public:
	Queue() :Front(NULL), Rear(NULL), Size(0) {}
	void EnQueue(T x);
	T DeQueue();
	bool IsEmpty() { return Front == NULL ? true : false; }
	int GetSize() { return Size; }
	void Destroy();
};

template <class T>
void Queue<T>::EnQueue(T x) {
	QNode<T> *P = new QNode<T>;
	P->Data = x;
	P->Next = NULL;
	if (Front == NULL)
		Front = Rear = P;
	else {
		Rear->Next = P;
		Rear = P;
	}
	Size++;
}
template <class T>
T Queue<T>::DeQueue() {
	if (Front == NULL) {
		std::cout << "队列为空,无法出队！！" << std::endl;
		exit(1);
	}
	QNode<T>* P = Front;
	T temp = Front->Data;
	Front = Front->Next;
	if (Front == NULL)
		Rear = NULL;
	delete P;
	Size--;
	return temp;
}
template <class T>
void Queue<T>::Destroy() {
	QNode<T>* P;
	while (Front != NULL) {
		P = Front;
		Front = Front->Next;
		delete(P);
	}
	Rear = NULL;
	Size = 0;
}
#endif