#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyException
{
public:

	MyException()
	{
		cout << "Ĭ�Ϲ��캯������" << endl;
	}
	MyException(const MyException& e)
	{
		cout << "�������캯������" << endl;
	}

	~MyException()
	{
		cout << "������������" << endl;
	}

	void printError()
	{
		this->m_a = 10;
		cout << "�Լ����쳣" << endl;
	}

	int m_a;
};

void doWork()
{
	throw MyException();
}

void test01()
{
	try
	{
		doWork();
	}
	catch (MyException e)
	{
		e.printError();
	}
}

void doWork2()
{
	throw MyException();
}
void test02()
{
	try
	{
		doWork2();
	}
	catch (MyException &e) //�����õķ�ʽ �����Ч�ʣ���ʡ�������Ƽ������ô���
	{
		e.printError();
	}
}

void doWork3()
{
	throw  new MyException();
}
void test03()
{
	try
	{
		doWork3();
	}
	catch (MyException *e) //�����õķ�ʽ �����Ч�ʣ���ʡ�������Ƽ������ô���
	{
		//e->printError(); // throw   &MyException(); Ұָ����ó�Ա���� ���Ƿ�����,��Ҫȥʹ�����ָ����

		e->printError();

		delete e; //���Ծ�ȥ�ͷ��������
	}
}

int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}