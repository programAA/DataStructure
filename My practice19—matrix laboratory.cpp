/*
#include <iostream>
#include <iomanip>
using namespace std;
template <typename T,int row,int col>
class Matrix {
	T mat[row][col];
public:
	friend istream& operator >>(istream &is, Matrix<T, row, col> &a)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				is >> a.mat[i][j];
			}
		}
		return is;
	}
	friend ostream& operator <<(ostream &os, Matrix<T, row, col> &a)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				os <<setw(4)<<setiosflags(ios::left)<<a.mat[i][j];
			}
			os << endl;
		}
		return os;
	}
	friend Matrix<T, row, col>& operator +(Matrix<T, row, col> &a, Matrix<T, row, col> &b)
	{
		Matrix<T, row, col> m;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				m.mat[i][j] = a.mat[i][j] + b.mat[i][j];
			}
		}
		return m;
	}
};
int main()
{
	Matrix<int, 2, 2> x, y, z;
	cin >> x;
	cin >> y;
	cout << x;
	cout << y;
	z = x + y;
	cout << z;
	system("pause");
	return 0;
}
*/