#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "Person.hpp"


//��ģ��ͨ�����������ļ���д��ԭ�� һ�㲻�����.cppԴ�ļ�
//�������������ģ���������ʵ�ֶ�д��ͬһ���ļ��У����ļ���׺����Ϊ .hpp Լ���׳ɵ�һ����׺��

int main(){

	Person <string, int >p1("��������", 100);
	p1.showPerson();


	system("pause");
	return EXIT_SUCCESS;
}