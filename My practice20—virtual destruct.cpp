//通过基类的指针删除派生类对象时，通常情况下只调用基类的析构函数
//但是，删除一个派生类对象时，应该先调用派生类的析构函数，然后调用基类的析构函数
//解决办法是:把基类的析构函数声明为virtual
//一般来说，一个类如果定义了虚函数，则应该将析构函数也定义成虚函数。
//或则，一个类打算作为基类使用，也应该将析构函数定义成虚函数。
//不允许以虚函数作为构造函数

#include <iostream>
using namespace std;

class son {
public:
	son() { cout << "son construct!" << endl; }
	virtual ~son() { cout << "son destruct!" << endl; }
};

class grandson :public son {
public:
	grandson() { cout << "grandson construct!" << endl; }
	~grandson() { cout << "grandson destruct!" << endl; }
};

int main(){
	son *p;
	p = new grandson();
	delete p;
	return 0;
}