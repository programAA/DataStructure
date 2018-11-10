#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>
#define MAXSIZE 1000
using namespace std;
typedef int ElemType;

typedef struct triple{
	int i, j;
	ElemType e;
}Triple;
typedef struct matrix{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}Matrix;
Matrix Transpose(Matrix &M)
{
	Matrix T;
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (M.tu) {
		int q = 1;
		int col, p;
		for (col = 1; col <= M.nu; ++col) {
			for (p = 1; p <= M.tu; ++p) {
				if (M.data[p].j == col) {
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					++q;
				}
			}
		}
	}
	return T;
}
Matrix FastTranspose(Matrix &M)
{
	Matrix T;
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu) {
		int col, t, q;
		int num[20],cpot[20];
		for (col = 1; col <= M.nu; ++col) num[col] = 0;//num[col]�洢ÿһ��Ԫ�ظ���
		for (t = 1; t <= M.tu; t++) ++num[M.data[t].j];//��M��ÿ�з���Ԫ�ظ���
		cpot[1] = 1;//cpot[col]�д洢��col�е�һ������Ԫ����data�����е�λ��
		for (col = 2; col <= M.nu; ++col) cpot[col] = cpot[col - 1] + num[col - 1];
		for (t = 1; t <= M.tu; ++t) {
			col = M.data[t].j;//��t��Ԫ�ص�����
			q = cpot[col];//��Ԫ���������е�λ��
			T.data[q].i = M.data[t].j;
			T.data[q].j = M.data[t].i;
			T.data[q].e = M.data[t].e;
			++cpot[col];
		}
	}
	return T;
}
ostream& operator <<(ostream &os, Matrix &M)
{
	int p = 1;
	int row, col;
	for (row = 1; row <= M.mu; row++)
	{
		for (col = 1; col <= M.nu; col++)
		{
			if (M.data[p].i == row && p <= M.tu) {
				if (M.data[p].j == col) {
					os << setw(4) << setiosflags(ios::left) << M.data[p].e;
					p++;
				}
				else
					os << setw(4) << setiosflags(ios::left) << 0;
			}
			else
				os << setw(4) << setiosflags(ios::left) << 0;
		}
		os << endl;
	}
	return os;
}


typedef struct OLnode {
	//Orthgonal List ������ʮ������
	int Row, Col;
	ElemType Value;
	OLNode Down, Right;
} *OLNode;
typedef struct CrossNode {
	int m, n, t;
	OLNode *RP;
	OLNode *CP;
}*CrossList;
CrossList CreateSMatrix() {
	CrossList M = (CrossList)malloc(sizeof(struct CrossNode));
	if (!M) {
		cout << "�ڴ治��" << endl;
		exit(1);
	}
	cout << "���������������������ͷ���Ԫ����:";
	cin >> M->m >> M->n >> M->t;
	if (!(M->RP = (OLNode *)malloc((M->m + 1) * sizeof(OLNode)))) {
		cout << "�ڴ治��" << endl;
		exit(1);
	}
	if (!(M->CP = (OLNode *)malloc((M->n + 1) * sizeof(OLNode)))) {
		cout << "�ڴ治��" << endl;
		exit(1);
	}
	for (int i = 1; i <= M->m; i++)//��ʼ����ָ��
		M->RP[i] = NULL;
	for (int i = 1; i <= M->n; i++)//��ʼ����ָ��
		M->CP[i] = NULL;
	OLNode P;
	OLNode Q;
	for(int count=1;count<=M->t;count++){
		if (!(P = (OLNode)malloc(sizeof(struct OLnode)))) {
			cout << "�ڴ治��" << endl;
			exit(1);
		}
		cin >> P->Row >> P->Col >> P->Value;
		if (M->RP[P->Row] == NULL || M->RP[P->Row]->Col > P->Col) {
			P->Right = M->RP[P->Row];
			M->RP[P->Row] = P;
		}
		else {//Ѱ�������еĲ���λ��
			for (Q = M->RP[P->Row]; Q->Right && Q->Right->Col < P->Col; Q = Q->Right);
			P->Right = Q->Right;
			Q->Right = P;
		}
		if (M->CP[P->Col] == NULL || M->CP[P->Col]->Row > P->Row) {
			P->Down = M->CP[P->Col];
			M->CP[P->Col] = P;
		}
		else {//Ѱ�������еĲ���λ��
			for (Q = M->CP[P->Col]; Q->Down && Q->Down->Row < P->Row; Q = Q->Down);
			P->Down = Q->Down;
			Q->Down = P;
		}
	}
	return M;
}
ostream& operator <<(ostream &os, CrossList L) {
	OLNode P;
	for (int i = 1; i <= L->m; i++) {
		P = L->RP[i];
		for (int j = 1; j <= L->n; j++) {
			if (P && P->Col == j) {
				os << left << setw(4) << P->Value;
				P = P->Right;
			}
			else
				os << left << setw(4) << 0;
		}
		os << endl;
	}
	return os;
}


struct GNode {
	int tag;
	union {
		ElemType data;
		struct GNode *sublist;
	};
	struct GNode *next;
};
int LengthGList(struct GNode *GL) {
	//��GL��ָ��Ĺ����ĳ���
	if (GL != NULL)
		return 1 + LengthGList(GL->next);
	else
		return 0;
}
int SizeGList(struct GNode *GL) {
	int size = 0;
	struct GNode *P = GL;
	while (P != NULL) {
		size++;
		P = P->next;
	}
	return size;
}
int DepthGList(struct GNode* GL) {
	//��GLָ��Ĺ��������
	int max = 0;
	//�������е�ÿһ���ڵ㣬�ҳ������ӱ��������
	while (GL != NULL) {
		if (GL->tag == 1) {
			int dep = DepthGList(GL->sublist);
			if (dep > max)
				max = dep;
		}
		GL = GL->next;
	}
	return max + 1;
}
#endif