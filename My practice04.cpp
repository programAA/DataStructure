//一个不小于6的偶数可以由两个素数相加得到
//打印所有结果

#include <iostream>
using namespace std;
int judge(int x) {//判断x是否是素数
	int i, y;
	y = sqrt(x);
	for (i = 2; i <= y; i++) {
		if (x % i == 0)
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
	while (s < 6 || s % 2 != 0) {
		cout << "输入错误，请重新输入:";
		cin >> s;
	}
	for (i = 2; i < s/2; i++) {
		if (judge(i)) {
			for (j = 2; j < s; j++) {
				if (judge(j) && i + j == s)
					cout << s << "=" << i << "+" << j << endl;
			}
		}
	}
	return 0;
}
