#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <stdexcept>
/*
string 构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化

3.1.2.2 string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串

*/

void test01()
{
	string str1; //默认构造
	string str2 = str1; //拷贝构造
	string str3 = "abcdef"; //有参构造
	string str4(10, 'a');// 10个字符a
	cout << str3 << endl;
	cout << str4 << endl;

	string str5;
	str5.assign("abcde", 2);
	cout << str5 << endl;

	//string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串 start从0开始还是从1开始？答案从0开始
	string str6;
	str6.assign(str3, 3, 3);
	cout << str6 << endl;

}

/*
string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/
void test02()
{
	string str = "helloworld";
	//for (int i = 0; i < str.size();i++)
	//{
	//	//cout << str[i] << endl;
	//	//cout << str.at(i) << endl;
	//}

	//at访问和 []访问区别？ []访问越界  直接挂掉  at访问越界 会抛出异常 out_of_range

	try
	{
		//cout << str[100] << endl;
		cout << str.at(100) << endl;
	}
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "捕获到了异常" << endl;
	}
}


/*
3.1.2.4 string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

3.1.2.5 string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

*/

void test03()
{
	string s1 = "我";
	string s2 = "爱北京";
	s1 += s2;

	cout << s1 << endl;

	s1.append("天安门");

	cout << s1 << endl;

	//find
	string str = "abcdefgbcd";
	int pos = str.find("bcd"); //参数1  查找的字符串  参数2 是查找的起始位置
	cout << "pos = " << pos << endl; //如果找到 返回第一个字符才下标，如果找不到，返回-1

	pos = str.rfind("bcd"); //从右往左查找
	cout << "pos = " << pos << endl;

	//replace 替换
	//替换从pos开始n个字符为字符串str   "alllefgbcd";
	string strNew = str.replace(1, 3, "llll");
	cout << strNew << endl;

}

/*
3.1.2.6 string比较操作
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
*/

void test04()
{
	string str1 = "bbc";
	string str2 = "bzc";

	if (str1.compare(str2) == 0)
	{
		cout << "str1 == str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}

}


/*
3.1.2.7 string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/
void test05()
{
	//string str = "abcdefg";

	//string subStr = str.substr(2, 4);
	//cout << subStr << endl;


	string email = "zhangtao@sina.com";
	//求出邮箱的用户名字符串

	int pos = email.find("@"); // 8

	string usrName = email.substr(0, pos); //从0位置开始 找8个字符

	cout << "usrName:  " << usrName << endl;
}

/*
string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/

void test06()
{
	//插入
	string str1 = "abcdef";
	str1.insert(1, "ppp");
	// apppbcdef
	cout << str1 << endl;

	//删除 
	str1.erase(1, 3);
	cout << str1 << endl;
}


/*
3.1.2.9 string和c-style字符串转换
*/

void doWork(char * str)
{}

void doWork2(string str)
{}

void test07()
{
	//c-style ->string
	const char * str = "helloworld";
	string str1(str);

	// string -> c-style
	string str2 = "aaaa";

	const char * str3 = str2.c_str();

	//doWork(str2); //没有成功

	doWork2(str3); //char* 可以隐式类型转换为 string，而反之不可以

}

void test08()
{
	string s = "abcdefg";
	char& a = s[2];
	char& b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	//如果重新分配地址了，那么原理的引用失效，就不要进行非法操作了
	s = "pppppppppppppppppppppp";

	/*a = '3';
	b = '4';*/


	cout << s << endl;
	cout << (int*)s.c_str() << endl;


}

//写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
void test09()
{
	string str = "abcDeFg";

	for (int i = 0; i < str.size(); i++)
	{
		//str[i] = toupper(str[i]); // 转大写

		str[i] = tolower(str[i]); //转小写

	}

	cout << str << endl;

}


int main(){
	//test01();

	//test02();

	//test03();

	//test04();

	//test05();

	//test06();

	//test08();

	test09();

	system("pause");
	return EXIT_SUCCESS;
}