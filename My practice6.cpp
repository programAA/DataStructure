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
		cout << "�����룺" << endl;
		cout << "Сʱ:";
		cin >> a.hour;
		cout << "����:";
		cin >> a.minute;
		cout << "����:";
		cin >> a.sec;
	}
	void output(Time &a)
	{
		cout << "Сʱ:" << a.hour << endl;
		cout << "����:" << a.minute << endl;
		cout << "����:" << a.sec << endl;
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
��д����Ҫ��
1�������ݳ�Ա��Ϊ˽�еģ�
2�������������Ĺ��ܸ�Ϊ�ɳ�Ա����ʵ�֣�
3���������ڶ����Ա������
Ȼ���������г��������ʲô��ԱӦָ��Ϊ���еģ�ʲô��ԱӦָ��Ϊ˽�еģ�ʲô������÷������ж��壿ʲô������������ⶨ�壿
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
	cout << t1.hour << ��; �� << t1.minute << ��; �� << t1.sec << endl;
}
*/