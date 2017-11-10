#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <iomanip>

/*
cout.put() //向缓冲区写字符
cout.write() //从buffer中写num个字节到当前输出流中。
*/

void test01()
{
	//cout.put('a').put('b').put('c');

	char buf[1024] = "hello world";
	cout.write(buf, strlen(buf));

//	cout << "hellow" << endl;
}


//使用流对象的成员函数
void test02()
{
	int number = 99;
	cout.width(20); // 预留位置
	cout.fill('*'); //填充符号
	cout.setf(ios::left); //设置格式 为左对齐
	cout.unsetf(ios::dec); //卸载十进制
	cout.setf(ios::hex);  //安装十六进制
	cout.setf(ios::showbase); //显示基数
	cout.unsetf(ios::hex);  //卸载十六进制
	cout.setf(ios::oct);  //安装八进制
	cout << number << endl;
}

//使用控制符 包含头文件iomanip
void test03()
{
	int number = 99;
	cout << setw(20)
		 << setfill('~')  //设置填充
		 << setiosflags(ios::showbase)  //设置基数
		<< setiosflags(ios::left) //左对齐
		<< hex  //安装16进制
		<< number
		<< endl;
}

int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}