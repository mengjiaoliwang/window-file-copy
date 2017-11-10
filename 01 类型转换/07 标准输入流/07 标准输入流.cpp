#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
void test01()
{

	// as  第一次是拿缓冲区中的a，第二次拿s，第三次拿换行 第四次等待下次输入
	char c = cin.get();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

}

void test02()
{
	////获取一个字符串
	//char buf[1024];
	//cin.get(buf, 1024); 

	////检测内部缓冲区有没有换行符
	////cin.get()获取字符串时候，不会将换行符拿走，而是留在缓冲区
	//char c = cin.get();
	//if (c == '\n')
	//{
	//	cout << "换行符留在缓冲区了" << endl;
	//}

	//cin.getline() 获取字符串
	//并没有将换行留在缓冲区，而是将换行符 拿走了
	char buf2[1024];
	cin.getline(buf2, 1024);
	char c1 = cin.get();
	if (c1 == '\n')
	{
		cout << "换行符留在缓冲区了" << endl;
	}

}

void test03()
{
	//cin.ignore()  忽略 没有参数，默认忽略1个字符
	//cin.ignore(N)，忽略N个字符
	// as  输出s
	cin.ignore(2);
	char c = cin.get();
	cout << "c :" << c << endl;
}

void test04()
{
	//cin.peek()  偷窥

	// as 输出  a a
	char c = cin.peek();
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;

}

void test05()
{
	//cin.putback() 放回
	char c = cin.get();
	cin.putback(c);


	char buf[1024];
	cin.getline(buf, 1024);

	cout << buf << endl;

}

//标准输入流小案例
//用户输入内容，判断用户输入的是字符 还是数字
void test06()
{
	cout << "请输入一个数字或者字符串：" << endl;

	char c = cin.peek();
	if (c >= '0' && c<= '9')
	{
		cout << "您输入的是数字" << endl;
		int num;
		cin >> num;
		cout << "数字为: " << num << endl;
	}
	else
	{
		cout << "您输入的是字符串" << endl;

		char buf[1024] = {0};
		cin >> buf;
		cout << "字符串为：" << buf << endl;
	}

}

//让用户输入一个数字，数字必须是 0 ~ 10之间的数字，否则无效，重新输入
void test07()
{
	cout << "请输入一个 0 ~ 10 之间的数字：" << endl;
	int num;


	while (true)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "输入正确：输入内容为" << num << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;

		

		//将标志位 重置0
		cin.clear();
		cin.sync(); // 清空缓冲区

		//cout << "fail  " << cin.fail() << endl; //标志位 0 正常   1 异常
	}

}


int main(){

	
	//test01();
	
	//test02();

	//test03();
	
	//test04();

	//test05();

	//test06();

	test07();

	system("pause");
	return EXIT_SUCCESS;
}