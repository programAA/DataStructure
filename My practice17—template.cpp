//1������һ������ģ��ʵ��ð������Ĺ��ܣ�����main()�����зֱ��int�������double����������� 

#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
void sort(T a[], int n)
{
	T c;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				c = a[j];
				a[j] = a[j + 1];
				a[j + 1] = c;
			}
		}
	}
}
int main()
{
	int x[10] = { 1,5,9,6,3,7,2,10,4,8 };
	double y[6] = { 2.6,2.8,3.2,1,6,2.0 };
	sort(x, 10);
	sort(y, 6);
	for (int i = 0; i < 10; i++)
	{
		cout << setw(5) << left << x[i];
	}
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << setw(5) << left << y[i];
	}
	cout << endl;
	return 0;
}

//2�����//һ��������ģ�� Array<T>�����а�������������������������ɴ˲���ģ���� Array<int>��Array<char>��ʹ��һЩ�������ݶ�����в��ԡ�
/*
��ģ�������������� >> ����������� << ��������, ��ʹ����Ԫ������������������ʵ�֣���ô����ʱ���ᱨ��,
�����ǿ��Բ����������ַ�ʽ��ʵ�������"<<"��"������>>"�����ء�
һ���������"<<"��"������>>"���ص�ʵ��д������
��ô�������������Ϊʲô��������������������ʵ���أ�����Ϊģ��Ƚ����⣬������ģ������ʵ�����صĻ���
���������غ���������ĳ�Ա��������˴˴��൱�ڶ�����һ���µĺ���ģ�塣���Բ�����ģ����������������ʵ�ֲ��������ء�
������Ȼ����ʵ���൱���ض�����һ������ģ�壬��ôֻҪ����ʹ�����˽�ó�Ա���ɣ�
������صĺ���ģ��ֻ��ͨ����Ĺ��г�Ա������ʵ�ֶ����˽�г�Ա�Ĳ�������������������������Ϊ��Ԫ��ֱ�����������ؼ��ɡ�
����ʹ�ù��ɺ���
*/
/*
#include <iostream>
using namespace std;
template <typename T, int size>
class Array
{
	T ary[size];
public:
	Array()=default;
	T &operator[](int i);
	void display();
	friend ostream& operator <<(ostream &os, Array<T, size> &a)
	{
		for (int i = 0; i < size; i++)
		{
			os << a.ary[i] << ' ';
		}
		os << endl;
		return os;
	}
	friend istream& operator >>(istream &is, Array<T, size> &a)
	{
		for (int i = 0; i < size; i++)
		{
			is >> a.ary[i];
		}
		return is;
	}
};
template <typename T, int  size>
void Array<T, size>::display()
{
	for (int i = 0; i < size; i++)
		cout << ary[i] << "   ";
	cout << endl;

}
template <typename T, int  size>
T& Array<T, size>::operator[](int i)
{
	if (i<0 || i >= size)
	{
		cout << "�������" << endl;
	}
	return ary[i];
}
int main()
{
	Array<int, 5> a1;
	Array<char, 5> a2;
	cout << "��������Ҫ��int��char������a[5]��b[5] " << endl;
	cin >> a1;
	cin >> a2;
	cout << a1;
	a2.display();
	system("pause");
	return 0;
}
*/