//1．定义一个函数模板实现冒泡排序的功能，并在main()函数中分别对int型数组和double型数组的排序。 

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

//2．设计//一个数组类模板 Array<T>，其中包含重载下载运算符函数，并由此产生模板类 Array<int>和Array<char>，使用一些测试数据对其进行测试。
/*
在模板类中输入流“ >> ”和输出流“ << ”的重载, 若使用友元在类内声明，在类外实现，那么连接时将会报错,
但我们可以采用以下三种方式来实现输出流"<<"和"输入流>>"的重载。
一、将输出流"<<"和"输入流>>"重载的实现写在类中
那么输入输出流重载为什么不能在类内声明，类外实现呢？？因为模板比较特殊，若果在模板类外实现重载的话：
操作符重载函数不是类的成员函数，因此此处相当于定义了一个新的函数模板。所以不能在模板类内声明，类外实现操作符重载。
二、既然类外实现相当于重定义了一个函数模板，那么只要他不使用类的私用成员即可，
因此重载的函数模板只有通过类的公有成员函数来实现对类的私有成员的操作，这样不必在类内声明它为友元，直接在类外重载即可。
三、使用过渡函数
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
		cout << "程序出错" << endl;
	}
	return ary[i];
}
int main()
{
	Array<int, 5> a1;
	Array<char, 5> a2;
	cout << "请输入你要的int和char的数组a[5]和b[5] " << endl;
	cin >> a1;
	cin >> a2;
	cout << a1;
	a2.display();
	system("pause");
	return 0;
}
*/