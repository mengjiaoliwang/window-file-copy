#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <stdexcept>

//编写我自己的一个 out_of_range类
class MyOutOfRangeException : public  exception
{
public:
	MyOutOfRangeException(string errorText)
	{
		this->m_ErrorInfo = errorText;
	}

	~MyOutOfRangeException()
	{
	}

	const char * what() const 
	{
		//string -> char *  利用 .c_str();
		return this->m_ErrorInfo.c_str();
	}

	string m_ErrorInfo;
	
};


class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			//越界 抛出一个越界异常
			throw MyOutOfRangeException(  string("我自己提供的  年龄越界了！"));
		}

		this->m_Age = age;
	}
	int m_Age;
};

void test01()
{
	try
	{
		Person p1(10000);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;;
	}
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}