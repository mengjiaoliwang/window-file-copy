#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>


template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age);
		/*{
			this->m_Name = name;
			this->m_Age = age;
			}*/

	void showPerson();
	//{
	//	cout << "姓名： " << this->m_Name << "  年龄： " << this->m_Age << endl;
	//}

	NameType m_Name;
	AgeType m_Age;
};


//如果在类外实现 类模板中的成员函数
//Person(NameType name, AgeType age);
// 返回值 作用域<模板参数 ,模板参数2>::实现成员函数(){}
template< class NameType, class AgeType >
Person<NameType, AgeType>::Person(NameType name, AgeType age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template< class NameType, class AgeType >
void  Person<NameType, AgeType>::showPerson()
{
	cout << "姓名： " << this->m_Name << "  年龄： " << this->m_Age << endl;
}

void test01()
{
	Person <string ,int>p("劣人", 11);
	p.showPerson();

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}