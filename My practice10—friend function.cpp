//һ�������Ԫ�������Է��ʸ����˽�г�Ա
//���A��B����Ԫ�࣬��ôA�ĳ�Ա�������Է���B��˽�г�Ա
//����һ����y=ax+bȷ����ֱ����Line������Ĺ��캯����ʼ��ֱ��
//��Ա����Print��ʾ��ֱ�߷��̣���Ԫ����SetPoint()�������ֱ�ߵĽ���
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
			cout << "��ֱ���غ�" << endl;
		else
			cout << "��ֱ��ƽ��,û�н���" << endl;
	}
	else {
		x = (two.b - one.b) / (one.a - two.a);
		y = one.a*x + one.b;
		cout << "����Ϊ:(" << x << "," << y << ")" << endl;
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
