#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>
/*
list������ ˫��ѭ������
*/

void test01()
{
	list<int> myList;
	for (int i = 0; i < 10; i++){
		myList.push_back(i);
	}
	//node��ͷ������һ���ڵ�
	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++){
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead){
			node = node->_Next;
		}
	}
}

/*
3.6.4.1 list���캯��
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����
3.6.4.2 list����Ԫ�ز����ɾ������
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�

*/

void printList( const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	list<int>list1;
	list<int>list2(10, 10);
	list2.push_back(100);

	////�������
	//for (list<int>::iterator it = list2.begin(); it != list2.end();it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	////�������
	//for (list<int>::reverse_iterator it = list2.rbegin(); it != list2.rend();it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	
	list<int>list3;
	list3.push_back(10);
	list3.push_back(20);
	list3.push_back(30);
	list3.push_front(100);
	list3.push_front(200);
	list3.push_front(300);
	// 300 200 100 10 20 30
	printList(list3);

	list3.pop_back();
	list3.pop_front();
	//  200 100 10 20 
	printList(list3);


	list3.insert(list3.begin(), 1000);
	printList(list3);

	list3.erase(list3.begin());
	printList(list3);

	list3.push_back(100);
	//  200 100 10 20 100 
	list3.remove(100);
	//  200  10 20  
	printList(list3);

}

/*
3.6.4.3 list��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(num);//����ָ�������ĳ���Ϊnum��
�������䳤������Ĭ��ֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(num, elem);//����ָ�������ĳ���Ϊnum��
�������䳤������elemֵ�����λ�á�
���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

3.6.4.4 list��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
list& operator=(const list &lst);//���صȺŲ�����
swap(lst);//��lst�뱾���Ԫ�ػ�����
3.6.4.5 list���ݵĴ�ȡ
front();//���ص�һ��Ԫ�ء�
back();//�������һ��Ԫ�ء�
*/

void test03()
{
	list<int>list1;
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_front(100);
	list1.push_front(200);
	list1.push_front(300);

	if (list1.empty())
	{
		cout << "list1Ϊ��" << endl;
	}
	else
	{
		cout << "list1��Ϊ��  ��СΪ��" << list1.size() << endl;
	}

	list<int>list2(10, 100);

	list1.swap(list2);

	printList(list1);
	printList(list2);

	cout << "front " << list2.front() << " back " << list2.back() << endl;

}


/*
list��ת����
reverse();//��ת��������lst����1,3,5Ԫ�أ����д˷�����lst�Ͱ���5,3,1Ԫ�ء�
sort(); //list����
*/

bool myCompare(int v1, int v2)
{
	return v1 > v2;
}

void test04()
{
	list<int>list1;
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_front(100);
	list1.push_front(200);
	list1.push_front(300);

	// 300 200 100 10 20 30
	printList(list1);
	list1.reverse();

	printList(list1);

	//ʹ�õ�sort�㷨��ȫ�ֺ��� ϵͳ�ṩ�ģ������ϵͳ�ṩ���㷨�������ĵ���������֧���������
	//sort(list1.begin(), list1.end());
	
	/*list<int>::iterator it = list1.begin();
	it = it + 1;*/

	//����ǲ�֧��������ʵĵ������������������ڲ����ṩ��Ա����
	list1.sort();
	printList(list1);

	//�Ӵ�С
	list1.sort(myCompare);
	printList(list1);

}

//�Զ�����������
class Person
{
public:
	Person(string name, int age, int height) :m_Name(name), m_Age(age), m_Height(height)
	{
	}

	//���� == ��remove֪������쳣 Person����

	bool operator==(const Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name; //����
	int m_Age; //����
	int m_Height; //���
};

bool myComparePerson(const Person & p1, const Person &p2)
{
	//���������������� ����������  ������߽�������
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}

	return p1.m_Age < p2.m_Age;
}

void test05()
{
	list<Person>list1;
	Person p1("����", 20 , 170);
	Person p2("����", 18, 168);
	Person p3("����", 16, 166);
	Person p4("����", 16 , 190);
	Person p5("����", 16 , 120);
	Person p6("�߾�", 888, 1111);
	Person p7("үү��", 998, 200);

	list1.push_back(p1);
	list1.push_back(p2);
	list1.push_back(p3);
	list1.push_back(p4);
	list1.push_back(p5);
	list1.push_back(p6);
	list1.push_back(p7);

	//��ӡ���
	//for (list<Person>::iterator it = list1.begin(); it != list1.end();it++)
	//{
	//	cout <<  "������ " << (*it).m_Name << " ���䣺 " << it->m_Age << endl;
	//}

	list1.sort(myComparePerson);
	//�����Զ����������ͣ�����Ҫָ���������

	cout << "����� " << endl;
	for (list<Person>::iterator it = list1.begin(); it != list1.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺 " << it->m_Age <<  " ��ߣ� "<< it->m_Height << endl;
	}


	//�Ƴ��߾�
	list1.remove(p6);
	cout << "�Ƴ���Ľ�� -------------------------------" << endl;
	for (list<Person>::iterator it = list1.begin(); it != list1.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺 " << it->m_Age << " ��ߣ� " << it->m_Height << endl;
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