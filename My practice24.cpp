#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int Count = 0;
int Count1 = 0;
//从后向前推
void dfs1(int a, int b, int wine) {//0 1 1--5 10 2
	Count1++;
	if (a == 5 && b == 10 && wine == 2)
		Count++;
	else {
		if (wine % 2 == 0) {
			a++;//假设遇到店
			wine /= 2;
			if (a <= 5 && b <= 10 && wine >= 1)
				dfs1(a, b, wine);
			a--;
			wine *= 2;//返回上一步的状态
		}
		b++;//假设遇到花
		wine++;
		if (a <= 5 && b <= 10 && wine >= 1)
			dfs1(a, b, wine);
		b--;//返回上一步的状态
		wine--;
	}
}



//从前向后推
void dfs(int a, int b, int wine) {
	Count1++;
	if (a == 0 && b == 0 && wine == 1)
		Count++;//符合结果，次数加一
	else {
		b--;//先假设遇到花
		wine--;
		if (a >= 0 && b >= 0 && wine >= 1)
			dfs(a, b, wine);
		b++;//返回上一步的状态
		wine++;
		a--;//再假设遇到店
		wine *= 2;
		if (a >= 0 && b >= 0 && wine >= 1)
			dfs(a, b, wine);
		a++;
		wine /= 2;//返回上一步的状态
		
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
	cout << "用时" << setprecision(5) << (double)(finish - start) / CLOCKS_PER_SEC << "秒" << endl;
	cout << Count << endl;
	cout << Count1 << endl;
	return 0;
}


