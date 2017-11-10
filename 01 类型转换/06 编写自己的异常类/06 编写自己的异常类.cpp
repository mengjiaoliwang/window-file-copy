#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <stdexcept>

//��д���Լ���һ�� out_of_range��
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
		//string -> char *  ���� .c_str();
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
			//Խ�� �׳�һ��Խ���쳣
			throw MyOutOfRangeException(  string("���Լ��ṩ��  ����Խ���ˣ�"));
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