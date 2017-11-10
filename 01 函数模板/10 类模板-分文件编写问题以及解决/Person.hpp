#pragma  once
#include <iostream>
using namespace std;
#include <string>


template<class NameType, class  AgeType >
class Person
{
public:
	Person(NameType name, AgeType age);

	void showPerson();

	NameType m_Name;
	AgeType m_Age;
};


template< class NameType, class AgeType >
Person<NameType, AgeType>::Person(NameType name, AgeType age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template< class NameType, class AgeType >
void  Person<NameType, AgeType>::showPerson()
{
	cout << "ÐÕÃû£º " << this->m_Name << "  ÄêÁä£º " << this->m_Age << endl;
}
