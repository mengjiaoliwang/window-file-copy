#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyException
{
public:
	void printError()
	{
		 cout << "我的异常抛出" << endl;
	}
	

};

class Person
{
public:
	Person()
	{
		cout << "Person的构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}

};

int myDivide(int a, int b)
{
	if (b == 0)
	{
		//return -1;
		//抛出异常
		//throw 1; //抛出int类型异常
		//throw 3.14; //抛出double异常
		//throw 'a'; //抛出char异常


		//栈解旋
		//在try代码开始后  到throw代码之前 所有栈中的内容 ，都会被释放掉，这个过程就叫栈解旋

		Person p1;
		Person p2;

		throw MyException(); //抛出一个 MyException的匿名对象
	}

	return a / b;
}


void test01()
{
	int a = 10;
	int b = 0;

	//异常的基本语法
	try  //尝试
	{
		myDivide(a, b);
	}
	catch (int )
	{
		cout << "捕获了int类型的异常" << endl;
	}
	catch (double)
	{
		//捕获到了异常 ，不去处理异常，而是向上继续抛出异常 ，利用throw
		//如果向上抛出的异常 依然没有被处理，那么程序调用 terminate函数，进行终止程序
		throw;
		cout << "捕获了double类型的异常" << endl;
	}
	catch (MyException e)
	{
		e.printError();
	}
	catch (...)
	{
		cout << "捕获了其他类型的异常" << endl;
	}


}


int main(){


	try
	{
		test01();
	}
	catch (char)
	{
		cout << "main函数中捕获char类型异常" << endl;
	}
	catch (...)
	{
		cout << "main函数中捕获其他类型异常" << endl;
	}
	

	system("pause");
	return EXIT_SUCCESS;
}