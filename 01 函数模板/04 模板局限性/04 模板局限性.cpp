#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
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

template<class T>
void mySwap(T & a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}


//�ṩһ����Person���н����� ģ��
template<> void mySwap<Person>(Person & a, Person &b)
{
	cout << "ͨ�����廯�ķ�ʽ ���� Person�Ľ���" << endl;
	Person Temp;
	Temp.m_Name = a.m_Name;
	a.m_Name = b.m_Name;
	b.m_Name = Temp.m_Name;

	Temp.m_Age = a.m_Age;
	a.m_Age = b.m_Age;
	b.m_Age = Temp.m_Age;
}

void test01()
{
	Person p1("TOM", 18);
	Person p2("Jerry", 20);

	cout << "p1 ������ " << p1.m_Name << " ���䣺" << p1.m_Age << endl;
	cout << "p2 ������ " << p2.m_Name << " ���䣺" << p2.m_Age << endl;

	cout << "������ " << endl;
	mySwap(p1, p2);
	cout << "p1 ������ " << p1.m_Name << " ���䣺" << p1.m_Age << endl;
	cout << "p2 ������ " << p2.m_Name << " ���䣺" << p2.m_Age << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}