//�����������������ߺ����������ķǹ��г�Ա������������������ߺ�����Ϊ������Ԫ
//��Ԫ��������Ԫ������������public��private��protected����û�����𣬶��ǿ��Ե�
//��Ԫ֮��Ĺ�ϵ���ܴ��ݣ����ܼ̳�
#include <iostream>
using namespace std;
class B;
class A
{
private:
	int x;
public:
	A(int xx) { x = xx; }
	void Set(B &b);
	int Get() { return x; }
};
class B
{
private:
	int x;
public:
	B(int xx) { x = xx; }
	friend class A;
};                 
void A::Set(B &b)
{
	x = b.x;
}
void main()
{
	A a(10);
	B b(20);
	cout << a.Get() << endl;
	a.Set(b);
	cout << a.Get() << endl;
}
