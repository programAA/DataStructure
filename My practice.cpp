//����������Ϊ�����������ݹ����У����˻�Ϊָ�롣
//�����������ݸ�һ��ָ�������ʹ��sizeof��ָ�����������
//�ó���ֵ��ָ�뱾����ռ�ռ��С�����������С��

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
	cout << "ָ�룺" << sizeof(p) << endl;
	cout << "��������" << sizeof(A) << endl;
	cout << "������������������������" << endl;
	double d[] = { 1,-2,3,4,5,6,2.2 };
	cout << sizeof(d) << endl;
	print(d);
	return 0;
}