#include <iostream>
#include <iomanip>
using namespace std;
int a[9] = { 0 };
int Count = 0;

bool judge(int a[]) {
	//�ж��Ƿ������ʽ
	int x = 100 * a[0] + 10 * a[1] + a[2];
	int y = 100 * a[3] + 10 * a[4] + a[5];
	int z = 100 * a[6] + 10 * a[7] + a[8];
	if (x + y == z)
		return true;
	else 
		return false;
}
bool check(int num) {
	//��������Ƿ����ظ�
	for (int i = num - 1; i >= 0; i--) {
		if (a[num] == a[i])
			return false;
	}
	return true;
}

void dfs(int num) {
	if (num > 8) {
		if (judge(a)) {
			Count++;
		}
		return;
	}
	//�����forѭ�����ƾŸ�����ȫ����
	for (int i = 1; i < 10; i++) {
		a[num] = i;
		if (check(num)) {
			dfs(num + 1);
		}
	}
}

int main() {
	dfs(0);
	cout << Count << endl;
	return 0;
}
