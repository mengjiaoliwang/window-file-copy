#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cin.get() //һ��ֻ�ܶ�ȡһ���ַ�
cin.get(һ������) //��һ���ַ�
cin.get(��������) //���Զ��ַ���
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
void test01()
{

	// as  ��һ�����û������е�a���ڶ�����s���������û��� ���Ĵεȴ��´�����
	char c = cin.get();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

}

void test02()
{
	////��ȡһ���ַ���
	//char buf[1024];
	//cin.get(buf, 1024); 

	////����ڲ���������û�л��з�
	////cin.get()��ȡ�ַ���ʱ�򣬲��Ὣ���з����ߣ��������ڻ�����
	//char c = cin.get();
	//if (c == '\n')
	//{
	//	cout << "���з����ڻ�������" << endl;
	//}

	//cin.getline() ��ȡ�ַ���
	//��û�н��������ڻ����������ǽ����з� ������
	char buf2[1024];
	cin.getline(buf2, 1024);
	char c1 = cin.get();
	if (c1 == '\n')
	{
		cout << "���з����ڻ�������" << endl;
	}

}

void test03()
{
	//cin.ignore()  ���� û�в�����Ĭ�Ϻ���1���ַ�
	//cin.ignore(N)������N���ַ�
	// as  ���s
	cin.ignore(2);
	char c = cin.get();
	cout << "c :" << c << endl;
}

void test04()
{
	//cin.peek()  ͵��

	// as ���  a a
	char c = cin.peek();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

}

void test05()
{
	//cin.putback() �Ż�
	char c = cin.get();
	cin.putback(c);


	char buf[1024];
	cin.getline(buf, 1024);

	cout << buf << endl;

}

//��׼������С����
//�û��������ݣ��ж��û���������ַ� ��������
void test06()
{
	cout << "������һ�����ֻ����ַ�����" << endl;

	char c = cin.peek();
	if (c >= '0' && c<= '9')
	{
		cout << "�������������" << endl;
		int num;
		cin >> num;
		cout << "����Ϊ: " << num << endl;
	}
	else
	{
		cout << "����������ַ���" << endl;

		char buf[1024] = {0};
		cin >> buf;
		cout << "�ַ���Ϊ��" << buf << endl;
	}

}

//���û�����һ�����֣����ֱ����� 0 ~ 10֮������֣�������Ч����������
void test07()
{
	cout << "������һ�� 0 ~ 10 ֮������֣�" << endl;
	int num;


	while (true)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "������ȷ����������Ϊ" << num << endl;
			break;
		}
		cout << "������������������" << endl;

		

		//����־λ ����0
		cin.clear();
		cin.sync(); // ��ջ�����

		//cout << "fail  " << cin.fail() << endl; //��־λ 0 ����   1 �쳣
	}

}


int main(){

	
	//test01();
	
	//test02();

	//test03();
	
	//test04();

	//test05();

	//test06();

	test07();

	system("pause");
	return EXIT_SUCCESS;
}