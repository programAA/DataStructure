#include <iostream>
using namespace std;
int main()
{
	int a[5][4];
	int m , n = 0, i, j, k, l, p = 1;
	for (int b = 0; b < 5; b++)
	{
		for (int c = 0; c < 4; c++)
			cin >> a[b][c];//输入五行四列矩阵
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			m = a[i][j];//循环判断矩阵所有元素是否是鞍点
			for (k = 0; k < 4; k++)
			{
				if (m < a[i][k])//如果m不是一行中最大的数
					p = 0;//则m不是鞍点，p赋值为0，表示否定
			}
			if (p == 1)//如果p=1，即m是一行中最大的数，再判断m是否是一列中最小的
			{
				for (l = 0; l < 5; l++)
				{
					if (m > a[l][j])//如果m不是一列中最小的
					{
						p == 0;//则m不是鞍点，p赋值为0，表示否定
						break;//跳出for循环，判断下一个元素是否是鞍点
					}
				}
			}
			if (p == 1)//如果是鞍点，输出，计数加一
			{
				n++;
				cout << "第" << i + 1 << "行第" << j + 1 << "列的元素" << m << "为鞍点" << endl;
			}
		}
	}
	if (n == 0)
		cout << "没有鞍点" << endl;
	else
		cout << "鞍点总数为:" << n << endl;
	return 0;
}