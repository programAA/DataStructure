/*
#include <iostream> 
#include <string>
using namespace std;  
int wlf[5];//dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ  
string wrname[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
class HeadQ
{
	int lifen;//����Ԫ  
	int wno;//��ʿ�������  
	int worrior[5];//5����ʿ���ε�����  
	string name;
	bool stop;//�Ƿ�ֹͣ������ʿ  

public:
	HeadQ(int lfn = 0, string snm = "") :lifen(lfn), wno(0), name(snm), stop(0)
	{
		memset(worrior, 0, sizeof(worrior));
	}
	bool gen_wr(int time, int k)//���ɱ��Ϊk����ʿ  
	{
		if (lifen < wlf[k])
		{
			return false;
		}
		wno++;
		worrior[k]++;
		lifen = lifen - wlf[k];
		cout.fill('0');//��������ַ���һֱ��Ч  
		cout.width(3);//�����Ϊ3��һ����Ч  
		cout << time << " " << name << " " << wrname[k] << " " << wno << " born with strength " << wlf[k] << ","
			<< worrior[k] << " " << wrname[k] << " in " << name << " headquarter" << endl;
		return true;
	}
	bool is_stop(int time)
	{
		bool flag = 0;//��־�Ƿ���Լ���������ʿ  
		for (int i = 0; i < 5; ++i)
		{
			if (lifen >= wlf[i]) { flag = 1; break; }//ֻҪ����������һ����ʿ  
		}
		if (flag == 0){
			cout.fill('0');//��������ַ���һֱ��Ч  
			cout.width(3);//�����Ϊ3��һ����Ч  
			cout << time << " " << name << " headquarter stops making warriors" << endl;
			stop = true;
			return true;
		}
		return false;
	}
	bool getstopflag() { return stop; }
};
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cout << "Case:" << i << endl;
		int m;
		cin >> m;
		cin >> wlf[0] >> wlf[1] >> wlf[2] >> wlf[3] >> wlf[4];
		HeadQ redhq(m, "red");//�췽��iceman��lion��wolf��ninja��dragon˳��:2,3,4,1,0  
		HeadQ bluehq(m, "blue");//������lion��dragon��ninja��iceman��wolf˳��:3,0,1,2,4  
		int redsx[5] = { 2,3,4,1,0 };
		int bluesx[5] = { 3, 0, 1, 2, 4 };
		int time = 0;
		int redk = 0;
		int bluek = 0;
		while (redhq.getstopflag() == false || bluehq.getstopflag() == false){
			while (redhq.getstopflag() == false && redhq.is_stop(time) == false && redhq.gen_wr(time, redsx[redk]) == false)//��û��ֹͣ������ʿ��������ʿʧ��ʱ��������һ�������ɵ���ʿ  
	        {
				redk = (redk + 1) % 5;
			}
			redk = (redk + 1) % 5;
			while (bluehq.getstopflag() == false && bluehq.is_stop(time) == false && bluehq.gen_wr(time, bluesx[bluek]) == false)//��û��ֹͣ������ʿ��������ʿʧ��ʱ��������һ�������ɵ���ʿ  
			{
				bluek = (bluek + 1) % 5;
			}
			bluek = (bluek + 1) % 5;
			time++;
		}
	}
	return 0;
}
*/

/*
#include "CArray.h"
using namespace std;
int main()
{
	CArray a;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	for (int i = 0; i < 9; i++)
		a.push_back(i);
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	CArray b(a);
	cout << b.size() << endl;
	cout << b.capacity() << endl;
	for (int i = 0; i < 9; i++)
		cout << b[i] << endl;
	return 0;
}
*/

/*
#include <iostream>
#include "Graph.h"	
using namespace std;
int main()
{
	LGraph Graph = BuildLGraph();
	int dist[5] = { -1,-1,-1 ,-1,-1};
	int path[5] = { -1,-1,-1 ,-1,-1};
	Unweighted(Graph, dist, path, 0);
	cout << dist[3] << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;

	}
	~MyString() { if (p) delete[] p; }
	MyString(MyString &s1) {
		if (s1.p) {
			p = new char[strlen(s1.p) + 1];
			strcpy(p, s1.p);
		}
		else p = NULL;
	}
	void Copy(const char *s) {
		if (s) {
			delete[]p;
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else p = NULL;
	}
    friend ostream& operator<<(ostream &os,const MyString &s1) {
		os << s1.p;
		return os;
	}
	MyString& operator =(const char *s) {
		if (s) {
			delete[]p;
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else p = NULL;
		return *this;
	}
	MyString &operator =(const MyString& s) {
		if (s.p) {
			delete[]p;
			p = new char[strlen(s.p) + 1];
			strcpy(p, s.p);
		}
		else p = NULL;
		return *this;
	}
};
int main()
{
	char w1[200], w2[100];
	while (cin >> w1 >> w2) {
		MyString s1(w1), s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;//s2=123456
		s3 = s2;//s3=123456
		s1 = s3;//s1=123456
		cout << s1 << "," << s2 << "," << s3 << endl;
	}
}
*/

/*
#include <iostream> 
using namespace std;
class MyInt
{
	int nVal;
public:
	MyInt(int n) { nVal = n; }
	// �ڴ˴�������Ĵ���
	MyInt& operator-(const int n) {
		nVal -= n;
		return *this;
	}
	operator int() { return nVal; };
};
int Inc(int n) {
	return n + 1;
}
int main() {
	int n;
	while (cin >> n) {
		MyInt objInt(n);
		objInt - 2 - 1 - 3;
		cout << Inc(objInt);
		cout << ",";
		objInt - 2 - 1;
		cout << Inc(objInt) << endl;
	}
	return 0;
}
*/

