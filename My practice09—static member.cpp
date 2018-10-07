#include <iostream>
using namespace std;

class Student {
private:
	static float score;
public:
	void input();
	void cal_dis(int n);
	static void cal();//申明时加static，下面实现时不需要再加static
};


void Student::cal()
{
	score += 100;
	cout << score << endl;
}


void Student::input()
{
	float x;
	cout << "请输入该学生成绩:";
	cin >> x;
	score += x;
}


void Student::cal_dis(int n)
{
	cout << "总成绩为:" << score << endl;
	cout << "平均成绩为:" << score / n << endl;
}  
//静态成员函数不能调用非静态数据成员，要通过类的对象来调用。
float Student::score = 0;//初始化静态成员，静态成员通常不在类的内部初始化


int main()
{
	Student a, b, c;
	a.input();
	b.input();
	c.input();
	a.cal_dis(3);
	Student::cal();
	return 0;
}
