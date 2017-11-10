/*
	createby zt 
	2017/8/5
	createPerson( vector<Person>&v) //创建五名选手的功能
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name; //姓名
	int m_Score; //分数
};

void createPerson(vector<Person>&v )
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5;i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0; //默认0分
		Person p(name, score);

		v.push_back(p);
	}

}

void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{
		//将10个分数 存放 deque容器
		deque<int>d;
		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60; //  60 ~ 100
			d.push_back(score); //将分数存放到 容器中
		}

		//排序前 查看每个评委的打分
		/*for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/

		//排序 从小到大
		sort(d.begin(), d.end());

		//去除最高分和最低分
		d.pop_back(); //最高分
		d.pop_front(); //最低分

		int sum = 0; //总分
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//获取平均分
		int avg = sum / d.size();

		//把分数设置到人身上
		it->m_Score = avg;
	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "姓名： " << (*it).m_Name << " 平均分： " << it->m_Score << endl;
	}
}

int main(){

	srand((unsigned int)time(NULL)); //设置随机数种子

	vector<Person> v; //存放五名选手的容器

	createPerson(v); //1 创建五名选手

	setScore(v); //2 打分

	showScore(v); //3 显示平均分

	////测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 分数： " <<(*it).m_Score << endl;
	//}

	system("pause");
	return EXIT_SUCCESS;
}