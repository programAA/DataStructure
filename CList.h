#pragma once
#include <iostream>
#include <iomanip>

template <typename T>
struct LNode {
	T Data;
	LNode<T> *Next;
	LNode(T data, LNode *next) {
		Data = data;
		Next = next;
	}
};

template <typename T>
class List {
private:
	LNode<T> *Head;
	int Size;
public:
	List() {
		Head = NULL;
		Size = 0;
	}
	List(List &L) {
		Size = L.Size;
		if (L.Size == 0)
			Head = NULL;
		else {
			Head = new LNode<T>(L.Head->Data, NULL);
			LNode<T> *Lp1= Head;
			LNode<T> *Lp = L.Head->Next;
			LNode<T> *Tp;
			while (Lp != NULL) {
				Tp = new LNode<T>(Lp->Data, NULL);
				Lp1->Next = Tp;
				Lp1 = Tp;
				Lp = Lp->Next;
			}
		}
	}
	~List() {
		LNode<T> *Tp;
		while (Head != NULL) {
			Tp = Head;
			Head = Head->Next;
			delete Tp;
		}
	}
	bool IsEmpty() {
		return Size == 0 ? true : false;
	}
	bool IsExist(T x) {
		LNode<T> Lp = Head;
		while (Lp != NULL) {
			if (Lp->Data == x)
				return true;
		}
		return false;
	}
	void SetSize(int size) {
		Size = size;
	}
	void InsertHead(T x) {
		LNode<T> *Tp = new LNode<T>(x, Head);
		Head = Tp;
		Size++;
	}
	void InsertLast(T x) {
		if (Head == NULL) {
			InsertHead(x);
		}
		else {
			LNode<T> *Lp = Head;
			while (Lp->Next != NULL) {
				Lp = Lp->Next;
			}
			Lp->Next = new LNode<T>(x, NULL);;
			Size++;
		}
	}
	void InsertPos(int pos, T x) {
		if (pos < 1 || pos>Size + 1) {
			std::cout << "UnlawfulIndexValue" << std::endl;
		}
		else if (pos == 1) {
			InsertHead(x);
		}
		else if (pos == Size + 1) {
			InsertLast(x);
		}
		else {
			int k = 1;
			LNode<T> *Lp = Head;
			while (k < pos - 1){//退出循环时k=pos-1,k后面即为第pos个位置
				Lp = Lp->Next;
				k++;
			}
			Lp->Next = new LNode<T>(x, Lp->Next);
			Size++;
		}
	}
	void InsertOrder(T x){
		LNode<T> *Tp = new LNode<T>(x, NULL);
		LNode<T> *Lp1 = Head;
		if (Lp1 == NULL || Lp1->Data > x) {
			InsertHead(x);
		}
		else {
			LNode<T> *Lp2 = Head->Next;
			while (Lp2 != NULL && Lp2->Data < x) {
				Lp1 = Lp2;
				Lp2 = Lp2->Next;
			}
			Tp->Next = Lp2;
			Lp1->Next = Tp;
			Size++;
		}


	}
	int GetLength() {
		return Size;
	}
	T GetMax() {
		if (Head == NULL) {
			std::cout << "NULL" << std::endl;
			exit(1);
		}
		LNode<T> *maxNode = Head;
		LNode<T> *Lp = Head->Next;
		while (Lp != NULL) {
			if (Lp->Data > maxNode->Data)
				maxNode = Lp;
			Lp = Lp->Next;
		}
		return maxNode->Data;
	}
	T GetElem(int pos) {
		if (pos<1 || pos>Size) {
			std::cout << "UnlawfulIndexValue" << std::endl;
			exit(1);
		}
		int k = 1;
		LNode<T> *Lp = Head;
		while (Lp != NULL) {
			if (pos == k)
				break;
			Lp = Lp->Next;
			k++;
		}
		return Lp->Data;
	}
	void DeleteHead() {
		if (Size != 0) {
			LNode<T> *Tp = Head;
			Head = Head->Next;
			delete Tp;
			Size--;
		}
	}
	void DeleteLast() {
		if (Size <= 1) {
			DeleteHead();
		}
		else {
			LNode<T> *Lp1 = Head;
			LNode<T> *Lp2 = Head->Next;
			while(Lp2->Next != NULL) {
				Lp1 = Lp2;
				Lp2 = Lp2->Next;
			}
			Lp1->Next = NULL;
			delete Lp2;
			Size--;
		}
	}
	void DeletePos(int pos) {
		if (pos == 1) {
			DeleteHead();
		}
		else if (pos == Size) {
			DeleteLast();
		}
		else {
			LNode<T> *Lp = Head;
			LNode<T> *Tp;
			int k = 1;
			while (k < pos - 1) {
				Lp = Lp->Next;
				k++;
			}
			Tp = Lp->Next;
			Lp->Next = Tp->Next;
			delete Tp;
			Size--;
		}
	}
	bool DeleteValue(T x) {
		//初始化P1和P2指针，使P2指向表头结点，使P1为空
		LNode<T> *P1 = NULL;
		LNode<T> *P2 = Head;
		//从单链表中查找值为x的结点，找到后由P2指向该结点，由P1指向其前驱结点
		while (P2 != NULL) {
			if (P2->Data == x)
				break;
			P1 = P2;
			P2 = P2->Next;
		}
		//若查找失败，即单链表中不存在值为x的结点,则返回false
		if (P2 == NULL)
			return false;
		//对删除的是表头或非表头分别进行处理
		else if (P1 == NULL)
			Head = Head->Next;
		else
			P1->Next = P2->Next;
		delete P2;
		//返回true表示删除成功
		return true;
	}
	void Traverse() {
		LNode<T> *Lp = Head;
		int count = 0;
		while (Lp != NULL) {
			std::cout << std::setw(5) << std::left << Lp->Data;
			count++;
			Lp = Lp->Next;
			if (count % 10 == 0)
				std::cout << std::endl;
		}
		if (count % 10 != 0)
			std::cout << std::endl;
	}
	void Reverse() {
		if (Head == NULL)
			return;
		LNode<T> *P1, *P2, *P3;//P2指向要改变结点，P1指向P2的前驱，P3指向P2的后继
		P1 = NULL;
		P2 = Head;
		P3 = Head->Next;
		while (P3 != NULL) {
			P2->Next = P1;
			P1 = P2;
			P2 = P3;
			P3 = P3->Next;
		}
		P2->Next = P1;
		Head = P2;
	}
	List<T> Merge(List<T> &L2) {
		List<T> L;
		if (Head == NULL && L2.Head == NULL)
			return L;
		L.Head = new LNode<T>(0, NULL);
		LNode<T> *P1, *P2;//P1指向新链表的尾节点,P2指向元素重复时要删除的节点
		P1 = L.Head;
		while ( Head!= NULL && L2.Head!= NULL) {
			if (Head->Data < L2.Head->Data) {
				P1->Next = Head;
				P1 = Head;
				Head = Head->Next;
			}
			else if (Head->Data > L2.Head->Data) {
				P1->Next = L2.Head;
				P1 = L2.Head;
				L2.Head = L2.Head->Next;
			}
			else {//L1.Head->Data = L2.Head->Data,把L1中节点加入链表，删除L2中的节点
				P1->Next = Head;
				P1 = Head;
				Head = Head->Next;
				P2 = L2.Head;
				L2.Head = L2.Head->Next;
				delete P2;
			}
		}
		if (Head != NULL) {
			P1->Next = Head;
			Head = NULL;
		}
		if (L2.Head != NULL) {
			P1->Next = L2.Head;
			L2.Head = NULL;
		}
		P2 = L.Head;
		L.Head = L.Head->Next;
		delete P2;
		//下面置Size值
		int size = 0;
		LNode<T> *Lp = L.Head;
		while (Lp != NULL) {
			Lp = Lp->Next;
			size++;
		}
		L.SetSize(size);
		return L;
	}
};
