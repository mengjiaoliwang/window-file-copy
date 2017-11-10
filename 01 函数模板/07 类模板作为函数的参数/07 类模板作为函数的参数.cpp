#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "������ " << this->m_Name << "  ���䣺 " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void doWork( Person<string ,int>& p  ) // 1 ��ָ����������
{
	p.showPerson();
}

void test01()
{
	Person <string ,int >p1("MT", 19);
	doWork(p1);
}

template<class T1,class T2>
void doWork2( Person<T1,T2> & p) //2 ������ģ�廯
{
	cout << "T1 ���ͣ� "<< typeid(T1).name() << endl;
	cout << "T2 ���ͣ� " << typeid(T2).name() << endl;

	p.showPerson();
}

void test02()
{
	Person<string, int> p2("ɵ��", 18);
	doWork2(p2);
}

template<class T>
void doWork3( T &p ) //��������ģ�廯
{
	cout << "T ���ͣ� " << typeid(T).name() << endl;
	p.showPerson();
}

void test03()
{
	Person<string, int> p3("����", 30);
	doWork3(p3);

}




int main(){
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}