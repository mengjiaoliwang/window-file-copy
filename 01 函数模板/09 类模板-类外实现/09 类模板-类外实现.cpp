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
	//	cout << "������ " << this->m_Name << "  ���䣺 " << this->m_Age << endl;
	//}

	NameType m_Name;
	AgeType m_Age;
};


//���������ʵ�� ��ģ���еĳ�Ա����
//Person(NameType name, AgeType age);
// ����ֵ ������<ģ����� ,ģ�����2>::ʵ�ֳ�Ա����(){}
template< class NameType, class AgeType >
Person<NameType, AgeType>::Person(NameType name, AgeType age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template< class NameType, class AgeType >
void  Person<NameType, AgeType>::showPerson()
{
	cout << "������ " << this->m_Name << "  ���䣺 " << this->m_Age << endl;
}

void test01()
{
	Person <string ,int>p("����", 11);
	p.showPerson();

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}