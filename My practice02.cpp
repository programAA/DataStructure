//��ͣ�s = a + aa + aaa + �� + aa��a������a�����֣�a��n�ɼ������롣
#include <iostream>
using namespace std;
int main()
{
	int a, n, x, s = 0;
	cout << "Please a and n:";
	cin >> a >> n;
	x = a;     //���潫Ҫ�ӵ�ֵ
	for (int i = 1; i <= n; i++)
	{
		s = s + x;
		x = 10 * x + a;
	}
	cout << "s=";
	for (int i = 1; i <= n; i++)      //
	{                                 //      
		for (int j = 1; j <= i; j++)  //��һ�������������a+aa+aaa
		{                             //  
			cout << "a";              //
		}                             //
		if (i != n)                   //
			cout << "+";              //
		else                          //
			cout << "=";              //
	}                                 //
	cout<< s << endl;
	return 0;
}