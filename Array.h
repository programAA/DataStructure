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
typedef struct LMatrix *OL;//Orthgonal List ������ʮ������
struct LMatrix {
	int m, n, t;
	CrossNode RM[MaxRows];
	CrossNode CM[MaxColumns];
};

OL CreateMatrix() {
	OL P;
	std::cout << "����������:";
	std::cin >> P->m;
	std::cout << "����������:";
	std::cin >> P->n;
	std::cout << "���������Ԫ�ظ���:";
	std::cin >> P->t;
}

#endif