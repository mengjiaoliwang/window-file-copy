#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class Calculator
//{
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_a + m_b;
//		}
//		else if (oper == "-")
//		{
//			return m_a - m_b;
//		}
//		else if (oper == "*")
//		{
//			return m_a  * m_b;
//		}
//		
//	}
//
//public:
//	int m_a;
//	int m_b;
//};
//
//void test01()
//{
//	Calculator cal;
//	cal.m_a = 10;
//	cal.m_b = 20;
//
//	cout << cal.getResult("+") << endl;
//	cout << cal.getResult("-") << endl;
//	cout << cal.getResult("*") << endl;
//
//}

//C++在架构创建时候，希望利用开闭原则
//开闭原则： 对修改进行关闭   对扩展进行开放
//利用多态写计算器

class BaseCalculator
{
public:
	//1 基类中的getResult方法 根本用不到
	//纯虚函数
	//2 写了纯虚函数后，所有继承纯虚函数的类，都必须重写 纯虚函数
	//3 如果一个类中了有了 纯虚函数，这个类也不能实例化对象了
	//4 如果一个类中 有了纯虚函数 ，那么这个类就称为 抽象类

	//virtual int getResult()
	//{
	//	return 0;
	//}

	virtual int getResult() = 0;
	//{
	//	return 0;
	//}

	int m_a;
	int m_b;

};



//加法计算器
class AddCalculator:public BaseCalculator
{
public:
	int getResult()
	{
		return m_a + m_b;
	}
};
//减法计算器
class SubCalculator :public BaseCalculator
{
public:
	int getResult()
	{
		return m_a - m_b;
	}
};
//乘法计算器
class MulCalculator :public BaseCalculator
{
public:
	int getResult()
	{
		return m_a * m_b;
	}
};



void test02()
{
	BaseCalculator * calculator;
	calculator = new AddCalculator;
	calculator->m_a = 1;
	calculator->m_b = 1;
	cout << calculator->getResult() << endl;
	delete calculator;

	//创建的是减法计算器
	calculator = new SubCalculator;
	calculator->m_a = 1;
	calculator->m_b = 1;
	cout << calculator->getResult() << endl;
	delete calculator;

}


//写了纯虚函数后，所有继承纯虚函数的类，都必须重写 纯虚函数
class A : public BaseCalculator
{
public:
	//int getResult(){ return 0; };  //如果不重写，那么不允许实例化对象
};

void test03()
{
	//A a;
}

//如果一个类中了有了 纯虚函数，这个类也不能实例化对象了
void test04()
{
	//BaseCalculator b1;
}

int main(){

	//test01();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}