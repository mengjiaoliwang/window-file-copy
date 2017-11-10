#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>
#include <string>

/*
3.7.2.1 set构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数
3.7.2.2 set赋值操作
set& operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器
3.7.2.3 set大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

3.7.2.4 set插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。
*/

void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

void test01()
{
	set<int>s1;

	//添加数据 用 insert
	s1.insert(10);
	s1.insert(6);
	s1.insert(3);
	s1.insert(1);
	s1.insert(7);
	//关联式容器 内部已经做好了排序规则，从小到大默认
	printSet(s1);
	
	s1.erase(6); //可以直接删除6，本质 按照key来进行删除

	printSet(s1);

	if (s1.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空 大小：" << s1.size() << endl;
	}
}

/*
3.7.2.5 set查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key);//查找键key的元素个数  对于set而言 结果无非是 0 或者 1
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

void test02()
{
	set<int>s1;
	//添加数据 用 insert
	s1.insert(10);
	s1.insert(6);
	s1.insert(3);
	s1.insert(1);
	s1.insert(7);


	//找容器中是否有1这个元素
	set<int>::iterator pos = s1.find(1);
	if ( pos != s1.end())
	{
		cout << "找到了 " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//找7的个数
	int num  = s1.count(7);
	cout << "7的个数为： " << num << endl;


	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	set<int>::iterator it = s1.lower_bound(3);
	if (it!=s1.end())
	{
		cout << "找到了lower_bound的值为：  " << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	set<int>::iterator it2 = s1.upper_bound(3);
	if (it2 != s1.end())
	{
		cout << "找到了upper_bound的值为：  " << *it2 << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

	pair<set<int>::iterator, set<int>::iterator > pair1 = s1.equal_range(3);

	//获取第一个对组中的值
	if (pair1.first != s1.end())
	{
		cout << "找到了equal_range 中 lower_bound的值为： " << *(pair1.first) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	if (pair1.second != s1.end())
	{
		cout << "找到了equal_range 中 upper_bound的值为： " << *(pair1.second) << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
		
}


void test03()
{
	set<int>s1;
	//第一个插入 10
	pair<set<int>::iterator, bool>  pair1 = s1.insert(10);

	if (pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}


	pair1 = s1.insert(10); //set不允许插入重复的key值

	if (pair1.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;
	}


	//printSet(s1);

	//对于multiset而言 ，可以插入重复的key值
	multiset<int>s2;
	s2.insert(10);
	s2.insert(10);

}

//利用仿函数
class Mycompare
{
public:
	bool operator()( int v1 ,int v2)
	{
		return v1 > v2;
	}
};

void test04()
{

	set<int, Mycompare>s1;
	//如果想改变排序规则，在插入数据前 指定规则

	//添加数据 用 insert
	s1.insert(10);
	s1.insert(6);
	s1.insert(3);
	s1.insert(1);
	s1.insert(7);

	//内部排序规则 默认  从小到大
	//修改排序规则 从大到小

	for (set<int, Mycompare>::iterator it = s1.begin(); it != s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

class MycomparePerson
{
public:
	bool operator()( const Person  &p1, const Person &p2 )
	{
		//按照年龄升序排序
		return p1.m_Age < p2.m_Age;
	}

};

void test05()
{
	//对于自定义数据类型，必须提前指定好排序规则
	set<Person, MycomparePerson>s1;

	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 40);
	Person p4("赵六", 30);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person, MycomparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	}

}


int main(){

	//test01();

	//test02();

	//test03();

	//test04();
	
	test05();

	system("pause");
	return EXIT_SUCCESS;
}