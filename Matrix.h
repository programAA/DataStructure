#pragma once
#include <iostream>
#include <iomanip>
#define MAXSIZE 1000
using namespace std;
typedef int ElemType;
typedef struct {
	int i, j;
	ElemType e;
}Triple;
typedef struct {
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
		for (col = 1; col <= M.nu; ++col) num[col] = 0;//num[col]存储每一列元素个数
		for (t = 1; t <= M.tu; t++) ++num[M.data[t].j];//求M中每列非零元素个数
		cpot[1] = 1;//cpot[col]中存储第col列第一个非零元素在data数组中的位置
		for (col = 2; col <= M.nu; ++col) cpot[col] = cpot[col - 1] + num[col - 1];
		for (t = 1; t <= M.tu; ++t) {
			col = M.data[t].j;//第t个元素的列数
			q = cpot[col];//该元素在数组中的位置
			T.data[q].i = M.data[t].j;
			T.data[q].j = M.data[t].i;
			T.data[q].e = M.data[t].e;
			++cpot[col];
		}
	}
	return T;
}

ostream &operator <<(ostream &os, Matrix &M)
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