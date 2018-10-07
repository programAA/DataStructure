/*
tellg() 和 tellp()
这两个成员函数不用传入参数，返回pos_type 类型的值(根据ANSI-C++ 标准) ，就是一个整数，代表当前get 流指针的位置 (用tellg) 或 put 流指针的位置(用tellp).
seekg() 和seekp()
这对函数分别用来改变流指针get 和put的位置。两个函数都被重载为两种不同的原型：
seekg ( pos_type position );
seekp ( pos_type position );
使用这个原型，流指针被改变为指向从文件开始计算的一个绝对位置。要求传入的参数类型与函数 tellg 和tellp 的返回值类型相同。
seekg ( off_type offset, seekdir direction );
seekp ( off_type offset, seekdir direction );
使用这个原型可以指定由参数direction决定的一个具体的指针开始计算的一个位移(offset)。它可以是：
ios::beg  从流开始位置计算的位移
ios::cur  从流指针当前位置开始计算的位移
ios::end  从流末尾处开始计算的位移
流指针 get 和 put 的值对文本文件(text file)和二进制文件(binary file)的计算方法都是不同的，因为文本模式的文件中某些特殊字符可能被修改。
由于这个原因，建议对以文本文件模式打开的文件总是使用seekg 和 seekp的第一种原型，而且不要对tellg 或 tellp 的返回值进行修改。
对二进制文件，你可以任意使用这些函数，应该不会有任何意外的行为产生。

第一个函数 (write) 是ostream 的一个成员函数，都是被ofstream所继承。而（read）是istream 的一个成员函数，被ifstream 所继承。
类 fstream 的对象同时拥有这两个函数。它们的原型是：
write ( char * buffer, streamsize size );
read ( char * buffer, streamsize size );
这里 buffer 是一块内存的地址，用来存储或读出数据。参数size 是一个整数值，表示要从缓存（buffer）中读出或写入的字符数。

1、gets(str);
是从缓冲区中读取字符串，然后保存到数组str中直到遇到回车符，换行符不作为字符串的内容，读取的换行符会转换为NULL值，由此标志程序的结束。
2、cin.getline(char*line,int size,char ='"n')是读入一行字符,第二个参数是本次读取的最大字符个数，第三个参数是分隔字符，作为读取一行结束的标志,默认是\n。
3、cin.get()第一个用法，是读入一个字符。 cin.get()第二个用法，也是输入一行（同cin.getline()），但是区别就是，不输出分隔符
补充一下：
cin.getline() 与 cin>>str 的一个不同是，前者输入一行，行中可以包含空格，后者却以空格或回车作为字串结束，不包含空格。
补充：get() 和getline()的异同
1）相同点：
要获取一行的输入，标准流类的成员函数getline(),get()都有三个参数，比如getline(char*line,int size,char ='\n')。
其中第一个参数指向存储结果字符的缓冲区指针，第二个表示缓冲区大小（本次读取的最大字符个数，不能够超过其限度），
第三个表示知道什么时候停止读输入的终止符（读取一行结束的标志）。终止符有一个经常用到的缺省值"\n"。两个函数遇到输入终止符时，都把零储存在结果缓冲区里。
2）不同点：
1.一般来讲，get()一次读入一个字符，getline()一次读入一行字符
2.在处理字符串时，get()遇到输入流的分隔符时就停止，而不从输入流中提取分隔符。
比如用cin.get(myarray1,20,'*'); 处理字符串1111*2222，碰到*就停止。cout<<myarray1;会输出1111。
然后再调用cin.get(ch1)，cout<<ch1;输出的还是这个分隔符*。getline()与其相反，它从输入流中提取分隔符，但仍没有把它储存在结果缓冲区里。
如果用cin.getline(myarray2,20,'*');处理上面同样的字符串1111*2222，碰到*停止。 cout<<myarray2;会输出1111。
然后再调用cin.get(ch2)，cout<<ch2;输出的是分隔符后面的2。
*/
//1．编写一个程序，统计文件abc.txt的字符个数。
/*
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream in;//读
	ofstream out;//写入
	out.open("d:\\abc.txt",ios::out);
	out << "abcde";
	out.close();
	in.open("d:\\abc.txt", ios::in);
	if (!in.is_open())
	{
		cout << "Open Error!" << endl;
		return -1;
	}
	string a;
	char c;
	int n = 0;
	while (!in.eof())
	{
		in >> a;
		cout << a << endl;
	}
	in.seekg(0);
	while (in.get(c))
		n++;
	cout << "字符数为:" << n << endl;
	in.close();
	system("pause");
	return 0;
}
*/
/*
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream out;
	out.open("d:\\abc.txt", ios::out);
	if (!out.is_open())
	{
		cout << "打开失败" << endl;
		return -1;
	}
	cout << "输入学生信息:" << endl;
	string a;		
	cout << "姓名:" << endl;
	cin >> a;
	out << "姓名:" << a << endl;
	cout << "请输入学号:" << endl;
	string b;
	cin >> b;
	out << "学号:" << b << endl;
	out.close();
	ifstream in;
	in.open("d:\\abc.txt", ios::in);
	if (!in.is_open())
	{
		cout << "打开失败！" << endl;
		return -1;
	}
	string c;
	while (getline(in,c))
	{
		cout << c << endl;
	}
	cout << "流指针位置:" << in.tellg() << endl;
	cout << "文件是否结束:" << in.eof() << endl;
	cout << "流是否有效:" << in.good() << endl;
	in.clear();//此时eof已经置位，调用clear清除eof置位，使流指针回到文件开始位置
	cout << "流指针位置:" << in.tellg() << endl;
	in.seekg(0);
	cout << "流指针位置:" << in.tellg() << endl;
	cout << "文件是否结束:" << in.eof() << endl;
	cout << "流是否有效:" << in.good() << endl;
	int n = 0;
	char ch;
	in.seekg(0,ios::beg);
	while (in.get(ch))
		n++;
	cout << "字符总数为:" << n << endl;
	in.close();
	system("pause");
	return 0;
}
*/