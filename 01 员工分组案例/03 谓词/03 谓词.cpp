#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

class GreaterThen40
{
public:
	bool operator()(int val)
	{
		return val > 40;
	}
};

//һԪν��
void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	//Ѱ�ҵ�һ������40������
	//����find_if ����������
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen40());
	if ( pos != v.end())
	{
		cout << "�ҵ�����40������ " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}


}


class MyCompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};

bool myCompare2(int v1, int v2)
{
	return v1 > v2;
}

void myPrint2(int v)
{
	cout << v << " ";
}

//��Ԫν��
void test02()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	//�Ӵ�С����
	sort(v.begin(), v.end(), MyCompare()); //���÷º��� 
	//sort(v.begin(), v.end(), myCompare2); //���ûص�����

	//��ӡ Lambda���ʽ   ��������
	//for_each(v.begin(), v.end(), [](int v1){ cout << v1 << " "; });
	for_each(v.begin(), v.end(), myPrint2);

}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}