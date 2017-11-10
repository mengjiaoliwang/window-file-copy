#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1����̬����ת��

class Base{};
class Son :public Base{};
class Other{};

void test01()
{

	//��̬����ת�������﷨��  static_cast<Ŀ������>(ԭ���󡢱���)
	//������������ת��
	char c = 'a';
	double d = static_cast<double>(c);
	cout << d << endl;


	//����֮���ת��
	Base * base = NULL;
	Son * son = NULL;

	//base תSon����  ����ȫ  ��������ת��
	Son * son1 = static_cast<Son*>(base);

	//son תΪ Base����   ��ȫ  ��������ת��
	Base * base1 = static_cast<Base*>(son);


	//����������ת��
	Base base2;
	Son son2;

	Base &base_ref = base2;

	Son& son_ref = static_cast<Son&>(base_ref);


	//ת��������
	//base תΪ Other  //ת����Ч
	//Other * other = static_cast<Other*>(base);

}


//2����̬����ת��
class Base2
{
	virtual void func();
};
class Son2 :public Base2
{
	virtual void func();
};
class Other2{};
void test02()
{
	//������������ ������ת��
	//char c = 'a';
	//double d = dynamic_cast<double>(c);
	//cout << d << endl;

	Base2 * base = NULL;
	Son2 * son = NULL;

	//son תΪ Base2*  ��ȫ 
	Base2 * base2 = dynamic_cast<Base2*>(son);

	//base תΪ Son2* ����ȫ  ����
	//��������ж�̬ ����ô�ǰ�ȫ��
	Son2* son2 = dynamic_cast<Son2*>(base);
}


//����ת��
void test03()
{
	//�Ƴ�const
	const int * p = NULL;
	int *p1 = const_cast<int*>(p);

	//����const
	int * pp = NULL;
	const int * pp1 = const_cast<const int*>(pp);

	//ֻ�ܶ�ָ��������� ��const���� �Ƴ�const
	/*const int a = 10;
	int b = const_cast<int>(a);*/

}

//���½���ת��
void test04()
{
	int a = 10;
	int * p = reinterpret_cast<int*>(a);


	Base * base = NULL;
	//��Ƽ�ʹ�õ�ת��
	Other * other = reinterpret_cast<Other*>(base);
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}