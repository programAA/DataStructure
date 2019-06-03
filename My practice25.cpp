#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD p = { 10,10 };
	SetConsoleCursorPosition(h, p);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(h, BACKGROUND_GREEN );
	cout << "abcdefghijklmnopqrst" << endl;
	cout << "abcd" << endl;
	return 0;
}

/*
#include <iostream>
using namespace std;
int GetBit(char c, int i) {
	//取c的第i位
	return (c >> i) & 1;
}
void SetBit(char &c, int i, int v) {
	//设置c的第i位为v
	if (v)
		c |= (1 << i);
	else
		c &= ~(1 << i);
}
void Flip(char &c, int i) {
	//将c的第i位取反
	c ^= (1 << i);
}
void output(int t, char result[]) {
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 6; j++) {
			cout << GetBit(result[i], j);
			if (j < 5)
				cout << ' ';
		}
		cout << endl;
	}
}
int main()
{
	char orilights[5];//最初的灯矩阵
	char lights[5];//变化的灯矩阵
	char result[5];//结果灯矩阵
	char switchs;//某行的状态
	memset(orilights, 0, sizeof(orilights));//灯矩阵置0
	for (int i = 0; i < 5; i++) {//输入最初状态
		for (int j = 0; j < 6; j ++ ) {
			int s;
			cin >> s;
			SetBit(orilights[i], j, s);
		}
	}
	memcpy(lights, orilights, sizeof(orilights));
	for (int n = 0; n < 64; n++) {//遍历首行64种开关方案
		switchs = n;//第i行的开关方案
		for (int i = 0; i < 5; i++) {
			result[i] = switchs;
			for (int j = 0; j < 6; j++) {
				if (GetBit(lights[i], j)) {//改本行灯状态
					if (j > 0)
						Flip(lights[i], j - 1);
					Flip(lights[i], j);
					if (j < 5)
						Flip(lights[i], j + 1);
				}
			}
			if (i < 4) {
				lights[i + 1] ^= switchs;//改下一行灯状态
				switchs = lights[i];//下一行开关方案
			}
		}
		if (lights[4] == 0) {
			output(n, result);
			break;
		}
	}
	system("pause");
	return 0;
}

*/

/*
#include <iostream>
#include <string>
using namespace std;
void Flip(char &c) {
	c = c == '1' ? '0' : '1';
}
int main()
{
	string origin, result, temp;
	int t;
	int r1,r2;
	cin >> origin;
	cin >> result;
	int n = origin.size();
	temp = origin;
	if (n >= 2) {
		t = 0;
		for (int i = 1; i < n; i++) {
			if (temp[i - 1] != result[i - 1]) {
				Flip(temp[i - 1]);
				Flip(temp[i]);
				if (i + 1 < n)
					Flip(temp[i + 1]);
				t++;
			}
		}
		if (temp[n - 1] == result[n - 1])
			r1 = t;
		else r1 = 0;
		origin[0] = origin[0] == '1' ? '0' : '1';
		origin[1] = origin[1] == '1' ? '0' : '1';
		t = 1;
		for (int i = 1; i < n; i++) {
			if (origin[i - 1] != result[i - 1]) {
				Flip(origin[i - 1]);
				Flip(origin[i]);
				if (i + 1 < n)
					Flip(origin[i + 1]);
				t++;
			}
		}
		if (origin[n - 1] == result[n - 1])
			r2 = t;
		else r2 = 0;
		if (r1 || r2)
			cout << (r1 > r2 ? r1 : r2) << endl;
		else
			cout << "impossible" << endl;
	}
	else
		cout << 1 << endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
double bolan()
{
	char s[20];
	cin >> s;
	switch (s[0]){
	case '+':return bolan() + bolan();
	case '-':return bolan() - bolan();
	case '*':return bolan() * bolan();
	case '/':return bolan() / bolan();
	default :return atof(s);
	}
}
int main()
{
	cout << bolan() << endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
int factor();
int term();
int expression();
int expression()
{
	int result = term();
	while (true) {
		char c = cin.peek();
		if (c == '+' || c == '-') {
			cin.get();
			int value = term();
			if (c == '+') result += value;
			else result -= value;
		}
		else break;
	}
	return result;
}
int term()
{
	int result = factor();
	while (true) {
		char c = cin.peek();
		if (c == '*' || c == '/') {
			cin.get();
			int value = factor();
			if (c == '*') result *= value;
			else result /= value;
		}
		else break;
	}
	return result;
}
int factor()
{
	int result = 0;
	char c = cin.peek();
	if (c == '(') {
		cin.get();
		result = expression();
		cin.get();
	}
	else
		while (isdigit(c)) {
			result = 10 * result + c - '0';
			cin.get();
			c = cin.peek();
		}
	return result;
}
int main()
{
	cout << "请输入要计算的表达式:";
	cout << expression() << endl;
	system("pause");
	return 0;
}
*/
