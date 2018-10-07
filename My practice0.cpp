#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> ws;
	string word;
	while (cin >> word)
		ws.push_back(word);
	auto it = ws.begin();
	while (it != ws.end())
	{
		cout << *it << endl;
		++it;
	}
	return 0;
}





/*
#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
Stack S = InitStack();
int i;
cout << GetTop(S) << endl;
for (i = 1; i < 102; i++)
{
S = Push(S, i);
cout << GetTop(S) << "  ";
if (i % 10 == 0)
cout << endl;
}
cout << endl;
cout << "�洢����:" << S->stacksize << endl;
cout << "Ԫ������:" << S->top - S->base << endl;
Pop(S);
cout << GetTop(S) << endl;
cout << "Ԫ������:" << S->top - S->base << endl;
cout << S->base[100] << endl;
system("pause");
return 0;
}
*/
/*
#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
Queue Q = InitQueue();
cout << Q->front->data;
cout << endl;
EnQueue(Q, 1);
cout << Q->rear->data << endl;
EnQueue(Q, 2);
cout << Q->rear->data << endl;
cout << Q->front->next->data << endl;
DeQueue(Q);
cout << Q->front->next->data << endl;
system("pause");
return 0;
}
*/
/*
#include <iostream>
#include <time.h>
using namespace std;
int fbi(int n)
{
if (n == 1 || n == 2)
return 1;
else return (fbi(n - 2) + fbi(n - 1)) % 10007;
}
int fbi2(int n)
{
int f1 = 1, f2 = 1, fn;
while (n == 1 || n == 2)
return 1;
for (int i = 3; i <= n; i++)
{
fn = f1 + f2;
f1 = f2;
f2 = fn;
}
return fn % 10007;
}
int main()
{
int n = 45;
clock_t start, finish;
start = clock();
cout << fbi(n) << endl;
finish = clock();
cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;
start = clock();
cout << fbi2(n) << endl;
finish = clock();
cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;
system("pause");
return 0;
}
*/
/*
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
char a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
clock_t start, finish;
start = clock();
for (a1 = 'A'; a1 < 'E'; a1++)
for (a2 = 'A'; a2 < 'E'; a2++)
for (a3 = 'A'; a3 < 'E'; a3++)
for (a4 = 'A'; a4 < 'E'; a4++)
for (a5 = 'A'; a5 < 'E'; a5++)
for (a6 = 'A'; a6 < 'E'; a6++)
for (a7 = 'A'; a7 < 'E'; a7++)
for (a8 = 'A'; a8 < 'E'; a8++)
for (a9 = 'A'; a9 < 'E'; a9++)
for (a10 = 'A'; a10 < 'E'; a10++)
{
//�ڶ���
if (a2 == 'A'&&a5 != 'C') continue;
if (a2 == 'B'&&a5 != 'D') continue;
if (a2 == 'C'&&a5 != 'A') continue;
if (a2 == 'D'&&a5 != 'B') continue;
//������
if (a3 == 'A' && !(a6 == a2 && a6 == a4 && a6 != a3)) continue;
if (a3 == 'B' && !(a3 == a2 && a3 == a4 && a3 != a6)) continue;
if (a3 == 'C' && !(a3 == a6 && a3 == a4 && a3 != a2)) continue;
if (a3 == 'D' && !(a3 == a6 && a3 == a2 && a3 != a4)) continue;
//������
if (a4 == 'A'&&a1 != a5) continue;
if (a4 == 'B'&&a2 != a7) continue;
if (a4 == 'C'&&a1 != a9) continue;
if (a4 == 'D'&&a6 != a10) continue;
//������
if (a5 == 'A'&&a8 != 'A') continue;
if (a5 == 'B'&&a4 != 'B') continue;
if (a5 == 'C'&&a9 != 'C') continue;
if (a5 == 'D'&&a7 != 'D') continue;
//������
if (a6 == 'A' && (a2 == a4 && a2 != a8)) continue;
if (a6 == 'B' && (a1 == a6 && a1 != a8)) continue;
if (a6 == 'C' && (a3 == a10 && a3 != a8)) continue;
if (a6 == 'D' && (a5 == a9 && a5 != a8)) continue;
//������
int ca=0, cb=0, cc=0, cd=0;
for (int i = 1; i <= 10; i++)
{
char ch;
switch (i)
{
case 1:ch = a1; break;
case 2:ch = a2; break;
case 3:ch = a3; break;
case 4:ch = a4; break;
case 6:ch = a6; break;
case 5:ch = a5; break;
case 7:ch = a7; break;
case 8:ch = a8; break;
case 9:ch = a9; break;
case 10:ch = a10; break;
}
switch (ch)
{
case 'A':ca++; break;
case 'B':cb++; break;
case 'C':cc++; break;
case 'D':cd++; break;//ͳ��ABCD���м���
}
}
int max = -1;
int min = 11;
char min_char;
if (max < ca) max = ca;
if (max < cb) max = cb;
if (max < cc) max = cc;
if (max < cd) max = cd;//�ĸ�if����maxΪ���ֵ
if (min > ca) { min = ca; min_char = 'A'; }
if (min > cb) { min = cb; min_char = 'B'; }
if (min > cc) { min = cc; min_char = 'C'; }
if (min > cd) { min = cd; min_char = 'D'; }//�ĸ�if����minΪ��Сֵ
if (a7 == 'A'&&min_char != 'C') continue;
if (a7 == 'B'&&min_char != 'B') continue;
if (a7 == 'C'&&min_char != 'A') continue;
if (a7 == 'D'&&min_char != 'D') continue;
//�ڰ���
if (a8 == 'A' && (a1 - a7 == -1 || a1 - a7 == 1)) continue;
if (a8 == 'B' && (a1 - a5 == -1 || a1 - a5 == 1)) continue;
if (a8 == 'C' && (a1 - a2 == -1 || a1 - a2 == 1)) continue;
if (a8 == 'D' && (a1 - a10 == -1 || a1 - a10 == 1)) continue;
//�ھ���
if (a1 == a6)
{
if (a9 =='A' && a5 == a6) continue;
if (a9 =='B' && a5 == a10) continue;
if (a9 =='C' && a5 == a2) continue;
if (a9 =='D' && a5 == a9) continue;
}
else
{
if (a9 =='A' && a5 != a6) continue;
if (a9 =='B' && a5 != a10) continue;
if (a9 =='C' && a5 != a2) continue;
if (a9 =='D' && a5 != a9) continue;
}
//��ʮ��
if (a10 == 'A' && (max - min) != 3) continue;
if (a10 == 'B' && (max - min) != 2) continue;
if (a10 == 'C' && (max - min) != 4) continue;
if (a10 == 'D' && (max - min) != 1) continue;
cout << "question1:" << a1 << endl;
cout << "question2:" << a2 << endl;
cout << "question3:" << a3 << endl;
cout << "question4:" << a4 << endl;
cout << "question5:" << a5 << endl;
cout << "question6:" << a6 << endl;
cout << "question7:" << a7 << endl;
cout << "question8:" << a8 << endl;
cout << "question9:" << a9 << endl;
cout << "question10:" << a10 << endl;
}
finish = clock();
cout << "��ʱ" << (finish - start) / CLOCKS_PER_SEC << "��" << endl;
system("pause");
return 0;
}
*/
/*
#include <iostream>
#include "Function.h"
using namespace std;
int main()
{
int x = 195;
while (x != turn(x))
{
cout << x << "+" << turn(x) << "=";
x = x + turn(x);
cout << x << endl;
}
system("pause");
return 0;
}
*/
/*
#include <iostream>
using namespace std;
void move(int n, char a, char b, char c)
{//��ŵ���ݹ��㷨
if (n == 1)
{
cout << a << "-->" << c << endl;
return;
}
move(n - 1, a, c, b);
cout << a << "-->" << c << endl;
move(n - 1, b, a, c);
}
int main()
{
char a = 'A', b = 'B', c = 'C';
move(3, a, b, c);
system("pause");
return 0;
}
*/
/*
#include "Tree.h"
int main()
{
	Tree T = NULL;
	T = Insert(18, T);
	Insert(10, T);
	Insert(20, T);
	Insert(7, T);
	Insert(15, T);
	Insert(22, T);
	Traverse1(T);
	Traverse11(T);
	Traverse22(T);
	Traverse2(T);
	system("pause");
	return 0;
}
*/

