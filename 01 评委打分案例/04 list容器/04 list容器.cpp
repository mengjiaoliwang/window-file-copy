#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>
/*
list容器是 双向循环链表
*/

void test01()
{
	list<int> myList;
	for (int i = 0; i < 10; i++){
		myList.push_back(i);
	}
	//node是头结点的下一个节点
	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++){
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead){
			node = node->_Next;
		}
	}
}

/*
3.6.4.1 list构造函数
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。
3.6.4.2 list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。

*/

void printList( const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int>list1;
	list<int>list2(10, 10);
	list2.push_back(100);

	////正序遍历
	//for (list<int>::iterator it = list2.begin(); it != list2.end();it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	////逆序遍历
	//for (list<int>::reverse_iterator it = list2.rbegin(); it != list2.rend();it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	
	list<int>list3;
	list3.push_back(10);
	list3.push_back(20);
	list3.push_back(30);
	list3.push_front(100);
	list3.push_front(200);
	list3.push_front(300);
	// 300 200 100 10 20 30
	printList(list3);

	list3.pop_back();
	list3.pop_front();
	//  200 100 10 20 
	printList(list3);


	list3.insert(list3.begin(), 1000);
	printList(list3);

	list3.erase(list3.begin());
	printList(list3);

	list3.push_back(100);
	//  200 100 10 20 100 
	list3.remove(100);
	//  200  10 20  
	printList(list3);

}

/*
3.6.4.3 list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

3.6.4.4 list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。
3.6.4.5 list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。
*/

void test03()
{
	list<int>list1;
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_front(100);
	list1.push_front(200);
	list1.push_front(300);

	if (list1.empty())
	{
		cout << "list1为空" << endl;
	}
	else
	{
		cout << "list1不为空  大小为：" << list1.size() << endl;
	}

	list<int>list2(10, 100);

	list1.swap(list2);

	printList(list1);
	printList(list2);

	cout << "front " << list2.front() << " back " << list2.back() << endl;

}


/*
list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}

void test04()
{
	list<int>list1;
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_front(100);
	list1.push_front(200);
	list1.push_front(300);

	// 300 200 100 10 20 30
	printList(list1);
	list1.reverse();

	printList(list1);

	//使用的sort算法是全局函数 系统提供的，如果用系统提供的算法，容器的迭代器必须支持随机访问
	//sort(list1.begin(), list1.end());
	
	/*list<int>::iterator it = list1.begin();
	it = it + 1;*/

	//如果是不支持随机访问的迭代器的容器，容器内部会提供成员函数
	list1.sort();
	printList(list1);

	//从大到小
	list1.sort(myCompare);
	printList(list1);

}

//自定义数据类型
class Person
{
public:
	Person(string name, int age, int height) :m_Name(name), m_Age(age), m_Height(height)
	{
	}

	//重载 == 让remove知道如果异常 Person对象

	bool operator==(const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name; //姓名
	int m_Age; //年龄
	int m_Height; //身高
};

bool myComparePerson(const Person & p1, const Person &p2)
{
	//按照年龄升序排序 如果年龄相等  按照身高降序排序
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}

	return p1.m_Age < p2.m_Age;
}

void test05()
{
	list<Person>list1;
	Person p1("大娃", 20 , 170);
	Person p2("二娃", 18, 168);
	Person p3("三娃", 16, 166);
	Person p4("四娃", 16 , 190);
	Person p5("五娃", 16 , 120);
	Person p6("蛇精", 888, 1111);
	Person p7("爷爷精", 998, 200);

	list1.push_back(p1);
	list1.push_back(p2);
	list1.push_back(p3);
	list1.push_back(p4);
	list1.push_back(p5);
	list1.push_back(p6);
	list1.push_back(p7);

	//打印输出
	//for (list<Person>::iterator it = list1.begin(); it != list1.end();it++)
	//{
	//	cout <<  "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	//}

	list1.sort(myComparePerson);
	//对于自定义数据类型，必须要指定排序规则

	cout << "排序后 " << endl;
	for (list<Person>::iterator it = list1.begin(); it != list1.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age <<  " 身高： "<< it->m_Height << endl;
	}


	//移除蛇精
	list1.remove(p6);
	cout << "移除后的结果 -------------------------------" << endl;
	for (list<Person>::iterator it = list1.begin(); it != list1.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height << endl;
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