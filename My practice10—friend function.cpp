//һ�������Ԫ�������Է��ʸ����˽�г�Ա
//���A��B����Ԫ�࣬��ôA�ĳ�Ա�������Է���B��˽�г�Ա
#include <iostream>
using namespace std;
class Vector {
	friend void add(Vector &a, Vector &b);
	friend void min(Vector &a, Vector &b);
private:
	int x;
	int y;
public:
	Vector(int a,int b):x(a),y(b){}
};
void add(Vector &a, Vector &b)
{
	int c, k;
	c = a.x + b.x;
	k = a.y + b.y;
	cout << "(" << c << "," << k << ")" << endl;
}
void min(Vector &a, Vector &b)
{
	int c, k;
	c = a.x - b.x;
	k = a.y - b.y;
	cout << "(" << c << "," << k << ")" << endl;
}
int main()
{

	Vector a(8, 6), b(5, 3);
	add(a, b);
	min(a, b);
	return 0;
}
