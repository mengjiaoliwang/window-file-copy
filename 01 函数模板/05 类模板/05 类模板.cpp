#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

// 2 、类模板中的 类型 可以有默认值
template<class NameType ,class AgeType = int >
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
		cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	NameType m_Name; //姓名
	AgeType m_Age; //年龄
};

void test01()
{
	//1、 类模板  不可以进行 自动类型转换（隐式类型转换）
	//必须显示指定类型
	Person<string > p1("MT", 10);

	p1.showPerson();

}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}