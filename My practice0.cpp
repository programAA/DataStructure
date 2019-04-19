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
	//ȡc�ĵ�iλ
	return (c >> i) & 1;
}
void SetBit(char &c, int i, int v) {
	//����c�ĵ�iλΪv
	if (v)
		c |= (1 << i);
	else
		c &= ~(1 << i);
}
void Flip(char &c, int i) {
	//��c�ĵ�iλȡ��
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
	char orilights[5];//����ĵƾ���
	char lights[5];//�仯�ĵƾ���
	char result[5];//����ƾ���
	char switchs;//ĳ�е�״̬
	memset(orilights, 0, sizeof(orilights));//�ƾ�����0
	for (int i = 0; i < 5; i++) {//�������״̬
		for (int j = 0; j < 6; j ++ ) {
			int s;
			cin >> s;
			SetBit(orilights[i], j, s);
		}
	}
	memcpy(lights, orilights, sizeof(orilights));
	for (int n = 0; n < 64; n++) {//��������64�ֿ��ط���
		switchs = n;//��i�еĿ��ط���
		for (int i = 0; i < 5; i++) {
			result[i] = switchs;
			for (int j = 0; j < 6; j++) {
				if (GetBit(lights[i], j)) {//�ı��е�״̬
					if (j > 0)
						Flip(lights[i], j - 1);
					Flip(lights[i], j);
					if (j < 5)
						Flip(lights[i], j + 1);
				}
			}
			if (i < 4) {
				lights[i + 1] ^= switchs;//����һ�е�״̬
				switchs = lights[i];//��һ�п��ط���
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
	cout << "������Ҫ����ı��ʽ:";
	cout << expression() << endl;
	system("pause");
	return 0;
}
*/
