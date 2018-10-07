//���������(), [], ->, ���߸�ֵ�����=ʱ����������غ�����������Ϊ��ĳ�Ա����

// 1�����һ��2��3�еľ�����Matrix��
//�����乹�캯���������Ա����input�������Ա����display�����������"+"������������ļӷ���

//#include <iostream>
//#include <iomanip>
//using namespace std;
//class Maxrix {
//	double m[2][3];
//public:
//	Maxrix() = default;
//	void input();
//	void display();
//	friend Maxrix operator +(const Maxrix &a, const Maxrix &b);
//};
//void Maxrix::input()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> m[i][j];
//		}
//	}
//}
//void Maxrix::display()
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << setw(5) << m[i][j];
//		}
//		cout << endl;
//	}
//}
//Maxrix operator +(const Maxrix &a, const Maxrix &b)
//{
//	Maxrix h;
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			h.m[i][j] = a.m[i][j] + b.m[i][j];
//		}
//	}
//	return h;
//}
//int main()
//{
//	Maxrix a, b, c;
//	a.input();
//	b.input();
//	c = a + b;
//	c.display();
//	return 0;
//}

//2������һ���ַ�����String��������Ų��������ַ�����
//���������"=="��"<"��">"�����������ַ����ĵ��ڡ�С�ںʹ��ڵıȽ����㡣

//#include <iostream>
//#include <cstring>
//using namespace std;
//class String {
//	char *s;
//public:
//	String() {
//		s = new char[1];
//		s[0] = 0;
//	}
//	String(char *st) :s(st) {}
//	String & operator =(const char *c);
//	friend bool operator <(const String a, const String b);
//	friend bool operator >(const String a, const String b);
//	friend bool operator ==(const String a, const String b);
//};
//String& String::operator=(const char *c) {
//	if (this->s == c) {
//		return *this;
//	}
//	delete[] s;
//	s = new char[strlen(c) + 1];
//	strcpy(s, c);
//	return *this;
//}
//
//bool operator <(const String a, const String b)
//{
//	if (strcmp(a.s, b.s) < 0)
//		return true;
//	else
//		return false;
//}
//bool operator >(const String a, const String b)
//{
//	if (strcmp(a.s, b.s) > 0)
//		return true;
//	else
//		return false;
//}
//bool operator ==(const String a, const String b)
//{
//	if (strcmp(a.s, b.s) == 0)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	String a("asfasfasf");
//	String b("asdgjagjha");
//	String c;
//	c = "asdsa";
//	if (a > b)
//		cout << "a>b" << endl;
//	if (a < b)
//		cout << "a<b" << endl;
//	if (a == b)
//		cout << "a==b" << endl;
//	printf("%s\n", c);
//	return 0;
//}

//3������һ�������࣬ʵ�������ǰ�á�++������á�++�������ء�
//ǰ��++����ʱû�в�����������++����ʱ�в���������ʹ��������������������á��������Ϊǰ��++�����в����ˣ����Բ���Ҫ����
//ǰ��++��Ҫ�������ã���Ϊ�����Լ����������Է��ض�������ã� �Է����ڱ��ʽ������ʹ�á�������++���صĲ������ã����Բ��ܽ�������ʹ�á�

#include <iostream>
using namespace std;
class plural {
	double a;
	double b;
public:
	plural() = default;
	plural(double x, double y) :a(x), b(y) {}
	plural(plural &m) { a = m.a; b = m.b; }
	plural(double x) { a = x; b = x; }
	plural& operator ++();//ǰ��++
	plural operator ++(int);//����++
	void dis() { cout << a << "+" << b << "i" << endl; }
	friend plural& operator --(plural& m)
	{
		m.a--;
		m.b--;
		return m;
	}
	friend plural operator --(plural& m, int x)
	{
		plural temp(m);
		m.a--;
		m.b--;
		return temp;
	}
};
plural& plural::operator ++()
{
	a++;
	b++;
	return *this;
}
plural plural::operator ++(int)
{
	plural c(*this);
	a += 1;
	b += 1;
	return c;
}
int main()
{
	plural m(1, 2);
	for (int i = 0; i < 2; i++)
		m++;
	m.dis();//��ӡ���Ϊ3+4i
	for (int i = 0; i < 2; i++)
		++m;
	m.dis();//��ӡ���Ϊ5+6i
	for (int i = 0; i < 2; i++)
		m++;
	m.dis();//��ӡ���Ϊ7+8i
	(++m) = 2;
	m.dis();
	(m++) = 2;
	m.dis();
	return 0;
}


/*
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex {
	double real, imag;
public:
	Complex(double r = 0, double i = 0) :real(r), imag(i) {};
	friend ostream &operator<<(ostream &os, const Complex &c);
	friend istream &operator>>(istream &is, Complex &c);
};
ostream &operator<<(ostream &os, const Complex &c) {
	os << c.real << "+" << c.imag << "i";
	return os;
}
istream &operator>>(istream &is, Complex &c) {
	string s;
	is >> s;
	int pos = s.find("+", 0);
	string sTmp = s.substr(0, pos);
	c.real = atof(sTmp.c_str());
	sTmp = s.substr(pos + 1, s.length() - pos - 2);
	c.imag = atof(sTmp.c_str());
	return is;
}
int main()
{
	Complex a;
	int b;
	cin >> a >> b;
	cout << a << "," << b << endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
class Complex {
	double real, imag;
public:
	Complex(double r = 0, double i = 0) :real(r), imag(i) {};
	operator double() { return real; }//��������ת�������
};
int main()
{
	Complex c(1.2, 3.4);
	cout << (double)c << endl;
	double n = 2 + c;
	cout << n;
	system("pause");
	return 0;
}
*/

//4�� ���һ��2��3�еľ�����Matrix����������������� ��<<��������ȡ����>>����ʹ֮�����ڸþ��������������