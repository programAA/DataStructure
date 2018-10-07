//КЏЪ§жиди
#include <iostream>
using namespace std;
double aver(int a[], int n)
{
	double s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + a[i];
	}
	return s / n;
}
double aver(double a[], int n)
{
	double s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + a[i];
	}
	return s / n;
}
int main()
{
	int a[5] = { 5,4,3,2,6 };
	double b[7] = { 1.5,6.5,2.6,3.5,7.5,7.6,7.5 };
	cout << "a(aver)=" << aver(a, 5) << endl;
	cout << "b(aver)=" << aver(b, 7) << endl;
	return 0;
}