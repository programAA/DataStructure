//���������()��[]��-> ��=ʱ����������غ�����������Ϊ��ĳ�Ա����
//�����������������������Ϊ��Ա������Ҳ������Ϊ��Ԫ����
//����Ϊ��Ա����ʱ�������Ĳ���������ԭ�в������ĸ�����һ������һԪ��������������Ϊ0����Ԫ�������Ĳ�������Ϊ1
//����Ϊ��Ԫ����ʱ�������Ĳ���������ԭ�в������ĸ�����ͬ

//ǰ��++����ʱû�в�����������++����ʱ�в���������ʹ��������������������á�
//�������Ϊǰ��++�����в����ˣ����Բ���Ҫ������
//ǰ��++��Ҫ�������ã���Ϊ�����Լ����������Է��ض�������ã��Է����ڱ��ʽ������ʹ�á�
//������++���صĲ������ã����Բ��ܽ�������ʹ�á�



//1������һ�������࣬ʵ�������ǰ�á�++������á�++�������ء�
#include <iostream>
using namespace std;
class plural {
	double a;
	double b;
public:
	plural() = default;
	plural(double x, double y) :a(x), b(y) {}
	plural(plural &m) { a = m.a; b = m.b; }//���ƹ��캯��
	plural(double x) { a = x; b = x; }//����ת�����캯��
	plural& operator ++();//ǰ��++
	plural operator ++(int);//����++
	friend ostream& operator <<(ostream& os,plural &A) {
		os << A.a << "+" << A.b << "i" << endl;
		return os;
	}
	void dis() { cout << a << "+" << b << "i" << endl; }
	friend plural& operator --(plural& m) {
		m.a--;
		m.b--;
		return m;
	}
	friend plural operator --(plural& m, int x) {
		plural temp(m);
		m.a--;
		m.b--;
		return temp;
	}
};
plural& plural::operator ++() {
	a++;
	b++;
	return *this;
}
plural plural::operator ++(int) {
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
	(++m) = 2;//��ֵ���ص�����m����Ȼ��ִ�и�ֵ����
	m.dis();
	(m++) = 2;//����ֵ����m����һ����ʱ����
	m.dis();
	cout << m << endl;
	return 0;
}

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
//	String(char *st) {
//		s = st;
//	}
//	String& operator =(const char *c) {//ע�������ǳ����������,�˴�Ϊ���
//		if (this->s == c) {
//			return *this;
//		}
//		delete[] s;
//		s = new char[strlen(c) + 1];
//		strcpy(s, c);
//		return *this;
//	}
//	friend ostream& operator <<(ostream &os, String &A) {
//		os << A.s << endl;
//		return os;
//	}
//	friend bool operator <(const String a, const String b);
//	friend bool operator >(const String a, const String b);
//	friend bool operator ==(const String a, const String b);
//};
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
//	cout << c << endl;
//	return 0;
//}

//����ת�������������
//1��д����ʱ��д����ֵ,����ֵʵ���������ص�����
//2����Ҫʱ�����Ѷ���ת��Ϊ����ֵ����
//#include <iostream>
//using namespace std;
//class Complex {
//	double real, imag;
//public:
//	Complex(double r = 0, double i = 0) :real(r), imag(i) {};
//	operator double() { return real; }//��������ת�������
//};
//int main()
//{
//	Complex c(1.2, 3.4);
//	cout << (double)c << endl;
//	double n = 2 + c;//����ת�������������ת�����캯������ʹ�������ɹ����룬�˴�ʹ��������ת�������
//	cout << n;
//	return 0;
//}
