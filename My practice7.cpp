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

//read��������ֱ������һ��������Ĳ���
istream &Cuboid::read(istream &is, Cuboid &a)
{
	is >> a.length >> a.width >> a.height;
	return is;
}


//print��������ֱ��������������
ostream &Cuboid::print(ostream &os, Cuboid &a)
{
	os << "���Ϊ:" << a.length*a.width*a.height << endl;
	return os;
}

//���㲢������������
void Cuboid::calculate_volume()
{
	cout << "�������������Ϊ:" << length*width*height;
}
int main()
{
	Cuboid x;
	char c;
	while (1)
	{
		cout << "�����볤���:";
		x.read(cin, x);
		x.print(cout, x);
		x.calculate_volume();
		cout << endl;
		cout << "��Ҫ������һ��������������Yes(y) or No(n):";
		cin >> c;
		if (c == 'y')
			continue;
		else
			break;
	}
	return 0;
}
