#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>

class Person
{
public:
	Person(){};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};


//打印person类型的数组
void printPerson(MyArray<Person>&p)
{
	for (int i = 0; i < p.getSize();i++)
	{
		cout << " 姓名：" << p[i].m_Name << " 年龄： " << p[i].m_Age << endl;
	}
}

void test01()
{
	MyArray <int>array(10); //声明  十个int类型的数组
	for (int i = 0; i < 10;i++)
	{
		array.push_back(i);
	}

	/*for (int i = 0; i < array.getSize();i++)
	{
		cout << array[i] << endl;
	}*/

	Person p1("大娃", 10);
	Person p2("二娃", 9);
	Person p3("三娃", 4);
	Person p4("蛇精", 999);
	Person p5("爷爷", 10000);


	//如果是自定义是数据类型，肯定会调用Person的默认构造函数
	MyArray <Person>arrayPerson(5);

	arrayPerson.push_back(p1);
	arrayPerson.push_back(p2);
	arrayPerson.push_back(p3);
	arrayPerson.push_back(p4);
	arrayPerson.push_back(p5);

	printPerson(arrayPerson);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}