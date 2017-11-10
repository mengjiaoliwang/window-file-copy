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

//C++�ڼܹ�����ʱ��ϣ�����ÿ���ԭ��
//����ԭ�� ���޸Ľ��йر�   ����չ���п���
//���ö�̬д������

class BaseCalculator
{
public:
	//1 �����е�getResult���� �����ò���
	//���麯��
	//2 д�˴��麯�������м̳д��麯�����࣬��������д ���麯��
	//3 ���һ������������ ���麯���������Ҳ����ʵ����������
	//4 ���һ������ ���˴��麯�� ����ô�����ͳ�Ϊ ������

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



//�ӷ�������
class AddCalculator:public BaseCalculator
{
public:
	int getResult()
	{
		return m_a + m_b;
	}
};
//����������
class SubCalculator :public BaseCalculator
{
public:
	int getResult()
	{
		return m_a - m_b;
	}
};
//�˷�������
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

	//�������Ǽ���������
	calculator = new SubCalculator;
	calculator->m_a = 1;
	calculator->m_b = 1;
	cout << calculator->getResult() << endl;
	delete calculator;

}


//д�˴��麯�������м̳д��麯�����࣬��������д ���麯��
class A : public BaseCalculator
{
public:
	//int getResult(){ return 0; };  //�������д����ô������ʵ��������
};

void test03()
{
	//A a;
}

//���һ������������ ���麯���������Ҳ����ʵ����������
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