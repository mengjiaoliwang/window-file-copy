#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void swapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapDouble(double &d1, double &d2)
{
	double temp = d1;
	d1 = d2;
	d2 = temp;
}

//����ģ��ļ���  ʵ��ͨ�ú���
// �߼�����һ��  ��ֻ�ǲ������Ͳ�ͬ�� �������� �� ������
// ���Ͳ������� ���ͱ��

template< typename T > //����һ��ģ��,���߱���������������ŵĺ����������� ������T����Ҫ�������Ǹ����ܵ�����
void mySwap(T & a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template< typename T >
void mySwap2()
{
	cout << "helloworld" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);

	//ģ��ʹ�÷�ʽ
	//1���Զ������Ƶ�,�����ñ������Ƶ���T�����ͣ��ſ���ʹ��
	char c1 = 'c';
	mySwap(a, b);

	//2����ʾָ�������Ƶ�
	mySwap<int>(a, b);

	cout << "a  = " << a << endl;
	cout << "b  = " << b << endl;

	//�����ñ������Ƶ���T�����ͣ��ſ��Ե���ģ��
	mySwap2<double>();


	double c = 1.1;
	double d = 3.14;
//	swapDouble(c, d);

	mySwap(c, d);

	cout << "c  = " << c << endl;
	cout << "d  = " << d << endl;


}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}