/*
#include<iostream>
using namespace std;
typedef int *A;
int main()
{
A a;
a = (A)malloc(sizeof(int));
cout << *a << endl;
cout << a << endl;
a = (A)malloc(sizeof(int));
cout << a << endl;
cout << *a << endl;
system("pause");
return 0;
}
*/

/*
#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
int a[10] = { 1,5,4,7,8,9,6,4,5,2 };
for (int i = 0; i < 10; i++)
cout << a[i] << endl;
Merge_sort(a, 10);
for (int i = 0; i < 10; i++)
cout << a[i] << endl;
system("pause");
return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	double a = 3.14;
	const int &b = a;
	cout << a << endl << b << endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
	Matrix M,T;
	int t;
	cout << "�������������:";
	cin >> M.mu;
	cout << "�������������:";
	cin >> M.nu;
	cout << "���������Ԫ�ظ���:";
	cin >> M.tu;
	cout << "���������Ԫ�ص���,�к�ֵ:" << endl;
	for (t = 1; t <= M.tu; ++t) {
		cin >> M.data[t].i >> M.data[t].j >> M.data[t].e;
	}
	T = Transpose(M);
	cout << M;
	cout << endl;
	cout << T;
	system("pause");
	return 0;
}
*/
/*
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD p = { 10,10 };
	SetConsoleCursorPosition(h, p);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(h, BACKGROUND_GREEN );
	cout << "abcdefghijklmnopqrst" << endl;
	cout << "abcd" << endl;
	system("pause");
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	
	int * a[] = { NULL,NULL,new int[1],new int[6] };
	*a[2] = 123;
	a[3][5] = 456;
	if (!a[0]) {
		cout << *a[2] << "," << a[3][5];
	}
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
int GetBit(char c, int i) {
	//ȡc�ĵ�iλ
	return (c >> i) & 1;
}
void SetBit(char &c, int i, int v) {
	//����c�ĵ�iλΪv
	if (v)
		c |= (1 << i);
	else
		c &= ~(1 << i);
}
void Flip(char &c, int i) {
	//��c�ĵ�iλȡ��
	c ^= (1 << i);
}
void output(int t, char result[]) {
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 6; j++) {
			cout << GetBit(result[i], j);
			if (j < 5)
				cout << ' ';
		}
		cout << endl;
	}
}
int main()
{
	char orilights[5];//����ĵƾ���
	char lights[5];//�仯�ĵƾ���
	char result[5];//����ƾ���
	char switchs;//ĳ�е�״̬
	memset(orilights, 0, sizeof(orilights));//�ƾ�����0
	for (int i = 0; i < 5; i++) {//�������״̬
		for (int j = 0; j < 6; j ++ ) {
			int s;
			cin >> s;
			SetBit(orilights[i], j, s);
		}
	}
	memcpy(lights, orilights, sizeof(orilights));
	for (int n = 0; n < 64; n++) {//��������64�ֿ��ط���
		switchs = n;//��i�еĿ��ط���
		for (int i = 0; i < 5; i++) {
			result[i] = switchs;
			for (int j = 0; j < 6; j++) {
				if (GetBit(lights[i], j)) {//�ı��е�״̬
					if (j > 0)
						Flip(lights[i], j - 1);
					Flip(lights[i], j);
					if (j < 5)
						Flip(lights[i], j + 1);
				}
			}
			if (i < 4) {
				lights[i + 1] ^= switchs;//����һ�е�״̬
				switchs = lights[i];//��һ�п��ط���
			}
		}
		if (lights[4] == 0) {
			output(n, result);
			break;
		}
	}
	system("pause");
	return 0;
}

*/

