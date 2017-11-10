#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>

/*
3.8.2.1 map���캯��
map<T1, T2> mapTT;//mapĬ�Ϲ��캯��:
map(const map &mp);//�������캯��


3.8.2.2 map��ֵ����
map& operator=(const map &mp);//���صȺŲ�����
swap(mp);//����������������

3.8.2.3 map��С����
size();//����������Ԫ�ص���Ŀ
empty();//�ж������Ƿ�Ϊ��

*/

void test01()
{
	map<int, int> m;

	//��������
	//��һ�ַ�ʽ����
	m.insert(pair<int, int>(1, 10));

	//�ڶ��ַ�ʽ����  �Ƽ�
	m.insert(make_pair(2, 20));

	//�����ַ�ʽ���� ֵ����
	m.insert(map<int, int>::value_type(3, 30));

	//�����ַ�ʽ����  ���Ƽ�
	//[]��ʽ ��������ȡֵ��������֤key��Ч�������ʹ��[]��ʽ
	m[4] = 40;

	for (map<int, int>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "key = " << it->first << " value = " << (*it).second << endl;
	}

	//m[5]; //���key�����ڣ�������������keyΪ5 valueΪ0 ��ֵ���뵽������

	/*for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << (*it).second << endl;
	}*/


	if (m.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ�� ��С�� " << m.size()<< endl;
	}
}


/*
3.8.2.5 mapɾ������
clear();//ɾ������Ԫ��
erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg,end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(keyElem);//ɾ��������keyΪkeyElem�Ķ��顣
3.8.2.6 map���Ҳ���
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
*/

void test02()
{
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	//ɾ�� 
	//m.erase(3); //����keyֵ
	//for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	cout << "key = " << it->first << " value = " << (*it).second << endl;
	//}

	//����
	map<int,int>::iterator pos = m.find(3);
	if (pos !=m.end())
	{
		cout << "�ҵ��� key = " << pos->first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//ͳ�Ƹ��� 
	int num = m.count(2);
	cout << "keyΪ2�ĸ����� " << num << endl;


	//lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������

	map<int,int>::iterator it =  m.lower_bound(3);
	if (it!=m.end())
	{
		cout << "�ҵ�lower_bound��ֵ key�� " << it->first << " value: " << it->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
	it = m.upper_bound(3);
	if (it != m.end())
	{
		cout << "�ҵ�upper_bound��ֵ key�� " << it->first << " value: " << it->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

	//equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

	pair<map<int,int>::iterator, map<int,int>::iterator > pair1 =m.equal_range(3);

	if (pair1.first != m.end())
	{
		cout << "�ҵ�equal_range �е� lower_bound��ֵ key�� " << pair1.first->first  << " value: " <<  pair1.first->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	
	if (pair1.second != m.end())
	{
		cout << "�ҵ�equal_range �е� upper_bound��ֵ key�� " << pair1.second->first << " value: " << pair1.second->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}

}

class MyCompare
{
public:
	bool operator()(int v1,int v2) //int v1 v2ָ����key
	{
		return v1 > v2;
	}
};

//���� 
void test03()
{
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(2, 20));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << (*it).second << endl;
	}

}


int main(){
	//test01();
	//test02();

	test03();
	system("pause");
	return EXIT_SUCCESS;
}