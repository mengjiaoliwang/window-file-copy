#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include <functional> //ʹ���ڽ���������  ��ͷ�ļ�
#include <vector>
#include <algorithm>

//template<class T> T negate<T>//ȡ���º���  һԪ����
//template<class T> T plus<T>//�ӷ��º���  ��Ԫ����
void test01()
{
	negate<int>n;
	cout << n(1000) << endl;

	plus<int>p;
	cout << p(1, 1) << endl;
}

// template<class T> bool greater<T>//����
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
	cout << endl;

	//�Ӵ�С����
	sort(v.begin(), v.end(), greater<int>());

	for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
	cout << endl;

}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}