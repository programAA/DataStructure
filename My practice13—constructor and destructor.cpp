/*
创建派生类对象时系统按下列步骤工作：
1.调用各基类的构造函数,调用顺序按照他们被继承时声明的顺序(从左到右);
2.再调用各对象成员的构造函数(如果该类有对象成员的话),调用顺序按照他们在派生类中声明的顺序(从左到右);
  注意:在派生类中声明对象成员的顺序可以与派生类构造函数处所列对象成员的顺序不相同，他们之间没有必然联系;
3.最后调用派生类自己的构造函数(执行其函数体);
释放派生类对象时系统的工作步骤相反:即先构造的后析构
1.先调用派生类自己的析构函数;
2.再调用对象成员的析构函数，调用顺序按照他们被继承时声明的相反顺序(从右到左);
3.最后调用各基类的析构函数，调用顺序按照他们被继承时声明的相反顺序(从右到左);
*/

#include <iostream>
using namespace std;
class CA {
	int a;
public:
	CA(int n) { a = n; cout << "CA::a=" << a << endl; }
	~CA() { cout << "调用CA的析构函数" << endl; }
};
class CB {
	int b;
public:
	CB(int n) { b = n; cout << "CB::b=" << b << endl; }
	~CB() { cout << "调用CB的析构函数" << endl; }
};
class CC :public CA {
	int c;
public:
	CC(int n1, int n2) :CA(n2) { c = n1; cout << "CC::c=" << c << endl; }
	~CC() { cout << "调用CC的析构函数" << endl; }
};
class CD :public CB, public CC {
	int d;
public:
	CD(int n1, int n2, int n3, int n4) :CC(n3, n4), CB(n2)
	{
		d = n1;
		cout << "CD::d=" << d << endl;
	}
	~CD() { cout << "调用CD的析构函数" << endl; }
};
int main()
{
	CD *p=new CD(1, 2, 3, 4);
	CA x(5);
	delete p;
	return 0;
}
