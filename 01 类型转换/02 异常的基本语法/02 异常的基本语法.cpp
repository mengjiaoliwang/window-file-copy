#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyException
{
public:
	void printError()
	{
		 cout << "�ҵ��쳣�׳�" << endl;
	}
	

};

class Person
{
public:
	Person()
	{
		cout << "Person�Ĺ��캯������" << endl;
	}
	~Person()
	{
		cout << "Person��������������" << endl;
	}

};

int myDivide(int a, int b)
{
	if (b == 0)
	{
		//return -1;
		//�׳��쳣
		//throw 1; //�׳�int�����쳣
		//throw 3.14; //�׳�double�쳣
		//throw 'a'; //�׳�char�쳣


		//ջ����
		//��try���뿪ʼ��  ��throw����֮ǰ ����ջ�е����� �����ᱻ�ͷŵ���������̾ͽ�ջ����

		Person p1;
		Person p2;

		throw MyException(); //�׳�һ�� MyException����������
	}

	return a / b;
}


void test01()
{
	int a = 10;
	int b = 0;

	//�쳣�Ļ����﷨
	try  //����
	{
		myDivide(a, b);
	}
	catch (int )
	{
		cout << "������int���͵��쳣" << endl;
	}
	catch (double)
	{
		//�������쳣 ����ȥ�����쳣���������ϼ����׳��쳣 ������throw
		//��������׳����쳣 ��Ȼû�б�������ô������� terminate������������ֹ����
		throw;
		cout << "������double���͵��쳣" << endl;
	}
	catch (MyException e)
	{
		e.printError();
	}
	catch (...)
	{
		cout << "�������������͵��쳣" << endl;
	}


}


int main(){


	try
	{
		test01();
	}
	catch (char)
	{
		cout << "main�����в���char�����쳣" << endl;
	}
	catch (...)
	{
		cout << "main�����в������������쳣" << endl;
	}
	

	system("pause");
	return EXIT_SUCCESS;
}