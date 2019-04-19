//重载运算符()、[]、-> 、=时，运算符重载函数必须声明为类的成员函数
//对于其他运算符，可以重载为成员函数，也可重载为友元函数
//重载为成员函数时，函数的参数个数比原有操作数的个数少一个，即一元操作符参数个数为0，二元操作符的参数个数为1
//重载为友元函数时，函数的参数个数与原有操作数的个数相同

//前置++重载时没有参数，而后置++重载时有参数。不会使用其参数，仅仅是区分用。
//可以理解为前置++后面有参数了，所以不需要参数。
//前置++需要返回引用，因为重载自加运算符后可以返回对象的引用，以方便在表达式中连续使用。
//而后置++返回的不是引用，所以不能进行连续使用。



//1、定义一个复数类，实现运算符前置“++”与后置“++”的重载。
#include <iostream>
using namespace std;
class plural {
	double a;
	double b;
public:
	plural() = default;
	plural(double x, double y) :a(x), b(y) {}
	plural(plural &m) { a = m.a; b = m.b; }//复制构造函数
	plural(double x) { a = x; b = x; }//类型转换构造函数
	plural& operator ++();//前置++
	plural operator ++(int);//后置++
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
	m.dis();//打印结果为3+4i
	for (int i = 0; i < 2; i++)
		++m;
	m.dis();//打印结果为5+6i
	for (int i = 0; i < 2; i++)
		m++;
	m.dis();//打印结果为7+8i
	(++m) = 2;//左值返回的仍是m本身，然后执行赋值操作
	m.dis();
	(m++) = 2;//返回值不是m，是一个临时对象
	m.dis();
	cout << m << endl;
	return 0;
}

//2、定义一个字符串类String，用来存放不定长的字符串，
//重载运算符"=="、"<"和">"，用于两个字符串的等于、小于和大于的比较运算。
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
//	String& operator =(const char *c) {//注意深拷贝和浅拷贝的区别,此处为深拷贝
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

//类型转换运算符的重载
//1：写函数时不写返回值,返回值实际上是重载的类型
//2：需要时主动把对象转换为返回值类型
//#include <iostream>
//using namespace std;
//class Complex {
//	double real, imag;
//public:
//	Complex(double r = 0, double i = 0) :real(r), imag(i) {};
//	operator double() { return real; }//重载类型转换运算符
//};
//int main()
//{
//	Complex c(1.2, 3.4);
//	cout << (double)c << endl;
//	double n = 2 + c;//类型转换运算符、类型转换构造函数均可使这条语句成功编译，此处使用了类型转换运算符
//	cout << n;
//	return 0;
//}
