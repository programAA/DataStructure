//���ƹ��캯��ʹ�õ��������
//1����һ�������ʼ����һ������
//2�������Ĳ����Ƕ���
//3�������ķ���ֵ�Ƕ���

//����ת�����캯��
//1��ֻ��һ������
//2����Ҫʱ�����Ѳ������͵ı���ת��Ϊ����

//����ת�������
//1��д����ʱ��д����ֵ,����ֵʵ���������ص�����
//2����Ҫʱ�����Ѷ���ת��Ϊ����ֵ����

//��ֵ�����
//1���Ⱥ��������Ͳ�ƥ��ʱ����Ҫ���ظ�ֵ�����
//2����ʱ������ת�����캯��������ת�������������ɸ�ֵ������Ĺ���
#include <iostream>
using namespace std;

class Complex {
public:
	double real, imaginary;
	Complex(int i) {//����ת�����캯��
		cout << "IntConstructor called" << endl;
		real = i;
		imaginary = 0;
	}
	Complex(double r, double i) { real = r; imaginary = i; }
};

int main() {
	Complex c1(7, 8);
	Complex c2 = 12;//����������ת�����캯��
	c1 = 9;//����������ת�����캯��
	cout << c1.real << "," << c1.imaginary << endl;
	return 0;
}