#pragma once
#include <iostream>
using namespace std;
//���ֲ���
//��size��Ԫ�ص�����a�����p�������±꣬�Ҳ����򷵻�-1
int BinarySearch(int a[], int size, int p) {
	int L = 0;
	int R = size - 1;
	while (L <= R) {
		int mid = L + (R - L) / 2;
		if (a[mid] == p)
			return mid;
		else if (a[mid] > p)
			R = mid - 1;
		else 
			L = mid + 1;
	}
	return -1;
}
//���ұ�pС�������������������±꣬�Ҳ����򷵻�-1
int LowerBound(int a[], int size, int p){
	int L = 0;
	int R = size - 1;
	int pos = -1;
	while (L <= R) {
		int mid = L + (R - L) / 2;//��ֹL+R�������
		if (a[mid] >= p)
			R = mid - 1;
		else {
			pos = mid;
			L = mid + 1;
		}
	}
	return pos;
}
//���ַ��󷽳̵ĸ�
const double EPS = 1e-6;
double f(double x) { return x * x*x - 5 * x*x + 10 * x - 80; }
double abs(double x) { return x > 0 ? x : -x; }
double root() {
	double root, x1 = 0, x2 = 100, y;
	root = x1 + (x2 - x1) / 2;
	y = f(root);//abs(y)<=EPSʱ����
	while (abs(y) > EPS) {
		if (y > 0)
			x2 = root;
		else x1 = root;
		root = x1 + (x2 - x1) / 2;
		y = f(root);
	}
	return root;
}
//�������������Ϊm
//���Ӷ�ΪO(n)
void SearchTwo(int a[], int size, int m) {
	int L = 0;
	int R = size - 1;
	while (L < R) {
		if (a[L] + a[R] > m)
			--R;
		else if (a[L] + a[R] < m)
			++L;
		else
			break;
	}
	cout << L << ' ' << R << endl;
	cout << a[L] << ' ' << a[R] << endl;
}
//���Ӷ�ΪO(n*log n)
void Searchtwo(int a[], int size, int m) {
	int i, j;
	for (i = 0; i < size; ++i) {
		j = BinarySearch(a + 1, size - 1 - i, m - a[i]);
		if (j)
			break;
	}
	cout << i << ' ' << j << endl;
	cout << a[i] << ' ' << a[j] << endl;
}
