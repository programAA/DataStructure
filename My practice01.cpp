//1����̣����һԪ���η���ax2 + bx + c = 0�ĸ���
#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	double a, b, c, n;
	cout << "Please Input a b and c��";
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) 
			cout << "�޽�" << endl;
		else
			cout << "����Ψһ��:x=" << -c / b << endl;
	}
	else {//a!=0
		n = b * b - 4 * a * c;
		if (n < 0)
			cout << "�޽�" << endl;
		else if (n == 0)
			cout << "��������ͬ�Ľ�:x1=x2=" << -b / (2 * a) << endl;
		else
			cout << "��������ͬ�Ľ�:x1=" << (-b + sqrt(n)) / (2 * a) << endl
			<< "  x2=" << (-b - sqrt(n)) / (2 * a) << endl;
	}
}