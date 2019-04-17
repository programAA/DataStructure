#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
//话说大诗人李白，一生好饮。幸好他从不开车。
//一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：
//无事街上走，提壶去打酒。逢店加一倍，遇花喝一斗。
//这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。
//请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。
//则：babaabbabbabbbb 就是合理的次序。像这样的答案一共有多少呢？
//请你计算出所有可能方案的个数（包含题目给出的）
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


