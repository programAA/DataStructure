//一个不小于6的偶数可以由素数相加得到
#include <iostream>
using namespace std;
int judg(int x)
{
	int i, y;
	y = sqrt(x);
	for (i = 2; i <= y; i++)
	{
		if (x%i == 0)
			break;
	}
	if (i > y)
		return 1;
	else
		return 0;
}
int main()
{
	int s, i, j;
	cout << "请输入一个不小于6的偶数:";
	cin >> s;
	while (s < 6 || s % 2 != 0)
	{
		cout << "输入错误，请重新输入:";
		cin >> s;
	}
	for (i = 2; i < s; i++)
	{
		if (judg(i))
		{
			for (j = 2; j < s; j++)
			{
				if (judg(j) && i + j == s)
					cout << s << "=" << i << "+" << j << endl;
			}
		}
	}
	return 0;
}

//int main()
//{
//	int x;
//	cout << "请输入要判断的数:";
//	cin >> x;
//	if (judg(x))
//		cout << x << "是素数" << endl;
//	else
//		cout << x << "不是素数" << endl;
//	return 0;
//}
