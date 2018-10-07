#pragma once
#include <iostream>
using namespace std;
//二分查找
//在size个元素的数组a里查找p，返回下标，找不到则返回-1
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
//查找比p小的数的最大的数，返回下标，找不到则返回-1
int LowerBound(int a[], int size, int p){
	int L = 0;
	int R = size - 1;
	int pos = -1;
	while (L <= R) {
		int mid = L + (R - L) / 2;//防止L+R过大溢出
		if (a[mid] >= p)
			R = mid - 1;
		else {
			pos = mid;
			L = mid + 1;
		}
	}
	return pos;
}
//二分法求方程的根
const double EPS = 1e-6;
double f(double x) { return x * x*x - 5 * x*x + 10 * x - 80; }
double abs(double x) { return x > 0 ? x : -x; }
double root() {
	double root, x1 = 0, x2 = 100, y;
	root = x1 + (x2 - x1) / 2;
	y = f(root);//abs(y)<=EPS时返回
	while (abs(y) > EPS) {
		if (y > 0)
			x2 = root;
		else x1 = root;
		root = x1 + (x2 - x1) / 2;
		y = f(root);
	}
	return root;
}
//查找两个数其和为m
//复杂度为O(n)
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
//复杂度为O(n*log n)
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
