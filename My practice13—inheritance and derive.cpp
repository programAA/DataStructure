// �ֱ�����Teacher(��ʦ)���Cadre(�ɲ�)�࣬���ö��ؼ̳з�ʽ��������������������Teacher_Cadre(��ʦ��ɲ�)��Ҫ��
//��1�������������ж����������������䡢�Ա𡢵�ַ���绰�����ݳ�Ա��
//��2����Teacher���л��������ݳ�Աtitle(ְ��)����Cadre���л��������ݳ�Աpost(ְ��)��
//     ��Teacher_Cadre���л��������ݳ�Աwages(����)��
//��3�������������е����������䡢�Ա𡢵�ַ���绰�����ݳ�Ա����ͬ�����֣���������Щ���ݳ�Աʱ��ָ��������
//��4����������������Ա�����������ⶨ���Ա������
//��5����������Teacher_Cadre�ĳ�Ա����show�е���Teacher���е�display������
//     ������������䡢�Ա𡢵�ַ���绰��Ȼ������cout������ְ��͹��ʡ�
//������Ĺ��캯��ֻ�ܳ�ʼ���Լ��ĳ�Ա�����������ܳ�ʼ������ĳ�Ա��
//��ʱ������ӻ���̳��˳�Ա����Ҳ���Գ�ʼ���ӻ���̳еĳ�Ա��
#include <iostream>
#include <string>
using namespace std;
class Teacher {
private:
	string name;//����
	int age;//����
	string sex;//�Ա�
	string address;//��ַ
	string phone;//�绰
public:
	string title;//ְ��
	Teacher(string n,int a,string s,string ad,string p);//���캯��
	void display();
};
Teacher::Teacher(string n, int a, string s, string ad, string p):name(n),age(a),sex(s),address(ad),phone(p){}
void Teacher::display()
{
	cout << "����:" << name << endl;
	cout << "����:" << age << endl;
	cout << "�Ա�:" << sex << endl;
	cout << "��ַ:" << address << endl;
	cout << "�绰:" << phone << endl;
}
class Cadre {
private:
	string name;
	int age;
	string sex;
	string address;
	string phone;
public:
	string post;//ְ��
	void display();
};
void Cadre::display()
{
	cout << "����:" << name << endl;
	cout << "����:" << age << endl;
	cout << "�Ա�:" << sex << endl;
	cout << "��ַ:" << address << endl;
	cout << "�绰:" << phone << endl;
	cout << "ְ��:" << post << endl;
}
class Teacher_Cadre :public Teacher, public Cadre {
private:
	int wages;
public:
	Teacher_Cadre(string n, int a, string s, string ad, string p, string po, int w) :Teacher(n, a, s, ad, p)
	{
		post = po;
		wages = w;
	}
	void display();
};
void Teacher_Cadre::display()
{
	Teacher::display();
	cout << "ְ��:" << post << endl;
	cout << "����:" << wages << endl;
}
int main()
{
	Teacher_Cadre x("lihua",40,"male","zhoukoushi","18465895421","dean",8000);
	x.display();
	x.Teacher::display();//��ֹ�����ԣ�ָ���̳����ĸ�����
	x.Cadre::display();
	return 0;
}
