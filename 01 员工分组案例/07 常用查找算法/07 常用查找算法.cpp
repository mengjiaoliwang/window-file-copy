#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
*/

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	//查一个元素  5;
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		cout << "找到了 " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==( const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}

	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 50);
	Person p5("eee", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//查找有没有 p4
	vector<Person>::iterator pos = find(v.begin(), v.end(), p4);
	if (pos != v.end())
	{
		cout << "找到了 姓名：" << (*pos).m_Name << " 年龄： " << (*pos).m_Age << endl;
	}

}

class MyFind :public binary_function<Person*,Person*,bool>
{
public:
	bool operator()(Person * p1 ,Person * p2) const
	{
		if (p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age)
		{
			return true;
		}
		return false;
	}
};

void test03()
{
	vector<Person*>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 50);
	Person p5("eee", 40);
	
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//查找  ccc 30

	Person * newPerson = new Person("ccc", 30);

	vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd( MyFind(), newPerson));

	 if (pos != v.end())
	 {
		 cout << "找到了 姓名：" << (*pos)->m_Name << " 年龄： " << (*pos)->m_Age << endl;
	 }
	 else
	 {
		 cout << "未找到" << endl;
	 }

}


/*
adjacent_find算法 查找相邻重复元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
@return 返回相邻元素的第一个位置的迭代器
*/

void test04()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(3);
	v.push_back(3);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		cout << "找到了相邻的重复元素 " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return bool 查找返回true 否则false
*/

void test05()
{
	//binary_search必须有序序列
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	//v.push_back(5); 必须有序

	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}


/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/

class MyCount
{
public:
	bool operator()(int val)
	{
		return val >= 3;
	}

};
void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	int num = count(v.begin(), v.end(), 3);
	cout << "3的个数为：" << num << endl;

	//count_if按条件统计

	//查找大于等于3的个数
	int num2 = count_if(v.begin(), v.end(), MyCount());
	cout << "大于等于 3的个数为：" << num2 << endl;

}


int main(){
	//test01();
	//test02();

	//test03();
	//test04();
	//test05();
	
	test06();
	
	system("pause");
	return EXIT_SUCCESS;
}