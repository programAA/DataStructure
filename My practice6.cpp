#include <iostream>
using namespace std;
class Time
{
private:
	int hour;
	int minute;
	int sec;
public:
	void input(Time &a)
	{
		cout << "请输入：" << endl;
		cout << "小时:";
		cin >> a.hour;
		cout << "分钟:";
		cin >> a.minute;
		cout << "秒数:";
		cin >> a.sec;
	}
	void output(Time &a)
	{
		cout << "小时:" << a.hour << endl;
		cout << "分钟:" << a.minute << endl;
		cout << "秒数:" << a.sec << endl;
	}
	istream &read(istream &is, Time &a);
	ostream &print(ostream &os, Time &a);
};
istream &Time::read(istream &is, Time &a)
{
	is >> a.hour >> a.minute >> a.sec;
	return is;
}
ostream &Time::print(ostream &os, Time &a)
{
	os << a.hour << ":" << a.minute << ":" << a.sec;
	return os;
}
int main()
{
	Time t1;
	t1.input(t1);
	t1.output(t1);
	cout << endl;
	t1.read(cin, t1);
	t1.print(cout, t1);
	return 0;
}


/*
改写程序，要求：
1）将数据成员改为私有的；
2）将输入和输出的功能改为由成员函数实现；
3）在类体内定义成员函数。
然后编译和运行程序。请分析什么成员应指定为公有的？什么成员应指定为私有的？什么函数最好放在类中定义？什么函数最好在类外定义？
#include <iostream.h>
class Time
{
public:
	int hour;
	int minute;
	int sec;
};
void main()
{
	Time t1;
	cin >> t1.hour;
	cin >> t1.minute;
	cin >> t1.sec;
	cout << t1.hour << “; ” << t1.minute << “; ” << t1.sec << endl;
}
*/