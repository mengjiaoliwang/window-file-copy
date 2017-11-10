#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector> //vector的容器
#include <algorithm> //算法头文件
#include <string>

//原生指针 也算迭代器
//迭代器主要 进行遍历 容器
void test01()
{
	int array[5] = { 1, 4, 7, 3, 0 };
	int * p = array; // 指针p指向 数组首地址  &array[0]
	for (int i = 0; i < 5;i++)
	{
		//cout << array[i] << endl;
		cout << *(p++) << endl;
	}
}


void myPrint(int val)
{
	cout << val << " ";
}

//STL中的三大组件
void test02()
{

	//stl中的容器
	vector<int>v; //单端数组,数组中每个元素类型都是int

	//向容器中插入元素 尾插
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(70);

	//遍历容器  利用迭代器遍历
	// vector<int>容器迭代器如何写？

	vector<int>::iterator itBegin = v.begin(); //声明一个 v容器的 起始迭代器，指向第一个元素位置
	vector<int>::iterator itEnd = v.end(); //结束迭代器  指向 最后一个元素的下一个地址

	//第一种方式遍历
	/*while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}*/

	//第二种方式遍历  推荐
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}*/

	//第三种遍历方式 利用算法
	for_each(v.begin(), v.end(), myPrint);

}

//自定义数据类型
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

void test03()
{
	vector<Person>v;

	Person p1("德玛西亚", 10);
	Person p2("东皇太一", 13);
	Person p3("安琪拉", 14);
	Person p4("百里守约", 16);
	Person p5("凯", 14);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历
	//每个容器都有自己专属的迭代器
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	}

}

//存放对象指针
void test04()
{
	vector<Person *>v;

	Person p1("德玛西亚", 10);
	Person p2("东皇太一", 13);
	Person p3("安琪拉", 14);
	Person p4("百里守约", 16);
	Person p5("凯", 14);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person *>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "姓名： " << (*it)->m_Name << " 年龄： " << (*it)->m_Age << endl;
	}

}

//容器嵌套容器
void test05()
{
	vector< vector<int> > v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//遍历大容器
	for (vector<vector <int>>::iterator it = v.begin(); it != v.end();it++)
	{
		// *it是什么？vector <int>  容器
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end();vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}

}


int main(){
	//test01();
	test02();
	//test03();
	//test04();
	//test05();

	system("pause");
	return EXIT_SUCCESS;
}