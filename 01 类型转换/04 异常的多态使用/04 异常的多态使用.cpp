#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BaseException
{
public:
	virtual void printError() = 0;
};

//��ָ���쳣
class NullPointerException:public BaseException
{
public:
	virtual void printError()
	{
		cout << "��ָ���쳣" << endl;
	};
};
//Խ���쳣
class OutofRangeException :public BaseException
{
public:
	virtual void printError()
	{
		cout << "Խ���쳣" << endl;
	};
};

void doWork()
{
	//�׳�һ����ָ���쳣
	//throw NullPointerException();

	//�׳�Խ��
	throw OutofRangeException();
}

void test01()
{
	try
	{
		doWork();
	}
	catch (BaseException &e)  // BaseException & e = NullPointerException();
	{
		e.printError();
	}
	
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}