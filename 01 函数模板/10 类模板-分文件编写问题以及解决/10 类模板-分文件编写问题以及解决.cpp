#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "Person.hpp"


//类模板通常不会做分文件编写，原因 一般不会包含.cpp源文件
//解决方案，将类模板的声明和实现都写到同一个文件中，将文件后缀名改为 .hpp 约定俗成的一个后缀名

int main(){

	Person <string, int >p1("五火球教主", 100);
	p1.showPerson();


	system("pause");
	return EXIT_SUCCESS;
}