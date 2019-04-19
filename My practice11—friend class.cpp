//类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的友元
//友元函数和友元类声明在类中public，private，protected部分没有区别，都是可以的
//友元之间的关系不能传递，不能继承
#include <iostream>
using namespace std;
class B;
class A{
private:
	int x;
public:
	A(int xx) { x = xx; }
	void Set(B &b);
	int Get() { return x; }
};
class B{
private:
	int x;
public:
	B(int xx) { x = xx; }
	friend class A;//声明A为B的友元,A中函数可访问B私有成员
};
void A::Set(B &b) {//此函数放到前面实现会运行出错，因为B尚未定义
	x = b.x;
}

void main()
{
	A a(10);
	B b(20);
	cout << a.Get() << endl;
	a.Set(b);
	cout << a.Get() << endl;
}
