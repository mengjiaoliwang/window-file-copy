#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
//#include <algorithm>
//#include <functional>

#include <numeric> //С���㷨ͷ�ļ�
#include <iterator>
/*
accumulate�㷨 ��������Ԫ���ۼ��ܺ�
@param beg ������ʼ������
@param end ��������������
@param value�ۼ�ֵ
*/

void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100;i++)
	{
		v.push_back(i);
	}

	int sum = accumulate(v.begin(), v.end(), 1000); //����3  ��ʼ��ֵ
	cout << "sum = " << sum << endl;

}


/*
fill�㷨 �����������Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value t���Ԫ��
*/

void test02()
{
	vector<int>v;
	v.resize(10,100);

	fill(v.begin(), v.end(), 200);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}


int main(){
	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}