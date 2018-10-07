#include <iostream>
using namespace std;
class Cuboid {
private:
	double length;
	double width;
	double height;
public:
	istream &read(istream &is, Cuboid &a);
	ostream &print(ostream &os, Cuboid &a);
	void calculate_volume();
};

//read函数可以直接输入一个长方体的参数
istream &Cuboid::read(istream &is, Cuboid &a)
{
	is >> a.length >> a.width >> a.height;
	return is;
}


//print函数可以直接输出长方体体积
ostream &Cuboid::print(ostream &os, Cuboid &a)
{
	os << "体积为:" << a.length*a.width*a.height << endl;
	return os;
}

//计算并输出长方体体积
void Cuboid::calculate_volume()
{
	cout << "这个长方体的体积为:" << length*width*height;
}
int main()
{
	Cuboid x;
	char c;
	while (1)
	{
		cout << "请输入长宽高:";
		x.read(cin, x);
		x.print(cout, x);
		x.calculate_volume();
		cout << endl;
		cout << "你要计算下一个长方体的体积吗？Yes(y) or No(n):";
		cin >> c;
		if (c == 'y')
			continue;
		else
			break;
	}
	return 0;
}
