//ͨ�������ָ��ɾ������������ǣ�ͨ�������ֻ���û��۵���������
//���ǣ�ɾ��һ�����������ʱ��Ӧ���ȵ��������������������Ȼ����û������������
//����취�ǣ��ѻ����������������Ϊvirtual
//һ����˵��һ��������������麯������Ӧ�ý���������Ҳ������麯����
//����һ���������Ϊ����ʹ�ã�ҲӦ�ý���������������麯����
//���������麯����Ϊ���캯��

#include <iostream>
using namespace std;

class son {
public:
	virtual ~son() { cout << "son destruct!" << endl; }
};

class grandson :public son {
public:
	~grandson() { cout << "grandson destruct!" << endl; }
};

int main(){
	son *p;
	p = new grandson();
	delete p;
	return 0;
}