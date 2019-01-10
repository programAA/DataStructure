#ifndef CQUEUE_H
#define CQUEUE_H
#include <iostream>

template <typename  T>
struct QNode {
	T Data;
	QNode<T> *Next;
	QNode<T>(T data, QNode<T> *next) {
		Data = data;
		Next = next;
	}
};
template <typename T>
class Queue {
	QNode<T>* Front;
	QNode<T>* Rear;
	int Size;
public:
	Queue() :Front(NULL), Rear(NULL), Size(0) {}
	Queue(Queue &Q) {
		Size = Q.Size;
		if (Size==0) {
			Front = Rear = NULL;
		}
		else {
			Front = new QNode<T>(Q.Front->Data, NULL);
			Rear = Front;
			QNode<T> *Qp = Q.Front->Next;
			QNode<T> *Tp;
			while (Qp != NULL) {
				Tp = new QNode<T>(Qp->Data, NULL);
				Rear->Next = Tp;
				Rear = Tp;
				Qp = Qp->Next;
			}
		}
	}
	~Queue() {
		//释放一块内存要做两点:1、释放指向他的指针 2、将该指针指向空
		QNode<T>* P;
		while (Front != NULL) {
			P = Front;
			Front = Front->Next;
			delete P;
		}
		Rear = NULL;
	}
	void EnQueue(T x);
	T DeQueue();
	bool IsEmpty() { return Front == NULL ? true : false; }
	int GetLength() { return Size; }
	void Traverse();
};

template <typename T>
void Queue<T>::EnQueue(T x) {
	QNode<T> *P = new QNode<T>(x,NULL);
	if (Front == NULL)
		Front = Rear = P;
	else {
		Rear->Next = P;
		Rear = P;
	}
	Size++;
}
template <typename T>
T Queue<T>::DeQueue() {
	if (Front == NULL) {
		std::cout << "QUEUE NULL" << std::endl;
		exit(1);
	}
	QNode<T>* P = Front;
	T temp = Front->Data;
	Front = Front->Next;
	if (Front == NULL)//删除一个节点后，队列变为空
		Rear = NULL;//需要把尾指针也指向空
	delete P;
	Size--;
	return temp;
}
template <typename T>
void Queue<T>::Traverse() {
	QNode<T> *Tp = Front;
	int count = 0;
	while ( Tp != NULL) {
		std::cout << std::setw(5) << std::left << Tp->Data;
		Tp = Tp->Next;
		count++;
		if (count % 10 == 0)
			std::cout << std::endl;
	}
}
#endif