//һ����С��6��ż������������������ӵõ�
//��ӡ���н��

#include <iostream>
using namespace std;
int judge(int x) {//�ж�x�Ƿ�������
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
	cout << "������һ����С��6��ż��:";
	cin >> s;
	while (s < 6 || s % 2 != 0) {
		cout << "�����������������:";
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
