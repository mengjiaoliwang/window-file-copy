#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
void test01()
{
	//第一种创建方式
	pair<string, int> p("TOM", 18);

	cout << "姓名： " << p.first << " 年龄： " << p.second << endl;


	//第二种创建方式
	pair<string, int> p2 = make_pair("Jerry", 19);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}