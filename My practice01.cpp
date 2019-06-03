//1．编程，求解一元二次方程ax2 + bx + c = 0的根。
#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	double a, b, c, n;
	cout << "Please Input a b and c：";
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) 
			cout << "无解" << endl;
		else
			cout << "存在唯一解:x=" << -c / b << endl;
	}
	else {//a!=0
		n = b * b - 4 * a * c;
		if (n < 0)
			cout << "无解" << endl;
		else if (n == 0)
			cout << "有两个相同的解:x1=x2=" << -b / (2 * a) << endl;
		else
			cout << "有两个不同的解:x1=" << (-b + sqrt(n)) / (2 * a) << endl
			<< "  x2=" << (-b - sqrt(n)) / (2 * a) << endl;
	}
}