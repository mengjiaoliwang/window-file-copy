#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "showPerson1 ����" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "showPerson2 ����" << endl;
	}
};

template<class T> // typename
class MyClass
{
public:
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}

	T obj; //T���͵�����
};

//��ģ���е� ��Ա�����������ڿ�ʼ�ʹ����õģ����Ƕ��α����ڼ��ȥ������
void test01()
{
	MyClass<Person1> p1;
	p1.func1();

	//p1.func2();
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}