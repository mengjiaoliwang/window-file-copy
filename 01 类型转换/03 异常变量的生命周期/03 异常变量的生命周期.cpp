#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyException
{
public:

	MyException()
	{
		cout << "默认构造函数调用" << endl;
	}
	MyException(const MyException& e)
	{
		cout << "拷贝构造函数调用" << endl;
	}

	~MyException()
	{
		cout << "析构函数调用" << endl;
	}

	void printError()
	{
		this->m_a = 10;
		cout << "自己的异常" << endl;
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
	catch (MyException &e) //用引用的方式 会提高效率，节省开销，推荐用引用传递
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
	catch (MyException *e) //用引用的方式 会提高效率，节省开销，推荐用引用传递
	{
		//e->printError(); // throw   &MyException(); 野指针调用成员函数 ，非法操作,不要去使用这个指针了

		e->printError();

		delete e; //靠自觉去释放这个对象
	}
}

int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}