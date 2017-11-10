#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <iterator>
/*
copy�㷨 ��������ָ����Χ��Ԫ�ؿ�������һ������
@param beg ������ʼ������
@param end ��������������
@param dest Ŀ����ʼ������
*/
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10;i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.resize(v1.size());
	//��v1�������ݿ�����v2������

	copy(v1.begin(), v1.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int v){ cout << v << " "; });

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));

}

/*
replace�㷨 ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
@param beg ������ʼ������
@param end ��������������
@param oldvalue ��Ԫ��
@param oldvalue ��Ԫ��
*/
class MyReplace
{
public:
	bool operator()(int val)
	{
		return val > 3;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//�� ������ ��3 ���� �滻 3000

	replace(v.begin(), v.end(), 3, 3000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//�������滻 
	//�����д���3������ ���滻�� 30000
	replace_if(v.begin(), v.end(), MyReplace(), 30000);

	// 0 1 2 3000 4 5 6 7 8 9 
	// 0 1 2 30000 30000...

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}


/*
swap�㷨 ��������������Ԫ��
@param c1����1
@param c2����2
*/

void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	vector<int>v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);

	//����
	swap(v, v2);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}




int main(){

	//test01();

	//test02();

	test03();
	system("pause");
	return EXIT_SUCCESS;
}