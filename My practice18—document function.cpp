/*
tellg() �� tellp()
��������Ա�������ô������������pos_type ���͵�ֵ(����ANSI-C++ ��׼) ������һ������������ǰget ��ָ���λ�� (��tellg) �� put ��ָ���λ��(��tellp).
seekg() ��seekp()
��Ժ����ֱ������ı���ָ��get ��put��λ�á�����������������Ϊ���ֲ�ͬ��ԭ�ͣ�
seekg ( pos_type position );
seekp ( pos_type position );
ʹ�����ԭ�ͣ���ָ�뱻�ı�Ϊָ����ļ���ʼ�����һ������λ�á�Ҫ����Ĳ��������뺯�� tellg ��tellp �ķ���ֵ������ͬ��
seekg ( off_type offset, seekdir direction );
seekp ( off_type offset, seekdir direction );
ʹ�����ԭ�Ϳ���ָ���ɲ���direction������һ�������ָ�뿪ʼ�����һ��λ��(offset)���������ǣ�
ios::beg  ������ʼλ�ü����λ��
ios::cur  ����ָ�뵱ǰλ�ÿ�ʼ�����λ��
ios::end  ����ĩβ����ʼ�����λ��
��ָ�� get �� put ��ֵ���ı��ļ�(text file)�Ͷ������ļ�(binary file)�ļ��㷽�����ǲ�ͬ�ģ���Ϊ�ı�ģʽ���ļ���ĳЩ�����ַ����ܱ��޸ġ�
�������ԭ�򣬽�������ı��ļ�ģʽ�򿪵��ļ�����ʹ��seekg �� seekp�ĵ�һ��ԭ�ͣ����Ҳ�Ҫ��tellg �� tellp �ķ���ֵ�����޸ġ�
�Զ������ļ������������ʹ����Щ������Ӧ�ò������κ��������Ϊ������

��һ������ (write) ��ostream ��һ����Ա���������Ǳ�ofstream���̳С�����read����istream ��һ����Ա��������ifstream ���̳С�
�� fstream �Ķ���ͬʱӵ�����������������ǵ�ԭ���ǣ�
write ( char * buffer, streamsize size );
read ( char * buffer, streamsize size );
���� buffer ��һ���ڴ�ĵ�ַ�������洢��������ݡ�����size ��һ������ֵ����ʾҪ�ӻ��棨buffer���ж�����д����ַ�����

1��gets(str);
�Ǵӻ������ж�ȡ�ַ�����Ȼ�󱣴浽����str��ֱ�������س��������з�����Ϊ�ַ��������ݣ���ȡ�Ļ��з���ת��ΪNULLֵ���ɴ˱�־����Ľ�����
2��cin.getline(char*line,int size,char ='"n')�Ƕ���һ���ַ�,�ڶ��������Ǳ��ζ�ȡ������ַ������������������Ƿָ��ַ�����Ϊ��ȡһ�н����ı�־,Ĭ����\n��
3��cin.get()��һ���÷����Ƕ���һ���ַ��� cin.get()�ڶ����÷���Ҳ������һ�У�ͬcin.getline()��������������ǣ�������ָ���
����һ�£�
cin.getline() �� cin>>str ��һ����ͬ�ǣ�ǰ������һ�У����п��԰����ո񣬺���ȴ�Կո��س���Ϊ�ִ��������������ո�
���䣺get() ��getline()����ͬ
1����ͬ�㣺
Ҫ��ȡһ�е����룬��׼����ĳ�Ա����getline(),get()������������������getline(char*line,int size,char ='\n')��
���е�һ������ָ��洢����ַ��Ļ�����ָ�룬�ڶ�����ʾ��������С�����ζ�ȡ������ַ����������ܹ��������޶ȣ���
��������ʾ֪��ʲôʱ��ֹͣ���������ֹ������ȡһ�н����ı�־������ֹ����һ�������õ���ȱʡֵ"\n"��������������������ֹ��ʱ�������㴢���ڽ���������
2����ͬ�㣺
1.һ��������get()һ�ζ���һ���ַ���getline()һ�ζ���һ���ַ�
2.�ڴ����ַ���ʱ��get()�����������ķָ���ʱ��ֹͣ������������������ȡ�ָ�����
������cin.get(myarray1,20,'*'); �����ַ���1111*2222������*��ֹͣ��cout<<myarray1;�����1111��
Ȼ���ٵ���cin.get(ch1)��cout<<ch1;����Ļ�������ָ���*��getline()�����෴����������������ȡ�ָ���������û�а��������ڽ���������
�����cin.getline(myarray2,20,'*');��������ͬ�����ַ���1111*2222������*ֹͣ�� cout<<myarray2;�����1111��
Ȼ���ٵ���cin.get(ch2)��cout<<ch2;������Ƿָ��������2��
*/
//1����дһ������ͳ���ļ�abc.txt���ַ�������
/*
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream in;//��
	ofstream out;//д��
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
	cout << "�ַ���Ϊ:" << n << endl;
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
		cout << "��ʧ��" << endl;
		return -1;
	}
	cout << "����ѧ����Ϣ:" << endl;
	string a;		
	cout << "����:" << endl;
	cin >> a;
	out << "����:" << a << endl;
	cout << "������ѧ��:" << endl;
	string b;
	cin >> b;
	out << "ѧ��:" << b << endl;
	out.close();
	ifstream in;
	in.open("d:\\abc.txt", ios::in);
	if (!in.is_open())
	{
		cout << "��ʧ�ܣ�" << endl;
		return -1;
	}
	string c;
	while (getline(in,c))
	{
		cout << c << endl;
	}
	cout << "��ָ��λ��:" << in.tellg() << endl;
	cout << "�ļ��Ƿ����:" << in.eof() << endl;
	cout << "���Ƿ���Ч:" << in.good() << endl;
	in.clear();//��ʱeof�Ѿ���λ������clear���eof��λ��ʹ��ָ��ص��ļ���ʼλ��
	cout << "��ָ��λ��:" << in.tellg() << endl;
	in.seekg(0);
	cout << "��ָ��λ��:" << in.tellg() << endl;
	cout << "�ļ��Ƿ����:" << in.eof() << endl;
	cout << "���Ƿ���Ч:" << in.good() << endl;
	int n = 0;
	char ch;
	in.seekg(0,ios::beg);
	while (in.get(ch))
		n++;
	cout << "�ַ�����Ϊ:" << n << endl;
	in.close();
	system("pause");
	return 0;
}
*/