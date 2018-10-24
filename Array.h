#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <algorithm>
#define MaxTerms 10000
#define MaxRows 100
#define MaxColumns 100
typedef int ElemType;


typedef struct triple {
	int row, col;
	ElemType value;
}Triple;
typedef struct SparseMatrix *Matrix;
struct SparseMatrix {
	int m, n, t;
	Triple Data[MaxTerms + 1];
};

typedef struct QuintupleNode *CrossNode;
struct QuintupleNode {
	int row, col;
	ElemType value;
	CrossNode Down, Right;
};
typedef struct LMatrix *OL;//Orthgonal List 正交表，十字链表
struct LMatrix {
	int m, n, t;
	CrossNode RM[MaxRows];
	CrossNode CM[MaxColumns];
};

OL CreateMatrix() {
	OL P;
	std::cout << "请输入行数:";
	std::cin >> P->m;
	std::cout << "请输入列数:";
	std::cin >> P->n;
	std::cout << "请输入非零元素个数:";
	std::cin >> P->t;
}

#endif