#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

//1����������������
class myPrint : public binary_function<int,int,void>
{
public:
	void operator()(int val,int start) const
	{	
		cout <<  "val = "<< val <<  " start = " << start << " sum = "<< val + start << endl;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	int num;
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd( myPrint(), num) ); //�Ƽ�
	//for_each(v.begin(), v.end(), bind1st(myPrint(), num));
}

//������ʹ��
//��һ�� ��  bind2nd
//�ڶ��� �̳� �������� �̳� binary_function<��������1����������2������ֵ����>
//������ ��const



class GreaterThenFive :public unary_function<int,bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};
//2��ȡ��������
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//��һ������5������
	//ȡ�������� һԪȡ��
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterThenFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(),  not1(bind2nd(greater<int>(),5))  );

	if (pos != v.end())
	{
		cout << "�ҵ�С��5�����֣�" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}


	//��Ԫȡ�� �Ӵ�С
	sort(v.begin(), v.end(), not2(less<int>()));

	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
}


void myPrint3(int val ,int start)
{
	cout << val + start << endl;
}
//3������ָ��������
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//��ͨ����ָ�� ����ɺ������� ���� ptr_fun
	for_each(v.begin(), v.end(),  bind2nd( ptr_fun( myPrint3) , 100));
}

//4����Ա����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << " ��Ա�����е� ������ " << m_Name << " ���䣺 " << m_Age << endl;
	}

	void addAge()
	{
		this->m_Age++;
	}

	string m_Name; //����
	int m_Age;//����
};

//void myPrintPerson( Person &p)
//{
//	cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;;
//}

void test04()
{
	vector<Person>v;
	Person p1("aaaa", 10);
	Person p2("bbbb", 20);
	Person p3("cccc", 30);
	Person p4("dddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//���� mem_fun_ref
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}



int main(){

	//test01();
	//test02();
	
	//test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}