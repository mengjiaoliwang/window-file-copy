#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <fstream> //对文件读写的头文件

//写文件
void test01()
{
	//参数1   向哪个位置写文件，参数2 打开文件的模式
	//ofstream ofs("./test.txt", ios::out | ios::trunc);

	ofstream ofs;
	//后制定打开方式
	ofs.open("./test.txt", ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	ofs << "姓名：孙悟空" << endl;
	ofs << "年龄：2000" << endl;
	ofs << "性别：中性" << endl;

	ofs.close();

}

//读文件
void test02()
{
	ifstream ifs;
	ifs.open("./test.txt", ios::in); //参数1  指定打开哪个文件  参数2  打开文件的模式

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	//读取文件内容 
	//方式1
	//char buf[1024] = { 0 };
	//while (ifs >> buf) //读取每行的内容
	//{
	//	cout << buf << endl;
	//}

	//方式2
	//char buf[1024];
	//while (!ifs.eof()) //如果没有读到文件尾 一直读
	//{
	//	ifs.getline(buf,sizeof(buf));
	//	cout << buf << endl;
	//}

	//方式3 
	//一个一个字符的读
	char c;
	while (  (c = ifs.get())  != EOF)   //如果没有读到文件尾，一个一个字符的读取
	{
		cout << c;
	}

	//关闭流对象
	ifs.close();


}




int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}