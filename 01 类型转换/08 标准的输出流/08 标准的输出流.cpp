#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <iomanip>

/*
cout.put() //�򻺳���д�ַ�
cout.write() //��buffer��дnum���ֽڵ���ǰ������С�
*/

void test01()
{
	//cout.put('a').put('b').put('c');

	char buf[1024] = "hello world";
	cout.write(buf, strlen(buf));

//	cout << "hellow" << endl;
}


//ʹ��������ĳ�Ա����
void test02()
{
	int number = 99;
	cout.width(20); // Ԥ��λ��
	cout.fill('*'); //������
	cout.setf(ios::left); //���ø�ʽ Ϊ�����
	cout.unsetf(ios::dec); //ж��ʮ����
	cout.setf(ios::hex);  //��װʮ������
	cout.setf(ios::showbase); //��ʾ����
	cout.unsetf(ios::hex);  //ж��ʮ������
	cout.setf(ios::oct);  //��װ�˽���
	cout << number << endl;
}

//ʹ�ÿ��Ʒ� ����ͷ�ļ�iomanip
void test03()
{
	int number = 99;
	cout << setw(20)
		 << setfill('~')  //�������
		 << setiosflags(ios::showbase)  //���û���
		<< setiosflags(ios::left) //�����
		<< hex  //��װ16����
		<< number
		<< endl;
}

int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}