//定义一个由y=ax+b确定的直线类Line，该类的构造函数初始化直线，
//成员函数Print显示该直线方程，友元函数SetPoint()求解两条直线的交点。
#include <iostream>
using namespace std;
class Line {
private:
	float a;
	float b;
public:
	Line(float a1,float b1):a(a1),b(b1){}
	void print();
	friend void setpoint(Line &a, Line &b);
};
void Line::print()
{
	cout << "y=" << a << "x+" << b << endl;
}
void setpoint(Line &one, Line &two)
{
	int x, y;
	if (one.a == two.a)
		cout << "没有交点" << endl;
	else
	{
		x = (two.b - one.b) / (one.a - two.a);
		y = one.a*x + one.b;
		cout << "交点为:(" << x << "," << y << ")" << endl;
	}
}
int main()
{
	Line L1(2,1), L2(3,5);
	L1.print();
	L2.print();
	setpoint(L1, L2);
	return 0;
}
