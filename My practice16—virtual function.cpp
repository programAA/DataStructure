//��̬�Ĺؼ�����ͨ������ָ������õ���һ���麯��ʱ��
//����ʱ����ȷ�����׵��õ��ǻ��໹��������ĺ���������ʱ����ȷ������ж�̬����

//���캯���;�̬��Ա��������ʹ�麯��
//����Ķ����У�ǰ����virtual�ؼ��ֵĳ�Ա���������麯��

//�������麯���������������
//������ֻ����Ϊ�������������࣬���ܴ���������Ķ���
//�������ָ������ÿ���ָ���ɳ�����������������Ķ���
//�ڳ�����ĳ�Ա�����ڿ��Ե��ô��麯���������ڹ��캯�������������ڲ����ܵ��ô��麯��
//���һ����ӳ�����������������ô���ҽ�����ʵ���˻����е����д��麯���������ܳ�Ϊ�ǳ�����

//���ȱ�дһ�����򣬼��������塢�����Բ����ı�����������
//����ʾ������һ��������� container��������cube��sphere��cylinder��������������������ĳ�Ա��������Ϊ���麯������

//ÿһ�����麯�����඼��һ���麯����������κζ����ж������麯�����ָ�롣
//�麯�������г��˸�����麯����ַ����������ĸ��ֽھ����������麯����ĵ�ַ�ġ�

#include <iostream>
using namespace std;

class container
{
protected:
	double x, y;
public:
	container(double a, double b) :x(a), y(b) {}
	virtual double Area() = 0;//����һ�����麯����������ΪArea������ֵΪdouble
	virtual double vun() = 0;
};
//���麯����һ��������麯�������������£�
//�ڻ����в��ܶ��麯�������������ʵ�֣�����������Ϊ���麯��������ʵ�������û����������ȥ����
class cube :public container
{
public:
	cube(double a, double b) :container(a, b) {}
	double Area() { return x*x * 6; }
	virtual double vun() { return x*x*x; }
};
//���������е�ĳһ��Ա��������Ϊ�麯����
//�������е�ͬ����������������ͬ�������б���ȫһ�¡�����ֵ������أ��Զ���Ϊ�麯��.
//�������е�ͬ�������Ӳ���virtual������
class sphere :public container
{
public:
	sphere(double a, double b) :container(a, b) {}
	double Area() { return 4 * 3.14*x*x; }
	virtual double vun() { return 4 * 3.14*x*x*x / 3; }
};
class cylinder :public container   //Բ����
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
	cout << "��������Ҫ�ļ��㣺1.�����壬2.���壬3.Բ����" << endl;
	cin >> m;
	switch (m) {
	case 1:
	{
		double a;
		cout << "������������ı߳�:";
		cin >> a;
		cube c(a, 0);
		cp = &c;
		cout << "����������:" << cp->Area() << endl << "�����ε����:" << cp->vun() << endl;
		break;
	}
	case 2:
	{
		double r;
		cout << "����������İ뾶:";
		cin >> r;
		sphere s(r, 0);
		cp = &s;
		cout << "��������:" << cp->Area() << endl << "��������:" << cp->vun() << endl;
		break;
	}
	case 3:
	{
		double a, b;
		cout << "������Բ�����Բ�İ뾶�͸�:";
		cin >> a >> b;
		cylinder L(a, b);
		cp = &L;
		cout << "Բ���ı����:" << cp->Area() << endl << "Բ�������:" << cp->vun() << endl;
		break;
	}
	default:
	{
		cout << "�������" << endl;
		break;
	}
	}
	return 0;
}
