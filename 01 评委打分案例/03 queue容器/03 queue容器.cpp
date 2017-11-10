#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>

/*
符合 先进先出数据结构
3.5.3.1 queue构造函数
queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
queue(const queue &que);//拷贝构造函数
3.5.3.2 queue存取、插入和删除操作
push(elem);//往队尾添加元素
pop();//从队头移除第一个元素
back();//返回最后一个元素
front();//返回第一个元素

3.5.3.3 queue赋值操作
queue& operator=(const queue &que);//重载等号操作符
3.5.3.4 queue大小操作
empty();//判断队列是否为空
size();//返回队列的大小

*/

void test01()
{
	queue<int>q;

	//向队尾添加元素
	q.push(10);
	q.push(40);
	q.push(20);
	q.push(60);

	while (!q.empty())
	{
		cout << "队头元素： " << q.front() << endl;
		cout << "队尾元素： " << q.back() << endl;

		//移除队头元素
		q.pop();
	}

	cout << "size  = " << q.size() << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}