/*
#include <iostream> 
using namespace std;
class Point {
private:
	int x;
	int y;
public:
	Point() { };
	// �ڴ˴�������Ĵ���
	friend istream& operator>>(istream &is, Point &p) {
		is >> p.x >> p.y;
		return is;
	}
	friend ostream& operator<<(ostream &os, const Point &p) {
		os << p.x << ',' << p.y;
		return os;
	}
};
int main()
{
	Point p;
	while (cin >> p) {
		cout << p << endl;
	}
	return 0;
}
*/

/*
#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
	// �ڴ˴�������Ĵ���
private:
	int row;
	int col;
	int **p;
public:
	Array2() :row(0), col(0) { p = NULL; }
	Array2(int row_, int col_) :row(row_), col(col_) {
		p = new int*[row];//pָ��һ��ָ������
		for (int i = 0; i < row; ++i) {
			p[i] = new int[1];//p[i]���int��ָ��
		}
	}
	int* operator[](int i) {
		//����[]
		return p[i];
	}
	int operator()(int x, int y) {
		//����()
		return p[x][y];
	}
	Array2& operator=(const Array2& a) {
		//���صȺ�
		if (p != NULL) {
			for (int i = 0; i < row; ++i) {
				delete[]p[row];//p��Ϊ��ʱ���ͷ�p[i]ָ���int������Ŀռ�
			}
			delete[]p;//�ͷ�pָ���ָ������Ŀռ�
		}
		p = new int *[a.row];//pָ��ָ������
		for (int i = 0; i < a.row; ++i) {
			p[i] = new int[a.col];//��p[i]ָ�����ָ��Ŀռ�
		}
		for (int i = 0; i < a.row; ++i) {
			for (int j = 0; j < a.col; ++j) {
				p[i][j] = a.p[i][j];
			}
		}
		return *this;
	}
};
int main() {
	int x, y;
	cin >> x >> y;
	Array2 a(x, y);
	int i, j;
	for (i = 0; i < x; ++i)
		for (j = 0; j < y; j++)
			a[i][j] = i * y + j;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < y; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     b = a;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < y; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
*/

/*
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i, j, n;
	cout << "�����뷶Χ�ұ߽�:";
	cin >> n;
	int *s = (int *)malloc(sizeof(int)*(n + 1));
	for (i = 1; i <= n; ++i)
		s[i] = i;
	for (i = 2; i <= sqrt(n); ++i)
		for (j = 2 * i; j <= n; j += i)
			s[j] = 0;
	j = 0;
	for (i = 2; i < n; ++i) {
		if (s[i]) {
			cout << left << setw(5) << s[i];
			j++;
			if (j % 10 == 0)
				cout << endl;
		}
	}
	cout << endl;
	cout << "��������Ϊ:" << j << endl;
	free(s);
	return 0;
}
*/


/*
//����оƬ
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	int i, j, n, a, b;
	cin >> n;
	cin >> a >> b;
	clock_t start, finish;
	start = clock();
	int *s = new int[n + 1];
	for (i = 0; i <= n; ++i)
		s[i] = -1;
	for (i = 2; i <= n; i++)
		for (j = i; j <= n; j += i)
			s[j] = -s[j];
	n = 0;
	for (i = a; i <= b; ++i)
		if (s[i] == 1)
			n++;
	finish = clock();
	cout << "��ʱ" << (finish - start) / CLOCKS_PER_SEC << "��" << endl;
	delete[]s;
	cout << n << endl;
	return 0;
}
*/

/*
//��������
#include <iostream>	
#include <string>
using namespace std;
int Rank(string::iterator a,string::iterator b)
{
	int n = 0;
	auto c = a+1;
	while (c != b) {
		if (*a > *c)
			n++;
		++c;
	}
	return n;
}
int factorial(int n) {
	int m = 1;
	for (int i = 1; i <= n; i++) {
		m *= i;
	}
	return m;
}
int main() 
{
	string s;
	cin >> s;
	int n = s.size();
	int result = 0;
	auto a = s.begin();
	auto b = s.end();
	for (int i = n; i > 0; i--) {
		result = result + Rank(a, b)*factorial(i - 1);
		a = a + 1;
		if (a == b)
			break;
	}
	cout << result << endl;
	return 0;
}
*/





/*
#include <iostream>
#include <string>
using namespace std;
//�����ҵ���һ����s[i]<s[i+1],�ٵ����ҵ���һ��s[y]>s[i]
//����s[i]��s[y],����s�����Դ�Ĵ�
void swap(string s)
{
	int len = s.length();
	int i, a, b;
	for (i = len - 1; i > 0; --i) {
		if (s[i - 1] < s[i]) {
			a = i - 1;
			break;
		}
	}
	for (i = len - 1; i >= 0; --i) {
		if (s[i] > s[a]) {
			b = i;
			break;
		}
	}
	char c=s[a];
	s[a] = s[b];
	s[b] = c;
	for (i = 0; i <= a; i++)
		cout << s[i];
	for (i = len - 1; i > a; --i)
		cout << s[i];
}

int main() {
	string  s;
	cin >> s;
	swap(s);
	return 0;
}
*/

/*
#include <iostream>
#include "Function.h"
using namespace std;
int main() {
	int n;
	cin >> n;
	int **A = createM(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
*/
