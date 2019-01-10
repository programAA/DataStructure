#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <iomanip>
#include "Stack.h"
#include "Queue.h"

template <typename T>
struct TNode {
	T Data;
	TNode<T> *Left, *Right;
	TNode<T>(T data) {
		Data = data;
		Left = NULL;
		Right = NULL;
	}
	TNode<T>(T data, TNode<T>*left, TNode<T>*right) {
		Data = data;
		Left = left;
		Right = right;
	}
};

template <typename T>
class Tree {
	TNode<T>* Head;
public:
	Tree<T>() : Head(NULL) {}
	Tree<T>(Tree<T> &T) {

	}
	int Depth() {
		return DepthAchieve(Head);
	}
	int DepthAchieve(TNode<T>* P) {
		if (P == NULL)
			return 0;
		else {
			int d1 = DepthAchieve(P->Left);
			int d2 = DepthAchieve(P->Right);
			if (d1 > d2)
				return d1 + 1;
			else
				return d2 + 1;
		}
	}
	TNode<T>* Find1(T x) {
		TNode<T>* P = Head;
		while (P != NULL) {
			if (x < P->Data)
				P = P->Left;
			else if (x > P->Data)
				P = P->Right;
			else
				return P;
		}
		return NULL;
	}
	TNode<T>* Find2(T x) {
		return Find2Achieve(Head, x);
	}
	TNode<T>* Find2Achieve(TNode<T>* P, T x) {
		if (P == NULL)
			return NULL;
		else {
			if (x == P->Data)
				return P;
			else if (x > P->Data)
				return Find2Achieve(P->Right, x);
			else
				return Find2Achieve(P->Left, x);
		}
	}
	TNode<T>* Find3(T x) {
		return Find2Achieve(Head, x);
	}
	TNode<T>* Find3Achieve(TNode<T>* P, T x) {
		//非二叉排序树二叉树查找
		if (P == NULL)
			return NULL;
		else {
			if (P->Data == x)
				return P;
			else {
				TNode<T>* P1;
				if (P1 = Find3Achieve(P->Left, x))
					return P1;
				if (P1 = Find3Achieve(P->Right, x))
					return P1;
				return NULL;
			}
		}
	}
	TNode<T>* FindMin() {
		TNode<T> *P = Head;
		if (P != NULL)
			while (P->Left != NULL)
				P = P->Left;
		return P;
	}
	TNode<T>* FindMin(TNode<T>* P) {
		if (P != NULL)
			while (P->Left != NULL)
				P = P->Left;
		return P;
	}
	TNode<T>* FindMax() {
		TNode<T> *P = Head;
		if (P == NULL || P->Right == NULL)
			return P;
		else
			return FindMax(P->Right);
	}
	TNode<T>* FindMax(TNode<T>* P) {
		if (P != NULL)
			while (P->Right != NULL)
				P = P->Right;
		return P;
	}
	void Insert(T x) {
		InsertAchieve(Head, x);
	}
	void InsertAchieve(TNode<T> *&P, T x) {
		if (P == NULL)
			P = new TNode<T>(x);
		else {
			if (x < P->Data)
				InsertAchieve(P->Left, x);
			else
				InsertAchieve(P->Right, x);
		}
	}
	void Delete(T x) {
		DeleteAchieve(Head, x);
	}
	void DeleteAchieve(TNode<T> *&P, T x) {
		TNode<T>* P1;
		if (P == NULL)
			std::cout << "ValueNotExist" << std::endl;
		else if (x < P->Data)
			DeleteAchieve(P->Left, x);
		else if (x > P->Data)
			DeleteAchieve(P->Right, x);
		else {
			if (P->Left != NULL && P->Right != NULL) {
				P1 = FindMax(P->Left);//或者FindMinAchieve(P->Right)
				P->Data = P1->Data;
				DeleteAchieve(P->Left, P->Data);
			}
			else {//只存在一个子节点或不存在子节点
				P1 = P;
				if (P->Left == NULL)//存在右子节点或无子节点
					P = P->Right;
				else //存在左孩子
					P = P->Left;
				delete P1;
			}
		}
	}
	void PreOrder1() {
		PreOrder1Achieve(Head);
	}
	void PreOrder1Achieve(TNode<T>* P) {
		if (P != NULL) {
			std::cout << P->Data << std::endl;
			PreOrder1Achieve(P->Left);
			PreOrder1Achieve(P->Right);
		}
	}
	void PreOrder2() {
		Stack<TNode<T>*> S;
		TNode<T>* P;
		if (Head != NULL)
			S.Push(Head);
		while (!S.IsEmpty()) {
			P = S.Pop();
			std::cout << P->Data << std::endl;
			if (P->Right != NULL)
				S.Push(P->Right);
			if (P->Left != NULL)
				S.Push(P->Left);
		}
	}
	void PreOrder3() {
		Stack<TNode<T>*> S;
		TNode<T>* P = Head;
		while (P != NULL || !S.IsEmpty()){
			while (P != NULL){
				std::cout << P->Data << std::endl;
				S.Push(P);
				P = P->Left;
			}
			if (!S.IsEmpty()){
				P = S.Pop();
				P = P->Right;
			}
		}
	}
	void MidOrder1() {
		MidOrder1Achieve(Head);
	}
	void MidOrder1Achieve(TNode<T>* P) {
		if (P != NULL) {
			MidOrder1Achieve(P->Left);
			std::cout << P->Data << std::endl;
			MidOrder1Achieve(P->Right);
		}
	}
	void MidOrder2() {
		Stack<TNode<T>*> S;
		TNode<T>* P = Head;
		while (P != NULL || !S.IsEmpty()) {
			while (P != NULL) {
				S.Push(P);
				P = P->Left;
			}
			if (!S.IsEmpty()) {
				P = S.Pop();
				std::cout << P->Data << std::endl;
				P = P->Right;
			}
		}
	}
	void PostOrder1() {
		PostOrder1Achieve(Head);
	}
	void PostOrder1Achieve(TNode<T>* P) {
		if (P != NULL) {
			PostOrder1Achieve(P->Left);
			PostOrder1Achieve(P->Right);
			std::cout << P->Data << std::endl;
		}
	}
	void PostOrder2() {
		Stack<TNode<T>*> S;
		TNode<T>* P = Head;
		TNode<T>* pre = NULL;//前一个
		TNode<T>* cur;//当前
		S.Push(P);
		while (!S.IsEmpty()) {
			cur = S.GetTop();
			if ((cur->Left == NULL && cur->Right == NULL) ||
				(pre != NULL && (pre == cur->Left || pre == cur->Right)))
			{//当前节点的左右儿子均不存在或前一个访问的节点存在且是当前节点的左右儿子之一
				std::cout << cur->Data << std::endl;//打印当前节点
				pre = cur;
				S.Pop();
			}
			else {
				if (cur->Right != NULL)
					S.Push(cur->Right);
				if (cur->Left != NULL)
					S.Push(cur->Left);
			}
		}
	}
	void LayerOrder() {
		TNode<T> *P;
		Queue<TNode<T>*> Q;
		if (Head != NULL)
			Q.EnQueue(Head);
		while (!Q.IsEmpty()) {
			P = Q.DeQueue();
			std::cout << P->Data << std::endl;
			if (P->Left != NULL)
				Q.EnQueue(P->Left);
			if (P->Right != NULL)
				Q.EnQueue(P->Right);
		}
	}
};



