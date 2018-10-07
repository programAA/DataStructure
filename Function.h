#ifndef FUNCTION_H
#define FUNCTION_H
typedef int(*Ptr)(int, int);
int add(int a, int b)
{
	return a + b;
}
int min(int a, int b)
{
	return a - b;
}
int fun1(int(*p)(int,int), int a, int b)
{
	return p(a, b);
}
int fun2(Ptr p, int a, int b)
{
	return p(a, b);
}
int turn(int x)//整数反向输出
{
	int temp = 0;
	while (x != 0)
	{
		temp = temp * 10 + x % 10;
		x = x / 10;
	}
	return temp;
}

void setValue(int **A, int m, int n, int value) {
	for (int i = m; i <= n; i++) {
		for (int j = m; j <= n; j++)
			A[i][j] = value;
	}
}

int** createM(int n){
	int time = (n / 2 == 0) ? n / 2 : n / 2 + 1;
	int x = 1;
	int **A = new int*[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	for (int i = 0; i < time; i++) {
		setValue(A, i, n - 1 - i, x);
		x++;
	}
	return A;
}

void displayM(int **A,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << A[i][j]<<"  ";
		std::cout << std::endl;
	}
}
#endif