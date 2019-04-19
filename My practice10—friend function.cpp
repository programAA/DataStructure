//一个类的友元函数可以访问该类的私有成员
//如果A是B的友元类，那么A的成员函数可以访问B的私有成员
//定义一个由y=ax+b确定的直线类Line，该类的构造函数初始化直线
//成员函数Print显示该直线方程，友元函数SetPoint()求解两条直线的交点
#include <iostream>
using namespace std;
class Line {
private:
	float a;
	float b;
public:
	Line(float a1, float b1) :a(a1), b(b1) {}
	void Print();
	friend void Setpoint(Line &a, Line &b);
};
void Line::Print()
{
	cout << "y=" << a << "x+" << b << endl;
}
void Setpoint(Line &one, Line &two)
{
	float x, y;
	if (one.a == two.a) {
		if (one.b == two.b)
			cout << "两直线重合" << endl;
		else
			cout << "两直线平行,没有交点" << endl;
	}
	else {
		x = (two.b - one.b) / (one.a - two.a);
		y = one.a*x + one.b;
		cout << "交点为:(" << x << "," << y << ")" << endl;
	}
}
int main()
{
	Line L1(2, 1), L2(4, 2);
	L1.Print();
	L2.Print();
	Setpoint(L1, L2);
	return 0;
}
