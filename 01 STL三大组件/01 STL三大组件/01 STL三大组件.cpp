#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector> //vector������
#include <algorithm> //�㷨ͷ�ļ�
#include <string>

//ԭ��ָ�� Ҳ�������
//��������Ҫ ���б��� ����
void test01()
{
	int array[5] = { 1, 4, 7, 3, 0 };
	int * p = array; // ָ��pָ�� �����׵�ַ  &array[0]
	for (int i = 0; i < 5;i++)
	{
		//cout << array[i] << endl;
		cout << *(p++) << endl;
	}
}


void myPrint(int val)
{
	cout << val << " ";
}

//STL�е��������
void test02()
{

	//stl�е�����
	vector<int>v; //��������,������ÿ��Ԫ�����Ͷ���int

	//�������в���Ԫ�� β��
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(70);

	//��������  ���õ���������
	// vector<int>�������������д��

	vector<int>::iterator itBegin = v.begin(); //����һ�� v������ ��ʼ��������ָ���һ��Ԫ��λ��
	vector<int>::iterator itEnd = v.end(); //����������  ָ�� ���һ��Ԫ�ص���һ����ַ

	//��һ�ַ�ʽ����
	/*while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}*/

	//�ڶ��ַ�ʽ����  �Ƽ�
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}*/

	//�����ֱ�����ʽ �����㷨
	for_each(v.begin(), v.end(), myPrint);

}

//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test03()
{
	vector<Person>v;

	Person p1("��������", 10);
	Person p2("����̫һ", 13);
	Person p3("������", 14);
	Person p4("������Լ", 16);
	Person p5("��", 14);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//����
	//ÿ�����������Լ�ר���ĵ�����
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺 " << it->m_Age << endl;
	}

}

//��Ŷ���ָ��
void test04()
{
	vector<Person *>v;

	Person p1("��������", 10);
	Person p2("����̫һ", 13);
	Person p3("������", 14);
	Person p4("������Լ", 16);
	Person p5("��", 14);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person *>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "������ " << (*it)->m_Name << " ���䣺 " << (*it)->m_Age << endl;
	}

}

//����Ƕ������
void test05()
{
	vector< vector<int> > v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5;i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//����������
	for (vector<vector <int>>::iterator it = v.begin(); it != v.end();it++)
	{
		// *it��ʲô��vector <int>  ����
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end();vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}

}


int main(){
	//test01();
	test02();
	//test03();
	//test04();
	//test05();

	system("pause");
	return EXIT_SUCCESS;
}