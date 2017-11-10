#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
/*
merge算法 容器元素合并，并存储到另一容器中
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器

注意： 要合并有序的序列  而且顺序一致
*/
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int>vTarget; //目标容器
	vTarget.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(), [](int v){ cout << v << " "; });
}


/*
sort算法 容器元素排序
注意:两个容器必须是有序的
@param beg 容器1开始迭代器
@param end 容器1结束迭代器
@param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	//从大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int v){ cout << v << " "; });
}

/*
random_shuffle算法 对指定范围内的元素随机调整次序
@param beg 容器开始迭代器
@param end 容器结束迭代器
洗牌
*/
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), [](int v){ cout << v << " "; });
}


/*
reverse算法 反转指定范围的元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
*/

void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(3); // 0~9 3

	//反转
	reverse(v.begin(), v.end());

	for_each(v.begin(), v.end(), [](int v){ cout << v << " "; });
}

int main(){

	srand((unsigned int)time(NULL));

	//test01();

	//test02();

	//test03();

	test04();

	system("pause");
	return EXIT_SUCCESS;
}