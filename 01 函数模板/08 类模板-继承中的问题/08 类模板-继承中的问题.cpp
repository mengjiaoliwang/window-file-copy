#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class Base
{
public:
	Base(){}
	Base(T tmp)
	{
		this->m_Arg = tmp;
	}
	T m_Arg;
};

template<class T1, class T2>
class Son :public Base<T2>
{
public:
	T1 m_other;
};

//��ģ���� �̳е�������� ����̳�ʱ��Ҫָ���������е�T�������಻֪������������ڴ�
//�﷨  class Son :public Base<T2>
void test01()
{
	Son <int,double> s1;
}


int main(){



	system("pause");
	return EXIT_SUCCESS;
}