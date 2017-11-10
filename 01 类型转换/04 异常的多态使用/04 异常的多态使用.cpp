#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BaseException
{
public:
	virtual void printError() = 0;
};

//空指针异常
class NullPointerException:public BaseException
{
public:
	virtual void printError()
	{
		cout << "空指针异常" << endl;
	};
};
//越界异常
class OutofRangeException :public BaseException
{
public:
	virtual void printError()
	{
		cout << "越界异常" << endl;
	};
};

void doWork()
{
	//抛出一个空指针异常
	//throw NullPointerException();

	//抛出越界
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