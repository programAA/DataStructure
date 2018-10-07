//多态的关键在于通过基类指针或引用调用一个虚函数时，
//编译时不能确定到底调用的是基类还是派生类的函数，运行时才能确定，这叫动态联编

//构造函数和静态成员函数不能使虚函数
//在类的定义中，前面有virtual关键字的成员函数就是虚函数

//包含纯虚函数的类叫做抽象类
//抽象类只能作为基类派生抽象类，不能创建抽象类的对象
//抽象类的指针和引用可以指向由抽象类派生出来的类的对象
//在抽象类的成员函数内可以调用纯虚函数，但是在构造函数和析构函数内部不能调用纯虚函数
//如果一个类从抽象类派生而来，那么当且仅当它实现了基类中的所有纯虚函数，它才能成为非抽象类

//事先编写一个程序，计算正方体、球体和圆柱体的表面积和体积。
//（提示：声明一个抽象基类 container，派生类cube、sphere和cylinder，基类中求表面积和体积的成员函数声明为纯虚函数。）

//每一个有虚函数的类都有一个虚函数表，该类的任何对象中都放着虚函数表的指针。
//虚函数表中列出了该类的虚函数地址。多出来的四个字节就是用来放虚函数表的地址的。

#include <iostream>
using namespace std;

class container
{
protected:
	double x, y;
public:
	container(double a, double b) :x(a), y(b) {}
	virtual double Area() = 0;//定义一个纯虚函数，函数名为Area，返回值为double
	virtual double vun() = 0;
};
//纯虚函数是一种特殊的虚函数，在许多情况下，
//在基类中不能对虚函数给出有意义的实现，而把它声明为纯虚函数，它的实现留给该基类的派生类去做。
class cube :public container
{
public:
	cube(double a, double b) :container(a, b) {}
	double Area() { return x*x * 6; }
	virtual double vun() { return x*x*x; }
};
//当将基类中的某一成员函数声明为虚函数后，
//派生类中的同名函数（函数名相同、参数列表完全一致、返回值类型相关）自动成为虚函数.
//派生类中的同名函数加不加virtual都可以
class sphere :public container
{
public:
	sphere(double a, double b) :container(a, b) {}
	double Area() { return 4 * 3.14*x*x; }
	virtual double vun() { return 4 * 3.14*x*x*x / 3; }
};
class cylinder :public container   //圆柱体
{
public:
	cylinder(double a,double b):container(a,b) {}
	double Area() { return 2 * 3.14*x*(x + y); }
	virtual double vun() { return 3.14*x*x*y; }
};
int main()
{
	int m;
	container *cp;
	cout << "输入你想要的计算：1.正方体，2.球体，3.圆柱体" << endl;
	cin >> m;
	switch (m) {
	case 1:
	{
		double a;
		cout << "请输入正方体的边长:";
		cin >> a;
		cube c(a, 0);
		cp = &c;
		cout << "正方体的面积:" << cp->Area() << endl << "正方形的体积:" << cp->vun() << endl;
		break;
	}
	case 2:
	{
		double r;
		cout << "请输入球体的半径:";
		cin >> r;
		sphere s(r, 0);
		cp = &s;
		cout << "球体的面积:" << cp->Area() << endl << "球体的体积:" << cp->vun() << endl;
		break;
	}
	case 3:
	{
		double a, b;
		cout << "请输入圆柱体的圆的半径和高:";
		cin >> a >> b;
		cylinder L(a, b);
		cp = &L;
		cout << "圆柱的表面积:" << cp->Area() << endl << "圆柱的体积:" << cp->vun() << endl;
		break;
	}
	default:
	{
		cout << "输入错误" << endl;
		break;
	}
	}
	return 0;
}
