#include <iostream>
using namespace std;
class Countstr {
	int count;
	char c[100];
public:
	Countstr() { 
		count = 0;
		cout << "���ù��캯��" << endl;
		input();
	}
	void input() {
		cout << "�������ַ�:";
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
	cout << "������ַ���Ϊ:" << s.getchar() << endl;
	return 0;
}