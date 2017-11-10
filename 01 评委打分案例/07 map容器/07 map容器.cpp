#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>

/*
3.8.2.1 map构造函数
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数


3.8.2.2 map赋值操作
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器

3.8.2.3 map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

*/

void test01()
{
	map<int, int> m;

	//插入数据
	//第一种方式插入
	m.insert(pair<int, int>(1, 10));

	//第二种方式插入  推荐
	m.insert(make_pair(2, 20));

	//第三种方式插入 值类型
	m.insert(map<int, int>::value_type(3, 30));

	//第四种方式插入  不推荐
	//[]方式 用来进行取值操作，保证key有效情况下再使用[]方式
	m[4] = 40;

	for (map<int, int>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "key = " << it->first << " value = " << (*it).second << endl;
	}

	//m[5]; //如果key不存在，会给容器中添加key为5 value为0 的值放入到容器中

	/*for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << (*it).second << endl;
	}*/


	if (m.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空 大小： " << m.size()<< endl;
	}
}


/*
3.8.2.5 map删除操作
clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);//删除容器中key为keyElem的对组。
3.8.2.6 map查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

void test02()
{
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	//删除 
	//m.erase(3); //按照key值
	//for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	cout << "key = " << it->first << " value = " << (*it).second << endl;
	//}

	//查找
	map<int,int>::iterator pos = m.find(3);
	if (pos !=m.end())
	{
		cout << "找到了 key = " << pos->first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//统计个数 
	int num = m.count(2);
	cout << "key为2的个数： " << num << endl;


	//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。

	map<int,int>::iterator it =  m.lower_bound(3);
	if (it!=m.end())
	{
		cout << "找到lower_bound的值 key： " << it->first << " value: " << it->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
	it = m.upper_bound(3);
	if (it != m.end())
	{
		cout << "找到upper_bound的值 key： " << it->first << " value: " << it->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

	pair<map<int,int>::iterator, map<int,int>::iterator > pair1 =m.equal_range(3);

	if (pair1.first != m.end())
	{
		cout << "找到equal_range 中的 lower_bound的值 key： " << pair1.first->first  << " value: " <<  pair1.first->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	
	if (pair1.second != m.end())
	{
		cout << "找到equal_range 中的 upper_bound的值 key： " << pair1.second->first << " value: " << pair1.second->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

}

class MyCompare
{
public:
	bool operator()(int v1,int v2) //int v1 v2指的是key
	{
		return v1 > v2;
	}
};

//排序 
void test03()
{
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(2, 20));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << (*it).second << endl;
	}

}


int main(){
	//test01();
	//test02();

	test03();
	system("pause");
	return EXIT_SUCCESS;
}