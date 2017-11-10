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
		cout << "姓名： " << this->m_Name << "  年龄： " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void doWork( Person<string ,int>& p  ) // 1 、指定传入类型
{
	p.showPerson();
}

void test01()
{
	Person <string ,int >p1("MT", 19);
	doWork(p1);
}

template<class T1,class T2>
void doWork2( Person<T1,T2> & p) //2 、参数模板化
{
	cout << "T1 类型： "<< typeid(T1).name() << endl;
	cout << "T2 类型： " << typeid(T2).name() << endl;

	p.showPerson();
}

void test02()
{
	Person<string, int> p2("傻馒", 18);
	doWork2(p2);
}

template<class T>
void doWork3( T &p ) //将整个类模板化
{
	cout << "T 类型： " << typeid(T).name() << endl;
	p.showPerson();
}

void test03()
{
	Person<string, int> p3("呆贼", 30);
	doWork3(p3);

}




int main(){
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}