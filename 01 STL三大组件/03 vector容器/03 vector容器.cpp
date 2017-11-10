#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <list>


void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++){
		v.push_back(i);
		cout << v.capacity() << endl;  // v.capacity()容器的容量
	}
	//不是以2倍的大小进行扩展
}


/*
3.2.4.1 vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

//例子 使用第二个构造函数 我们可以...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。

3.2.4.3 vector大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	int array[] = { 2, 5, 8, 9, 1 };
	vector <int>v1(array, array + sizeof(array) / sizeof(int));
	printVector(v1);

	vector<int>v2(v1.begin(), v1.end());
	//printVector(v2);

	vector<int>v3 = v2; //拷贝构造

	vector<int>v4(10, 100);
	printVector(v4);

	//swap交换
	cout << "v1和 v4交换后：" << endl;

	v1.swap(v4);
	printVector(v1);
	printVector(v4);


	cout << "v4容器的大小：" << v4.size() << endl;
	//判断容器是否为空
	if (v4.empty())
	{
		cout << "v4容器为空" << endl;
	}
	else
	{
		cout << "v4容器不为空" << endl;
	}

	//resize重新指定大小  v4    2, 5, 8, 9, 1，默认用0 填充
	v4.resize(10,10000); //参数2 可以修改默认填充值

	printVector(v4);

	v4.resize(3);

	printVector(v4);

}


// 巧用swap收缩内存
void test03()
{
	vector<int>v;
	for (int i = 0; i < 100000;i++)
	{
		v.push_back(i);
	}

	cout << "容量： " << v.capacity() << endl;
	cout << "大小： " << v.size() << endl;

	v.resize(3);
	cout << "容量： " << v.capacity() << endl;
	cout << "大小： " << v.size() << endl;


	vector<int>(v).swap(v);
	cout << "容量： " << v.capacity() << endl;
	cout << "大小： " << v.size() << endl;

}

//巧用reserve预留空间
//reverse 反转
void test04()
{
	vector<int>v;

	//如果已经知道数据的量级，可以先预留出地址
	v.reserve(100000);

	int * p = NULL;
	int num = 0;
	for (int i = 0; i < 100000;i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	// 记录找了开辟了多少次 新的空间
	cout << "num = " << num << endl;
}

/*
3.2.4.4 vector数据存取操作
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素

3.2.4.5 vector插入和删除操作
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素

*/
void test05()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	cout << "v.front = " << v.front() << endl; //第一个元素
	cout << "v.back = " << v.back() << endl;//最后一个元素

	//insert插入
	v.insert(v.begin(), 100); //第一个参数是迭代器 而不是int类型
	v.insert(v.begin(), 2,1000);

	printVector(v);

	//尾删
	v.pop_back();
	printVector(v);

	//删除  参数也是迭代器
	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end());  //清空第一个方法
	v.clear();  //清空第二种方法
	printVector(v);
}

/*
	逆序遍历
*/
void test06()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//reverse_iterator 反转迭代器
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend();it++)
	{
		cout << *it << endl;
	}

	//如果判断一个迭代器是否支持随机访问

	vector<int>::iterator itBegin = v.begin();
	itBegin = itBegin + 1; //如果可以写成+ 跳跃式访问，那么这个容器的迭代器是随机访问的迭代器

	//list容器迭代器是不支持随机访问的
	/*list<int>L;
	list<int>::iterator Lit = L.begin();
	Lit = Lit + 1;*/

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