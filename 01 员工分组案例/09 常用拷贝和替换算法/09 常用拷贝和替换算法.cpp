#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <iterator>
/*
copy算法 将容器内指定范围的元素拷贝到另一容器中
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param dest 目标起始迭代器
*/
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10;i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.resize(v1.size());
	//将v1容器内容拷贝到v2容器中

	copy(v1.begin(), v1.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int v){ cout << v << " "; });

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));

}

/*
replace算法 将容器内指定范围的旧元素修改为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param oldvalue 旧元素
@param oldvalue 新元素
*/
class MyReplace
{
public:
	bool operator()(int val)
	{
		return val > 3;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//将 容器中 的3 数据 替换 3000

	replace(v.begin(), v.end(), 3, 3000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//按条件替换 
	//把所有大于3的数字 都替换成 30000
	replace_if(v.begin(), v.end(), MyReplace(), 30000);

	// 0 1 2 3000 4 5 6 7 8 9 
	// 0 1 2 30000 30000...

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}


/*
swap算法 互换两个容器的元素
@param c1容器1
@param c2容器2
*/

void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	vector<int>v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);

	//交换
	swap(v, v2);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}




int main(){

	//test01();

	//test02();

	test03();
	system("pause");
	return EXIT_SUCCESS;
}