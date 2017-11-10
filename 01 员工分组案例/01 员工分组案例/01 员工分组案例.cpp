#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <ctime>
/*
//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过Multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
*/

enum 
{
	CAIWU,
	RENLI,
	YANFA
};

class Worker
{
public:
	string m_Name; // 姓名
	int m_Money; //工资
};


void createWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5;i++)
	{
		Worker worker;

		string name = "员工";
		name += nameSeed[i];

		worker.m_Name = name;

		worker.m_Money = rand() % 10000 + 10000; // 10000 ~ 19999
		
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
	{
		//产生部门编号
		int Id = rand() % 3; // 0 1 2

		//将员工放入到 multimap容器中
		m.insert(make_pair(Id, *it));
	}

}

void showGroup(multimap<int,Worker>&m)
{
	cout << "财务部门员工信息如下：" << endl;
	// 0 A    0 B    0  C   1 D   2 E
	multimap<int,Worker>::iterator pos = m.find(CAIWU);
	int num = 0;
	int count = m.count(CAIWU);
	for (; pos != m.end(), num < count; pos++, num++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}

	cout << "人力部门员工信息如下：" << endl;
	pos = m.find(RENLI);
	num = 0;
	count = m.count(RENLI);
	for (; pos != m.end(), num < count; pos++, num++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}

	cout << "研发部门员工信息如下：" << endl;
	pos = m.find(YANFA);
	num = 0;
	count = m.count(YANFA);
	for (; pos != m.end(), num < count; pos++, num++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
	}

}

int main(){

	//随机数种子
	srand((unsigned int)time(NULL));

	vector<Worker>v;
	//1、创建五名员工，放入到容器中
	createWorker(v);

	//2、员工分组
	multimap<int, Worker> m; //存放部门编号以及具体的人员
	setGroup(v,m);

	//3、分部门显示员工信息
	showGroup(m);


	//测试
	/*for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << " 姓名： " << (*it).m_Name << " 工资： " << it->m_Money << endl;
	}*/

	system("pause");
	return EXIT_SUCCESS;
}