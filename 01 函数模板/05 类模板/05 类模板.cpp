#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

// 2 ����ģ���е� ���� ������Ĭ��ֵ
template<class NameType ,class AgeType = int >
class Person
{
public:

	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
	}

	NameType m_Name; //����
	AgeType m_Age; //����
};

void test01()
{
	//1�� ��ģ��  �����Խ��� �Զ�����ת������ʽ����ת����
	//������ʾָ������
	Person<string > p1("MT", 10);

	p1.showPerson();

}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}