#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}

//区别： 普通函数可以进行隐式类型转换，模板函数如果自动类型推导，不可以做隐式类型转换
void test01()
{
	int a = 1;
	int b = 2;
	char c = 'c'; // 99 
	// 如果是自动类型推导 ，函数模板是不会做隐式类型转换的
	//cout << myPlus(a, c) << endl;

	//如果是普通函数，可以做隐式类型转换
	cout << myPlus2(a, c) << endl;

}


/////////////////////////////////////////////// 调用规则 /////////////////////////////////////////////
template<class T>
void myPrint(T a, T b)
{
	cout << "函数模板的调用" << endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "函数模板的调用 a b c" << endl;
}

//函数模板通过具体类型产生不同的函数
//通过模板 产生的函数 就叫 模板函数
//void myPrint(int a, int b, int c)
//{
//	cout << "函数模板的调用 a b c" << endl;
//}
//void myPrint(double a, double b, double c)
//{
//	cout << "函数模板的调用 a b c" << endl;
//}



void myPrint(int a, int b)
{
	cout << "普通函数的调用" << endl;
}

void test02()
{
	int a = 10;
	int b = 20;
	//myPrint(a, b);
	//1、如果普通函数和函数模板都可以匹配调用，优先使用普通函数的调用

	//2、如果想强制调用函数模板，用空模板参数列表可以调用
	myPrint<>(a, b);

	int c = 30;
	//3、函数模板，也可以发生重载
	myPrint(a, b, c);


	//4、如果函数模板可以产生更好的匹配，那么优先选择函数模板调用
	char c1 = 'c';
	char d1 = 'd';
	myPrint(c1, d1);
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}