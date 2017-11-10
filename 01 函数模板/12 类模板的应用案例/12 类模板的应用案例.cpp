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


//��ӡperson���͵�����
void printPerson(MyArray<Person>&p)
{
	for (int i = 0; i < p.getSize();i++)
	{
		cout << " ������" << p[i].m_Name << " ���䣺 " << p[i].m_Age << endl;
	}
}

void test01()
{
	MyArray <int>array(10); //����  ʮ��int���͵�����
	for (int i = 0; i < 10;i++)
	{
		array.push_back(i);
	}

	/*for (int i = 0; i < array.getSize();i++)
	{
		cout << array[i] << endl;
	}*/

	Person p1("����", 10);
	Person p2("����", 9);
	Person p3("����", 4);
	Person p4("�߾�", 999);
	Person p5("үү", 10000);


	//������Զ������������ͣ��϶������Person��Ĭ�Ϲ��캯��
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