#ifndef CTREE_H
#define CTREE_H
#include <iostream>

template <typename T>
struct TNode {
	T Data;
	TNode<T> *Left, *Right;
};

template <typename T>
class Tree {
	TNode<T>* Head;
public:
	Tree<T>() : Head(NULL) {}
	TNode<T>* GetHead() { return Head; }
	TNode<T>* FindMin();
	TNode<T>* FindMinAchieve(TNode<T>* P);
	TNode<T>* FindMax();
	TNode<T>* FindMaxAchieve(TNode<T>* P);
	void Insert(T x);
	void InsertAchieve(TNode<T> *&P, T x);
	void Delete(T x);
	void DeleteAchieve(TNode<T> *&P, T x);
	int Depth();
	int DepthAchieve(TNode<T>* P);
	void PreOrder1();
	void PreOrder1Achieve(TNode<T>* P);
	
	/*
	void MidOrder();
	void PostOrder();
	void LayerOrder();
	TNode<T>* Find(T x);
	
	*/
};
template <typename T>
TNode<T>* Tree<T>::FindMin() {
	return FindMinAchieve(Head);
}
template <typename T>
TNode<T>* Tree<T>::FindMinAchieve(TNode<T>* P) {
	if (P != NULL)
		while (P->Left != NULL)
			P = P->Left;
	return P;
}
template <typename T>
TNode<T>* Tree<T>::FindMax() {
	return FindMaxAchieve(Head);
}
template <typename T>
TNode<T>* Tree<T>::FindMaxAchieve(TNode<T>* P) {
	if (P == NULL || P->Right == NULL)
		return P;
	else
		return FindMaxAchieve(P->Right);
}
template <typename T>
void Tree<T>::Insert(T x) {
	InsertAchieve(Head, x);
}
template <typename T>
void Tree<T>::InsertAchieve(TNode<T> *&P, T x) {
	if (P == NULL) {
		P = new TNode<T>;
		P->Data = x;
		P->Left = P->Right = NULL;
	}
	else {
		if (x < P->Data)
			InsertAchieve(P->Left, x);
		else
			InsertAchieve(P->Right, x);
	}
}
template <typename T>
void Tree<T>::Delete(T x) {
	DeleteAchieve(Head, x);
}
template <typename T>
void Tree<T>::DeleteAchieve(TNode<T> *&P, T x) {
	TNode<T>* P1;
	if (P == NULL)
		std::cout << "删除失败!" << std::endl;
	else if (x < P->Data)
		DeleteAchieve(P->Left, x);
	else if (x > P->Data)
		DeleteAchieve(P->Right, x);
	else {
		if (P->Left != NULL && P->Right != NULL) {
			P1 = FindMaxAchieve(P->Left);//或者FindMinAchieve(P->Right)
			P->Data = P1->Data;
			DeleteAchieve(P->Left, P->Data);
		}
		else {//只存在一个子节点或不存在子节点
			P1 = P;
			if (P->Left == NULL)//存在右子节点或无子节点
				P = P->Right;
			else if (P->Right == NULL)//存在左孩子或无子节点
				P = P->Left;
			free(P1);
		}
	}
}
template <typename T>
int Tree<T>::Depth() {
	return DepthAchieve(Head);
}
template <typename T>
int Tree<T>::DepthAchieve(TNode<T>* P) {
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
template <typename T>
void Tree<T>::PreOrder1() {
	PreOrder1Achieve(Head);
}
template <typename T>
void Tree<T>::PreOrder1Achieve(TNode<T>* P) {//前序递归遍历
	if (P != NULL) {
		std::cout << P->Data << std::endl;
		PreOrder1Achieve(P->Left);
		PreOrder1Achieve(P->Right);
	}
}
#endif