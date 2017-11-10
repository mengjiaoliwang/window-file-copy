#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include <functional> //使用内建函数对象  的头文件
#include <vector>
#include <algorithm>

//template<class T> T negate<T>//取反仿函数  一元运算
//template<class T> T plus<T>//加法仿函数  二元运算
void test01()
{
	negate<int>n;
	cout << n(1000) << endl;

	plus<int>p;
	cout << p(1, 1) << endl;
}

// template<class T> bool greater<T>//大于
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
	cout << endl;

	//从大到小排序
	sort(v.begin(), v.end(), greater<int>());

	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
	cout << endl;

}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}