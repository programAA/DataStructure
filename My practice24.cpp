#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int Count = 0;
int Count1 = 0;
//�Ӻ���ǰ��
void dfs1(int a, int b, int wine) {//0 1 1--5 10 2
	Count1++;
	if (a == 5 && b == 10 && wine == 2)
		Count++;
	else {
		if (wine % 2 == 0) {
			a++;//����������
			wine /= 2;
			if (a <= 5 && b <= 10 && wine >= 1)
				dfs1(a, b, wine);
			a--;
			wine *= 2;//������һ����״̬
		}
		b++;//����������
		wine++;
		if (a <= 5 && b <= 10 && wine >= 1)
			dfs1(a, b, wine);
		b--;//������һ����״̬
		wine--;
	}
}



//��ǰ�����
void dfs(int a, int b, int wine) {
	Count1++;
	if (a == 0 && b == 0 && wine == 1)
		Count++;//���Ͻ����������һ
	else {
		b--;//�ȼ���������
		wine--;
		if (a >= 0 && b >= 0 && wine >= 1)
			dfs(a, b, wine);
		b++;//������һ����״̬
		wine++;
		a--;//�ټ���������
		wine *= 2;
		if (a >= 0 && b >= 0 && wine >= 1)
			dfs(a, b, wine);
		a++;
		wine /= 2;//������һ����״̬
		
	}
}


int main() {
	int a = 0;
	int b = 1;
	int wine = 1;
	clock_t start, finish;
	start = clock();
	dfs1(a, b, wine);
	finish = clock();
	cout << "��ʱ" << setprecision(5) << (double)(finish - start) / CLOCKS_PER_SEC << "��" << endl;
	cout << Count << endl;
	cout << Count1 << endl;
	return 0;
}


