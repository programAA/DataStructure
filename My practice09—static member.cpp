//静态成员函数中不能访问非静态成员变量(不清楚变量属于哪个对象的)
//也不能调用非静态成员函数(显然非静态成员函数可能调用非静态成员变量)
//静态成员变量只有一份，被所有该类型的对象共享
//sizeof运算符不会计算静态成员变量
//静态成员访问有三种方法
//对象名.成员名
//类名::成员名 
//指针->成员名
//引用.成员名
#include <iostream>
using namespace std;

class Rectangle {
private:
	int w, h;
	static int TotalArea;
	static int TotalNumber;
public:
	Rectangle(int w,int h);
	~Rectangle();
	static void PrintTotal();
};
//缺点,通过复制构造函数生成对象时不会增加，但消亡时却一定会调用析构函数减去
//解决方法,不使用系统自动生成的复制构造函数,自己写一个复制构造函数
Rectangle::Rectangle(int w,int h) {
	this->w = w;
	this->h = h;
	TotalNumber++;
	TotalArea += w * h;
}
Rectangle::~Rectangle() {
	TotalNumber--;
	TotalArea -= w * h;
}
void Rectangle::PrintTotal() {
	cout << TotalNumber<< ',' << TotalArea << endl;
}

int Rectangle::TotalArea = 0;
int Rectangle::TotalNumber = 0;

int main() {
	Rectangle r1(3, 3), r2(4, 4);
	Rectangle *r3 = new Rectangle(5, 5);
	Rectangle *r4;
	Rectangle::PrintTotal();
	delete r3;
	r1.PrintTotal();
	r3->PrintTotal();
	r4->PrintTotal();
	return 0;
}