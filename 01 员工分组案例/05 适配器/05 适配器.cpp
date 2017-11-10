#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

//1、函数对象适配器
class myPrint : public binary_function<int,int,void>
{
public:
	void operator()(int val,int start) const
	{	
		cout <<  "val = "<< val <<  " start = " << start << " sum = "<< val + start << endl;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	int num;
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd( myPrint(), num) ); //推荐
	//for_each(v.begin(), v.end(), bind1st(myPrint(), num));
}

//适配器使用
//第一步 绑定  bind2nd
//第二步 继承 两个参数 继承 binary_function<参数类型1，参数类型2，返回值类型>
//第三步 加const



class GreaterThenFive :public unary_function<int,bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};
//2、取反适配器
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//找一个大于5的数字
	//取反适配器 一元取反
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterThenFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(),  not1(bind2nd(greater<int>(),5))  );

	if (pos != v.end())
	{
		cout << "找到小于5的数字：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//二元取反 从大到小
	sort(v.begin(), v.end(), not2(less<int>()));

	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
}


void myPrint3(int val ,int start)
{
	cout << val + start << endl;
}
//3、函数指针适配器
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//普通函数指针 适配成函数对象 利用 ptr_fun
	for_each(v.begin(), v.end(),  bind2nd( ptr_fun( myPrint3) , 100));
}

//4、成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << " 成员函数中的 姓名： " << m_Name << " 年龄： " << m_Age << endl;
	}

	void addAge()
	{
		this->m_Age++;
	}

	string m_Name; //姓名
	int m_Age;//年龄
};

//void myPrintPerson( Person &p)
//{
//	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;;
//}

void test04()
{
	vector<Person>v;
	Person p1("aaaa", 10);
	Person p2("bbbb", 20);
	Person p3("cccc", 30);
	Person p4("dddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//利用 mem_fun_ref
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}



int main(){

	//test01();
	//test02();
	
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}