template <typename T,int K>
struct KTNode {
	T Data;
	KTNode<T,K>* C[K];
	KTNode<T, K>(T data) {
		Data = data;
		for (int i = 0; i < K; i++)
			C[i] = NULL;
	}
};
template <typename T,int K>
class KTree {
private:
	KTNode<T, K>* Head;
public:
	KTree<T, K>() {
		Head = NULL;
	}
	void PreOrder() {
		PreOrderAchieve(Head);
	}
	void PreOrderAchieve(KTNode<T, K>* P) {
		if (P != NULL) {
			std::cout << P->Data << std::endl;
			for (int i = 0; i < K; i++)
				PreOrderAchieve(P->C[i]);
		}
	}
	void PostOrder() {
		PostOrderAchieve(Head);
	}
	void PostOrderAchieve(KTNode<T, K>* P) {
		if (P != NULL) {
			for (int i = 0; i < K; i++)
				PreOrderAchieve(P->C[i]);
			std::cout << P->Data << std::endl;
		}
	}
	KTNode<T, K>* Find(T x) {
		return FindAchieve(Head, x);
	}
	KTNode<T, K>* FindAchieve(KTNode<T, K>* P, T x) {
		if (P == NULL)
			return NULL;
		else {
			KTNode<T, K>* Tp;
			if (P->Data == x)
				return P;
			for (int i = 0; i < K; i++)
				if (Tp = FindAchieve(P->C[i], x))
					return Tp;
			return NULL;
		}
	}
	void Insert(T x) {
		InsertAchieve(Head, x);
	}
	void InsertAchieve(KTNode<T, K> *&P, T x) {
		if (P == NULL) {
			P = new KTNode<T, K>(x);
		}
		else {
			int i = rand() % K;
			InsertAchieve(P->C[i], x);
		}
	}
};



template <typename T>
class Heap {
private:
	T * Data;
	int Length;
	int Size;
public:
	Heap() {
		Data = (T*)malloc(32 * sizeof(T));
		Length = 0;
		Size = 32;
	}
	Heap(int size) {
		Data = (T*)malloc(size * sizeof(T));
		Length = 0;
		Size = size;
	}
	void Traverse() {
		for (int i = 0; i < Length; i++) {
			std::cout << std::setw(5) << std::left << Data[i];
			if ((i + 1) % 10 == 0)
				std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	void MaxInsert(T x) {
		if (Length == Size) {
			T *NewP = (T *)realloc(Data, 2 * Size * sizeof(T));
			if (NewP == NULL) {
				std::cout << "InsufficientDynamicMemory" << std::endl;
				exit(1);
			}
			Data = NewP;
			Size *= 2;
		}
		Data[Length] = x;
		Length++;
		int child = Length - 1;//儿子节点
		int parent = (child - 1) / 2;//父亲节点
		while (child != 0) {
			if (x < Data[parent])//儿子节点小于父亲节点，不用调整
				break;
			Data[child] = Data[parent];//寻找x的合适位置
			child = parent;
			parent = (child - 1) / 2;
		}
		Data[child] = x;
	}
};


#endif