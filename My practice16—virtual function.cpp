//��̬�Ĺؼ�����ͨ������ָ������õ���һ���麯��ʱ��
//����ʱ����ȷ�����׵��õ��ǻ��໹��������ĺ���������ʱ����ȷ������ж�̬����

//���캯���;�̬��Ա��������ʹ�麯��
//����Ķ����У�ǰ����virtual�ؼ��ֵĳ�Ա���������麯��

//�������麯���������������
//������ֻ����Ϊ�������������࣬���ܴ���������Ķ���
//�������ָ������ÿ���ָ���ɳ�����������������Ķ���
//�ڳ�����ĳ�Ա�����ڿ��Ե��ô��麯���������ڹ��캯�������������ڲ����ܵ��ô��麯��
//���һ����ӳ�����������������ô���ҽ�����ʵ���˻����е����д��麯���������ܳ�Ϊ�ǳ�����

//ÿһ�����麯�����඼��һ���麯����������κζ����ж������麯�����ָ�롣
//�麯�������г��˸�����麯����ַ����������ĸ��ֽھ����������麯����ĵ�ַ�ġ�

//���ȱ�дһ�����򣬼��������塢�����Բ����ı�����������
//��ʾ������һ��������� container��������cube��sphere��cylinder
//������������������ĳ�Ա��������Ϊ���麯��


#include <iostream>
#include <math.h>
using namespace std;

class container {
protected:
	double x, y;
public:
	container(double a, double b = 0) :x(a), y(b) {}
	virtual double Area() = 0;//����һ�����麯����������ΪArea������ֵΪdouble
	virtual double Vun() = 0;
};
//���麯����һ��������麯�������������£��ڻ����в��ܶ��麯�������������ʵ��
//����������Ϊ���麯��������ʵ�������û����������ȥ����
//���������е�ĳһ��Ա��������Ϊ�麯����
//�������е�ͬ����������������ͬ�������б���ȫһ�¡�����ֵ������أ��Զ���Ϊ�麯��.
//�������е�ͬ�������Ӳ���virtual������
class cube :public container {
public:
	cube(double a) :container(a) {}
	double Area() { return x * x * 6; }
	virtual double Vun() { return x * x * x; }
};

class sphere :public container {
public:
	sphere(double a) :container(a) {}
	double Area() { return 4 * 3.14 * x * x; }
	virtual double Vun() { return 4 * 3.14 * x * x * x / 3; }
};

class cylinder :public container {  //Բ����
public:
	cylinder(double a, double b) :container(a, b) {}
	double Area() { return 2 * 3.14 * x * (x + y); }
	virtual double Vun() { return 3.14 * x * x * y; }
};

class cone :public container {
public:
	cone(double r, double h) :container(r, h) {}
	double Area() { return 3.14 * x * x + 3.14 * x * sqrt(y * y + x * x / 4); }
	double Vun() { return 3.14 * x * x * y; }
};

int main()
{
	int m;
	double a, b;
	container *cp;
	cout << "��������Ҫ�ļ��㣺1.�����壬2.���壬3.Բ���壬4.Բ׶��" << endl;
	cin >> m;
	switch (m){
		case 1: {
			cout << "������������ı߳�:";
			cin >> a;
			cube c(a);
			cp = &c;
			cout << "����������:" << cp->Area() << endl << "�����ε����:" << cp->Vun() << endl;
			break;
		}
		case 2: {
			cout << "����������İ뾶:";
			cin >> a;
			sphere s(a);
			cp = &s;
			cout << "��������:" << cp->Area() << endl << "��������:" << cp->Vun() << endl;
			break;
		}
		case 3: {
			cout << "������Բ�����Բ�İ뾶�͸�:";
			cin >> a >> b;
			cylinder L(a, b);
			cp = &L;
			cout << "Բ���ı����:" << cp->Area() << endl << "Բ�������:" << cp->Vun() << endl;
			break;
		}
		case 4: {
			cout << "������Բ׶��İ뾶�͸�:";
			cin >> a >> b;
			cone co(a, b);
			cp = &co;
			cout << "Բ׶�ı����:" << cp->Area() << endl << "Բ׶�����:" << cp->Vun() << endl;
			break;
		}
		default: {
			cout << "�������" << endl;
			break;
		}
	}
	return 0;
}
