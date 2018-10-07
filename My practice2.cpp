//求和：s = a + aa + aaa + … + aa…a，其中a是数字，a和n由键盘输入。
#include <iostream>
using namespace std;
int main()
{
	int a, n, x, s = 0;
	cout << "Please a and n:";
	cin >> a >> n;
	x = a;     //保存将要加的值
	for (int i = 1; i <= n; i++)
	{
		s = s + x;
		x = 10 * x + a;
	}
	cout << "s=";
	for (int i = 1; i <= n; i++)      //
	{                                 //      
		for (int j = 1; j <= i; j++)  //这一段用来控制输出a+aa+aaa
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