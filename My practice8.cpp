#include <iostream>
using namespace std;
class Countstr {
	int count;
	char c[100];
public:
	Countstr() 
	{ 
		count = 0;
		cout << "���ù��캯��" << endl;
	}
	void countchar();
	int getchar();
};

void Countstr::countchar()
{
	cout << "�������ַ�:";
	cin >> c;
}

int Countstr::getchar()
{
	while (c[count] != '\0')
	{
		count = count + 1;
	}
	return count;
}

int main()
{
	Countstr s;
	s.countchar();
	cout << "������ַ���Ϊ:" << s.getchar() << endl;
	return 0;
}