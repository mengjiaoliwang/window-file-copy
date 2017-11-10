#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

class GreaterThen40
{
public:
	bool operator()(int val)
	{
		return val > 40;
	}
};

//一元谓词
void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	//寻找第一个大于40的数据
	//利用find_if 做条件查找
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen40());
	if ( pos != v.end())
	{
		cout << "找到大于40的数字 " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


}


class MyCompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};

bool myCompare2(int v1, int v2)
{
	return v1 > v2;
}

void myPrint2(int v)
{
	cout << v << " ";
}

//二元谓词
void test02()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	//从大到小排序
	sort(v.begin(), v.end(), MyCompare()); //利用仿函数 
	//sort(v.begin(), v.end(), myCompare2); //利用回调函数

	//打印 Lambda表达式   匿名函数
	//for_each(v.begin(), v.end(), [](int v1){ cout << v1 << " "; });
	for_each(v.begin(), v.end(), myPrint2);

}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}