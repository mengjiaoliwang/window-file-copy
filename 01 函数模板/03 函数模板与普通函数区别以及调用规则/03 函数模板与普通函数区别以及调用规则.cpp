#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}

//���� ��ͨ�������Խ�����ʽ����ת����ģ�庯������Զ������Ƶ�������������ʽ����ת��
void test01()
{
	int a = 1;
	int b = 2;
	char c = 'c'; // 99 
	// ������Զ������Ƶ� ������ģ���ǲ�������ʽ����ת����
	//cout << myPlus(a, c) << endl;

	//�������ͨ��������������ʽ����ת��
	cout << myPlus2(a, c) << endl;

}


/////////////////////////////////////////////// ���ù��� /////////////////////////////////////////////
template<class T>
void myPrint(T a, T b)
{
	cout << "����ģ��ĵ���" << endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "����ģ��ĵ��� a b c" << endl;
}

//����ģ��ͨ���������Ͳ�����ͬ�ĺ���
//ͨ��ģ�� �����ĺ��� �ͽ� ģ�庯��
//void myPrint(int a, int b, int c)
//{
//	cout << "����ģ��ĵ��� a b c" << endl;
//}
//void myPrint(double a, double b, double c)
//{
//	cout << "����ģ��ĵ��� a b c" << endl;
//}



void myPrint(int a, int b)
{
	cout << "��ͨ�����ĵ���" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	//myPrint(a, b);
	//1�������ͨ�����ͺ���ģ�嶼����ƥ����ã�����ʹ����ͨ�����ĵ���

	//2�������ǿ�Ƶ��ú���ģ�壬�ÿ�ģ������б���Ե���
	myPrint<>(a, b);

	int c = 30;
	//3������ģ�壬Ҳ���Է�������
	myPrint(a, b, c);


	//4���������ģ����Բ������õ�ƥ�䣬��ô����ѡ����ģ�����
	char c1 = 'c';
	char d1 = 'd';
	myPrint(c1, d1);
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}