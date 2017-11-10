#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>
#include <string>

/*
3.7.2.1 set���캯��
set<T> st;//setĬ�Ϲ��캯����
mulitset<T> mst; //multisetĬ�Ϲ��캯��:
set(const set &st);//�������캯��
3.7.2.2 set��ֵ����
set& operator=(const set &st);//���صȺŲ�����
swap(st);//����������������
3.7.2.3 set��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

3.7.2.4 set�����ɾ������
insert(elem);//�������в���Ԫ�ء�
clear();//�������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem);//ɾ��������ֵΪelem��Ԫ�ء�
*/

void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

void test01()
{
	set<int>s1;

	//������� �� insert
	s1.insert(10);
	s1.insert(6);
	s1.insert(3);
	s1.insert(1);
	s1.insert(7);
	//����ʽ���� �ڲ��Ѿ�������������򣬴�С����Ĭ��
	printSet(s1);
	
	s1.erase(6); //����ֱ��ɾ��6������ ����key������ɾ��

	printSet(s1);

	if (s1.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ�� ��С��" << s1.size() << endl;
	}
}

/*
3.7.2.5 set���Ҳ���
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key);//���Ҽ�key��Ԫ�ظ���  ����set���� ����޷��� 0 ���� 1
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
*/

void test02()
{
	set<int>s1;
	//������� �� insert
	s1.insert(10);
	s1.insert(6);
	s1.insert(3);
	s1.insert(1);
	s1.insert(7);


	//���������Ƿ���1���Ԫ��
	set<int>::iterator pos = s1.find(1);
	if ( pos != s1.end())
	{
		cout << "�ҵ��� " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}


	//��7�ĸ���
	int num  = s1.count(7);
	cout << "7�ĸ���Ϊ�� " << num << endl;


	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
	set<int>::iterator it = s1.lower_bound(3);
	if (it!=s1.end())
	{
		cout << "�ҵ���lower_bound��ֵΪ��  " << *it << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}


	//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	set<int>::iterator it2 = s1.upper_bound(3);
	if (it2 != s1.end())
	{
		cout << "�ҵ���upper_bound��ֵΪ��  " << *it2 << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

	pair<set<int>::iterator, set<int>::iterator > pair1 = s1.equal_range(3);

	//��ȡ��һ�������е�ֵ
	if (pair1.first != s1.end())
	{
		cout << "�ҵ���equal_range �� lower_bound��ֵΪ�� " << *(pair1.first) << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	if (pair1.second != s1.end())
	{
		cout << "�ҵ���equal_range �� upper_bound��ֵΪ�� " << *(pair1.second) << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
		
}


void test03()
{
	set<int>s1;
	//��һ������ 10
	pair<set<int>::iterator, bool>  pair1 = s1.insert(10);

	if (pair1.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}


	pair1 = s1.insert(10); //set����������ظ���keyֵ

	if (pair1.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}


	//printSet(s1);

	//����multiset���� �����Բ����ظ���keyֵ
	multiset<int>s2;
	s2.insert(10);
	s2.insert(10);

}

//���÷º���
class Mycompare
{
public:
	bool operator()( int v1 ,int v2)
	{
		return v1 > v2;
	}
};

void test04()
{

	set<int, Mycompare>s1;
	//�����ı���������ڲ�������ǰ ָ������

	//������� �� insert
	s1.insert(10);
	s1.insert(6);
	s1.insert(3);
	s1.insert(1);
	s1.insert(7);

	//�ڲ�������� Ĭ��  ��С����
	//�޸�������� �Ӵ�С

	for (set<int, Mycompare>::iterator it = s1.begin(); it != s1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


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

class MycomparePerson
{
public:
	bool operator()( const Person  &p1, const Person &p2 )
	{
		//����������������
		return p1.m_Age < p2.m_Age;
	}

};

void test05()
{
	//�����Զ����������ͣ�������ǰָ�����������
	set<Person, MycomparePerson>s1;

	Person p1("����", 10);
	Person p2("����", 20);
	Person p3("����", 40);
	Person p4("����", 30);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person, MycomparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺 " << it->m_Age << endl;
	}

}


int main(){

	//test01();

	//test02();

	//test03();

	//test04();
	
	test05();

	system("pause");
	return EXIT_SUCCESS;
}