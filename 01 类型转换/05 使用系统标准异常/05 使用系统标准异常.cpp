#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stdexcept> //使用系统提供的标准异常头文件

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			//越界 抛出一个越界异常
			throw out_of_range("年龄越界了！");
		}

		this->m_Age = age;
	}
	int m_Age;
};


void test01()
{
	try
	{
		Person p1(1000);
	}
	catch ( out_of_range & e )// exception & e  = out_of_range("年龄越界了！"); 发生多态
	{
		cout << e.what() << endl; //打印输出错误提示内容
	}


}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}