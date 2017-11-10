#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stdexcept> //ʹ��ϵͳ�ṩ�ı�׼�쳣ͷ�ļ�

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			//Խ�� �׳�һ��Խ���쳣
			throw out_of_range("����Խ���ˣ�");
		}

		this->m_Age = age;
	}
	int m_Age;
};


void test01()
{
	try
	{
		Person p1(1000);
	}
	catch ( out_of_range & e )// exception & e  = out_of_range("����Խ���ˣ�"); ������̬
	{
		cout << e.what() << endl; //��ӡ���������ʾ����
	}


}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}