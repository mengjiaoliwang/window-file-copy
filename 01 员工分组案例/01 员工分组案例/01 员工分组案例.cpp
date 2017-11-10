#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <ctime>
/*
//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
//ͨ��Multimap������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ
*/

enum 
{
	CAIWU,
	RENLI,
	YANFA
};

class Worker
{
public:
	string m_Name; // ����
	int m_Money; //����
};


void createWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		Worker worker;

		string name = "Ա��";
		name += nameSeed[i];

		worker.m_Name = name;

		worker.m_Money = rand() % 10000 + 10000; // 10000 ~ 19999
		
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
	{
		//�������ű��
		int Id = rand() % 3; // 0 1 2

		//��Ա�����뵽 multimap������
		m.insert(make_pair(Id, *it));
	}

}

void showGroup(multimap<int,Worker>&m)
{
	cout << "������Ա����Ϣ���£�" << endl;
	// 0 A    0 B    0  C   1 D   2 E
	multimap<int,Worker>::iterator pos = m.find(CAIWU);
	int num = 0;
	int count = m.count(CAIWU);
	for (; pos != m.end(), num < count; pos++, num++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Money << endl;
	}

	cout << "��������Ա����Ϣ���£�" << endl;
	pos = m.find(RENLI);
	num = 0;
	count = m.count(RENLI);
	for (; pos != m.end(), num < count; pos++, num++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Money << endl;
	}

	cout << "�з�����Ա����Ϣ���£�" << endl;
	pos = m.find(YANFA);
	num = 0;
	count = m.count(YANFA);
	for (; pos != m.end(), num < count; pos++, num++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Money << endl;
	}

}

int main(){

	//���������
	srand((unsigned int)time(NULL));

	vector<Worker>v;
	//1����������Ա�������뵽������
	createWorker(v);

	//2��Ա������
	multimap<int, Worker> m; //��Ų��ű���Լ��������Ա
	setGroup(v,m);

	//3���ֲ�����ʾԱ����Ϣ
	showGroup(m);


	//����
	/*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << " ������ " << (*it).m_Name << " ���ʣ� " << it->m_Money << endl;
	}*/

	system("pause");
	return EXIT_SUCCESS;
}