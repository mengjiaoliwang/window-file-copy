#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <functional>

/*

�����㷨 ��������Ԫ��
@param beg ��ʼ������
@param end ����������
@param _callback  �����ص����ߺ�������
@return ��������
for_each(iterator beg, iterator end, _callback);
*/
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
		num++;
	}
	int num = 0;
};

void MyPrint01(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint());

	cout << endl;

	for_each(v.begin(), v.end(), MyPrint01);

	cout << endl;
}

//for_each�з���ֵ
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	MyPrint print = for_each(v.begin(), v.end(), MyPrint());
	cout << "���õ�num = " << print.num << endl;
}


class MyPrint3:public binary_function<int ,int ,void>
{
public:
	void operator()(int val , int start) const
	{
		cout << val + start << endl;
	}

};

//���԰󶨲����������
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), bind2nd(MyPrint3(), 1000));
}


/*
transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
ע�� : transform �����Ŀ�����������ڴ棬������Ҫ������ǰ������ڴ�
@param beg1 Դ������ʼ������
@param end1 Դ��������������
@param beg2 Ŀ��������ʼ������
@param _cakkback �ص��������ߺ�������
@return ����Ŀ������������
*/
class MyTransform
{
public:
	int operator()(int val)
	{
		return val + 1000;
	}
};
void test04()
{
	vector<int>v; //Դ����
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//Ŀ������
	vector<int>vTarget;
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), MyTransform());

	for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });

}

class MyTransform2
{
public:
	int operator()(int val ,int val2)
	{
		return val + val2;
	}

};

void test05()
{
	//�������������ݷ��뵽һ��������

	vector<int>v1; //Դ����
	vector<int>v2; //Դ����2
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i); // 0 ~ 9
		v2.push_back(i); // 0 ~ 9
	}

	vector<int>vTarget;
	vTarget.resize(v1.size());

	transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), MyTransform2());

	for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });


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