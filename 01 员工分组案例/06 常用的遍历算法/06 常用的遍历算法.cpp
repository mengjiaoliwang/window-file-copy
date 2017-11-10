#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>

/*

遍历算法 遍历容器元素
@param beg 开始迭代器
@param end 结束迭代器
@param _callback  函数回调或者函数对象
@return 函数对象
for_each(iterator beg, iterator end, _callback);
*/
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
		num++;
	}
	int num = 0;
};

void MyPrint01(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint());

	cout << endl;

	for_each(v.begin(), v.end(), MyPrint01);

	cout << endl;
}

//for_each有返回值
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	MyPrint print = for_each(v.begin(), v.end(), MyPrint());
	cout << "调用的num = " << print.num << endl;
}


class MyPrint3:public binary_function<int ,int ,void>
{
public:
	void operator()(int val , int start) const
	{
		cout << val + start << endl;
	}

};

//可以绑定参数进行输出
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), bind2nd(MyPrint3(), 1000));
}


/*
transform算法 将指定容器区间元素搬运到另一容器中
注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
@param beg1 源容器开始迭代器
@param end1 源容器结束迭代器
@param beg2 目标容器开始迭代器
@param _cakkback 回调函数或者函数对象
@return 返回目标容器迭代器
*/
class MyTransform
{
public:
	int operator()(int val)
	{
		return val + 1000;
	}
};
void test04()
{
	vector<int>v; //源容器
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//目标容器
	vector<int>vTarget;
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), MyTransform());

	for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });

}

class MyTransform2
{
public:
	int operator()(int val ,int val2)
	{
		return val + val2;
	}

};

void test05()
{
	//将两个容器内容放入到一个容器中

	vector<int>v1; //源容器
	vector<int>v2; //源容器2
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i); // 0 ~ 9
		v2.push_back(i); // 0 ~ 9
	}

	vector<int>vTarget;
	vTarget.resize(v1.size());

	transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), MyTransform2());

	for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });


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