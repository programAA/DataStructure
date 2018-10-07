// 分别声明Teacher(教师)类和Cadre(干部)类，采用多重继承方式由这两个类派生出新类Teacher_Cadre(教师兼干部)，要求：
//（1）在两个基类中都包含有姓名、年龄、性别、地址、电话等数据成员；
//（2）在Teacher类中还包含数据成员title(职称)，在Cadre类中还包含数据成员post(职务)，
//     在Teacher_Cadre类中还包含数据成员wages(工资)；
//（3）对两个基类中的姓名、年龄、性别、地址、电话等数据成员用相同的名字，在引用这些数据成员时，指定作用域；
//（4）在类体中声明成员函数，在类外定义成员函数；
//（5）在派生类Teacher_Cadre的成员函数show中调用Teacher类中的display函数，
//     输出姓名、年龄、性别、地址、电话，然后再用cout语句输出职务和工资。
//派生类的构造函数只能初始化自己的成员函数，而不能初始化基类的成员。
//有时派生类从基类继承了成员，他也可以初始化从基类继承的成员。
#include <iostream>
#include <string>
using namespace std;
class Teacher {
private:
	string name;//姓名
	int age;//年龄
	string sex;//性别
	string address;//地址
	string phone;//电话
public:
	string title;//职称
	Teacher(string n,int a,string s,string ad,string p);//构造函数
	void display();
};
Teacher::Teacher(string n, int a, string s, string ad, string p):name(n),age(a),sex(s),address(ad),phone(p){}
void Teacher::display()
{
	cout << "姓名:" << name << endl;
	cout << "年龄:" << age << endl;
	cout << "性别:" << sex << endl;
	cout << "地址:" << address << endl;
	cout << "电话:" << phone << endl;
}
class Cadre {
private:
	string name;
	int age;
	string sex;
	string address;
	string phone;
public:
	string post;//职务
	void display();
};
void Cadre::display()
{
	cout << "姓名:" << name << endl;
	cout << "年龄:" << age << endl;
	cout << "性别:" << sex << endl;
	cout << "地址:" << address << endl;
	cout << "电话:" << phone << endl;
	cout << "职务:" << post << endl;
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
	cout << "职务:" << post << endl;
	cout << "工资:" << wages << endl;
}
int main()
{
	Teacher_Cadre x("lihua",40,"male","zhoukoushi","18465895421","dean",8000);
	x.display();
	x.Teacher::display();//防止二义性，指明继承自哪个基类
	x.Cadre::display();
	return 0;
}
