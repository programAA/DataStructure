#include <iostream>
using namespace std;

class Student {
private:
	static float score;
public:
	void input();
	void cal_dis(int n);
	static void cal();//����ʱ��static������ʵ��ʱ����Ҫ�ټ�static
};


void Student::cal()
{
	score += 100;
	cout << score << endl;
}


void Student::input()
{
	float x;
	cout << "�������ѧ���ɼ�:";
	cin >> x;
	score += x;
}


void Student::cal_dis(int n)
{
	cout << "�ܳɼ�Ϊ:" << score << endl;
	cout << "ƽ���ɼ�Ϊ:" << score / n << endl;
}  
//��̬��Ա�������ܵ��÷Ǿ�̬���ݳ�Ա��Ҫͨ����Ķ��������á�
float Student::score = 0;//��ʼ����̬��Ա����̬��Աͨ����������ڲ���ʼ��


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