/*
#include <iostream>
#include <string>
using namespace std;
void Flip(char &c) {
	c = c == '1' ? '0' : '1';
}
int main()
{
	string origin, result, temp;
	int t;
	int r1,r2;
	cin >> origin;
	cin >> result;
	int n = origin.size();
	temp = origin;
	if (n >= 2) {
		t = 0;
		for (int i = 1; i < n; i++) {
			if (temp[i - 1] != result[i - 1]) {
				Flip(temp[i - 1]);
				Flip(temp[i]);
				if (i + 1 < n)
					Flip(temp[i + 1]);
				t++;
			}
		}
		if (temp[n - 1] == result[n - 1])
			r1 = t;
		else r1 = 0;
		origin[0] = origin[0] == '1' ? '0' : '1';
		origin[1] = origin[1] == '1' ? '0' : '1';
		t = 1;
		for (int i = 1; i < n; i++) {
			if (origin[i - 1] != result[i - 1]) {
				Flip(origin[i - 1]);
				Flip(origin[i]);
				if (i + 1 < n)
					Flip(origin[i + 1]);
				t++;
			}
		}
		if (origin[n - 1] == result[n - 1])
			r2 = t;
		else r2 = 0;
		if (r1 || r2)
			cout << (r1 > r2 ? r1 : r2) << endl;
		else
			cout << "impossible" << endl;
	}
	else
		cout << 1 << endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
double bolan()
{
	char s[20];
	cin >> s;
	switch (s[0]){
	case '+':return bolan() + bolan();
	case '-':return bolan() - bolan();
	case '*':return bolan() * bolan();
	case '/':return bolan() / bolan();
	default :return atof(s);
	}
}
int main()
{
	cout << bolan() << endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
int factor();
int term();
int expression();
int expression()
{
	int result = term();
	while (true) {
		char c = cin.peek();
		if (c == '+' || c == '-') {
			cin.get();
			int value = term();
			if (c == '+') result += value;
			else result -= value;
		}
		else break;
	}
	return result;
}
int term()
{
	int result = factor();
	while (true) {
		char c = cin.peek();
		if (c == '*' || c == '/') {
			cin.get();
			int value = factor();
			if (c == '*') result *= value;
			else result /= value;
		}
		else break;
	}
	return result;
}
int factor()
{
	int result = 0;
	char c = cin.peek();
	if (c == '(') {
		cin.get();
		result = expression();
		cin.get();
	}
	else
		while (isdigit(c)) {
			result = 10 * result + c - '0';
			cin.get();
			c = cin.peek();
		}
	return result;
}
int main()
{
	cout << "������Ҫ����ı��ʽ:";
	cout << expression() << endl;
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	char name[20];
	unsigned int age;
	unsigned int num;
	unsigned int score[4];
public:
	void input() {
		char c;
		cin.getline(name, 20, ',');
		cin >> age>>c;
		cin >> num>>c;
		cin >> score[0] >> c >> score[1] >> c >> score[2] >> c >> score[3];
	}
	double calculate() {
		return (score[0] + score[1] + score[2] + score[3]) / 4.0;
	}
	void output() {
		cout << name << ',' << age << ',' << num << ',' << calculate();
	}

};

int main() {
	Student student;        // ������Ķ���
	student.input();        // ��������
	student.calculate();    // ����ƽ���ɼ�
	student.output();       // �������
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	Complex() { r = 0; i = 0; }
	Complex(const char a[]) {//����ת�����캯��
		r = a[0] - '0';
		i = a[2] - '0';
	}
};
int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
#include <string>
using namespace std;
class Base {
public:
	int k;
	Base(int n) :k(n) { }
};
class Big
{
public:
	int v;
	Base b;
	Big(int i = 0) :v(i), b(i) { }
};
int main()
{
	int n;
	while (cin >> n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
class Animal {
public:
	static int number;
	virtual ~Animal() {}
};
class Dog:public Animal {
public:
	static int number;
	Dog() { number++; Animal::number++; }
	~Dog() { number--; Animal::number--; }
};
class Cat:public Animal{
public:
	static int number;
	Cat() { number++; Animal::number++; }
	~Cat() { number--; Animal::number--; }
};
int Animal::number = 0;
int Dog::number = 0;
int Cat::number = 0;
void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;//����ָ��ָ�����������ֻ���û������������������취������������������
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}
*/
/*
#include <iostream>
using namespace std;
struct A
{
	int v;
	A(int vv) :v(vv) { }
	A* getPointer(){
	    return this;
	}//��������
	A* getPointer() const{
		return (A*)this;
	}
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();//�����������治��ִ�зǳ�����Ա����
	cout << p->v << endl;
	return 0;
}
*/
