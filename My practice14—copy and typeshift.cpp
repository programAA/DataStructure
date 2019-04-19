//复制构造函数使用的三种情况
//1：用一个对象初始化另一个对象
//2：函数的参数是对象
//3：函数的返回值是对象

//类型转换构造函数
//1：只有一个参数
//2：需要时主动把参数类型的变量转换为对象

//类型转换运算符
//1：写函数时不写返回值,返回值实际上是重载的类型
//2：需要时主动把对象转换为返回值类型

//赋值运算符
//1：等号两边类型不匹配时，需要重载赋值运算符
//2：有时候类型转换构造函数、类型转换运算符可以完成赋值运算符的功能
#include <iostream>
using namespace std;

class Complex {
public:
	double real, imaginary;
	Complex(int i) {//类型转换构造函数
		cout << "IntConstructor called" << endl;
		real = i;
		imaginary = 0;
	}
	Complex(double r, double i) { real = r; imaginary = i; }
};

int main() {
	Complex c1(7, 8);
	Complex c2 = 12;//调用了类型转换构造函数
	c1 = 9;//调用了类型转换构造函数
	cout << c1.real << "," << c1.imaginary << endl;
	return 0;
}