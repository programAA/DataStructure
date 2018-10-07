//数组名在作为函数参数传递过程中，会退化为指针。
//把数组名传递给一个指针变量后，使用sizeof（指针变量名）后，
//得出的值是指针本身所占空间大小而不是数组大小。

#include <iostream>
#include <iomanip>
using namespace std;

void print(double* a) {
	cout << sizeof(a) << endl;
	int count = sizeof(a) / sizeof(double);
	cout << "length=" << count << endl;
	for (int i = 0; i < count; ++i) {
		cout << "i=" << i << ",a=" << a[i] << endl;
	}
}

int main() {
	double *p = new double[10];
	double A[10];
	cout << "指针：" << sizeof(p) << endl;
	cout << "数组名：" << sizeof(A) << endl;
	cout << "————————————" << endl;
	double d[] = { 1,-2,3,4,5,6,2.2 };
	cout << sizeof(d) << endl;
	print(d);
	return 0;
}