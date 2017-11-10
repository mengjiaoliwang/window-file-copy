#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void swapInt(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapDouble(double &d1, double &d2)
{
	double temp = d1;
	d1 = d2;
	d2 = temp;
}

//利用模板的技术  实现通用函数
// 逻辑方面一致  ，只是参数类型不同， 参数类型 给 参数化
// 类型参数化， 泛型编程

template< typename T > //声明一个模板,告诉编译器，下面紧跟着的函数或者类中 出现了T，不要报错，这是个万能的类型
void mySwap(T & a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template< typename T >
void mySwap2()
{
	cout << "helloworld" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	//swapInt(a, b);

	//模板使用方式
	//1、自动类型推导,必须让编译器推导出T的类型，才可以使用
	char c1 = 'c';
	mySwap(a, b);

	//2、显示指定类型推导
	mySwap<int>(a, b);

	cout << "a  = " << a << endl;
	cout << "b  = " << b << endl;

	//必须让编译器推导出T的类型，才可以调用模板
	mySwap2<double>();


	double c = 1.1;
	double d = 3.14;
//	swapDouble(c, d);

	mySwap(c, d);

	cout << "c  = " << c << endl;
	cout << "d  = " << d << endl;


}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}