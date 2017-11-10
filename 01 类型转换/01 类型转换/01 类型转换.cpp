#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、静态类型转换

class Base{};
class Son :public Base{};
class Other{};

void test01()
{

	//静态类型转换基本语法：  static_cast<目标类型>(原对象、变量)
	//基础数据类型转换
	char c = 'a';
	double d = static_cast<double>(c);
	cout << d << endl;


	//父子之间的转换
	Base * base = NULL;
	Son * son = NULL;

	//base 转Son类型  不安全  向下类型转换
	Son * son1 = static_cast<Son*>(base);

	//son 转为 Base类型   安全  向上类型转换
	Base * base1 = static_cast<Base*>(son);


	//父子类引用转换
	Base base2;
	Son son2;

	Base &base_ref = base2;

	Son& son_ref = static_cast<Son&>(base_ref);


	//转其他类型
	//base 转为 Other  //转换无效
	//Other * other = static_cast<Other*>(base);

}


//2、动态类型转换
class Base2
{
	virtual void func();
};
class Son2 :public Base2
{
	virtual void func();
};
class Other2{};
void test02()
{
	//基础数据类型 不允许转换
	//char c = 'a';
	//double d = dynamic_cast<double>(c);
	//cout << d << endl;

	Base2 * base = NULL;
	Son2 * son = NULL;

	//son 转为 Base2*  安全 
	Base2 * base2 = dynamic_cast<Base2*>(son);

	//base 转为 Son2* 不安全  向下
	//但是如果有多态 ，那么是安全的
	Son2* son2 = dynamic_cast<Son2*>(base);
}


//常量转换
void test03()
{
	//移除const
	const int * p = NULL;
	int *p1 = const_cast<int*>(p);

	//加上const
	int * pp = NULL;
	const int * pp1 = const_cast<const int*>(pp);

	//只能对指针或者引用 加const或者 移除const
	/*const int a = 10;
	int b = const_cast<int>(a);*/

}

//重新解释转换
void test04()
{
	int a = 10;
	int * p = reinterpret_cast<int*>(a);


	Base * base = NULL;
	//最不推荐使用的转换
	Other * other = reinterpret_cast<Other*>(base);
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}