#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>


// friend void showPerson2<>(Person<T1, T2>&p);  必须让编译器 先看到有这个模板
//让编译器再看到Person的声明
template<class T1, class T2>class Person;
template<class T1, class T2>void showPerson2(Person<T1, T2> & p);

template<class T1, class T2>
class Person
{

	//1 、友元函数在类内实现
	//利用全局函数 打印Person对象的属性
	// 只是一个普通的函数
	friend void showPerson( Person<T1,T2>&p)
	{
		cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
	}

	//2、 友元函数在类外实现 加入空模板参数列表 ，变为模板的声明
	friend void showPerson2<>(Person<T1, T2>&p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

//类外做showPerson2的实现
template<class T1, class T2>
void showPerson2(Person<T1, T2>&p)
{
	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

void test01()
{
	Person <string ,int>p1("孙悟空", 1000);
	//showPerson(p1);

	showPerson2(p1);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}