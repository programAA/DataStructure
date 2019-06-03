#include <iostream>
using namespace std;
class Countstr {
	int count;
	char c[100];
public:
	Countstr() { 
		count = 0;
		cout << "调用构造函数" << endl;
		input();
	}
	void input() {
		cout << "请输入字符:";
		cin >> c;
	}
	int getchar();
};

int Countstr::getchar() {
	while (c[count] != '\0') {
		count++;
	}
	return count;
}

int main()
{
	Countstr s;
	cout << "输入的字符数为:" << s.getchar() << endl;
	return 0;
}