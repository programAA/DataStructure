//��̬��Ա�����в��ܷ��ʷǾ�̬��Ա����(��������������ĸ������)
//Ҳ���ܵ��÷Ǿ�̬��Ա����(��Ȼ�Ǿ�̬��Ա�������ܵ��÷Ǿ�̬��Ա����)
//��̬��Ա����ֻ��һ�ݣ������и����͵Ķ�����
//sizeof�����������㾲̬��Ա����
//��̬��Ա���������ַ���
//������.��Ա��
//����::��Ա�� 
//ָ��->��Ա��
//����.��Ա��
#include <iostream>
using namespace std;

class Rectangle {
private:
	int w, h;
	static int TotalArea;
	static int TotalNumber;
public:
	Rectangle(int w,int h);
	~Rectangle();
	static void PrintTotal();
};
//ȱ��,ͨ�����ƹ��캯�����ɶ���ʱ�������ӣ�������ʱȴһ�����������������ȥ
//�������,��ʹ��ϵͳ�Զ����ɵĸ��ƹ��캯��,�Լ�дһ�����ƹ��캯��
Rectangle::Rectangle(int w,int h) {
	this->w = w;
	this->h = h;
	TotalNumber++;
	TotalArea += w * h;
}
Rectangle::~Rectangle() {
	TotalNumber--;
	TotalArea -= w * h;
}
void Rectangle::PrintTotal() {
	cout << TotalNumber<< ',' << TotalArea << endl;
}

int Rectangle::TotalArea = 0;
int Rectangle::TotalNumber = 0;

int main() {
	Rectangle r1(3, 3), r2(4, 4);
	Rectangle *r3 = new Rectangle(5, 5);
	Rectangle *r4;
	Rectangle::PrintTotal();
	delete r3;
	r1.PrintTotal();
	r3->PrintTotal();
	r4->PrintTotal();
	return 0;
}