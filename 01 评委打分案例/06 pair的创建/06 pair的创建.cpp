#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
void test01()
{
	//��һ�ִ�����ʽ
	pair<string, int> p("TOM", 18);

	cout << "������ " << p.first << " ���䣺 " << p.second << endl;


	//�ڶ��ִ�����ʽ
	pair<string, int> p2 = make_pair("Jerry", 19);
	cout << "������ " << p2.first << " ���䣺 " << p2.second << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}