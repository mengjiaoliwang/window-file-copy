#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、内部重载了（）运算符，使用时像函数的调用，不是一个函数 而是一个类

class MyPrint
{
public:
	void operator()(int val) //一元仿函数
	{
		cout << val << endl;
		count++;
	}
	int count = 0;
};

void test01()
{
	MyPrint myPrint;
	myPrint(10);
}

//2、函数对象超出普通函数的概念，内部可以拥有自己的状态
void test02()
{
	MyPrint myPrint;
	myPrint(10);
	myPrint(10);
	myPrint(10);
	myPrint(10);
	myPrint(10);

	cout <<"调用次数为："<<  myPrint.count << endl;
}

//3、函数对象可以作为参数进行传递
void doWork( MyPrint print, int val)
{
	print(val);
}
void test03()
{
	doWork(MyPrint(), 10000);


}


int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}