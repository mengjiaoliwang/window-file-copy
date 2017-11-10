#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <deque>
#include <numeric>
#include <functional>
#include <ctime>
/*
需求分析：
1) 产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWX ） 姓名、得分；选手编号

2) 第1轮	选手抽签 选手比赛 查看比赛结果
3) 第2轮	选手抽签 选手比赛 查看比赛结果
4) 第3轮	选手抽签 选手比赛 查看比赛结果
*/

//选手类
class Speaker
{
public:
	string m_Name;  //姓名
	int m_Score[3]; //分数
};

void createSpeaker(vector<int>&v, map<int,Speaker>&m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";

	for (int i = 0; i < 24;i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 3;j++)
		{
			sp.m_Score[j] = 0;
		}

		v.push_back(100 + i); //存放编号

		m.insert(make_pair(100 + i, sp)); //存放编号以及对应的人员
	}

}


void speechDraw( vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}


void speechContest( int index, vector<int>&v, map<int,Speaker>&m, vector<int>&v2)
{
	multimap<int, int, greater<int>> groupScore; //临时容器 保存6个人 key 分数  value 代表编号   greater从大到小排序
	int num = 0;
	//遍历选手  进行打分
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		num++;
		deque<int>d;
		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60; // 60 ~100
			d.push_back(score);
		}
		//排序
		sort(d.begin(), d.end());
		//去除最高最低分
		d.pop_back(); //最高
		d.pop_front(); // 最低

		//总分
		int sum = accumulate(d.begin(), d.end(), 0);
		//平均分
		int avg = sum / d.size();

		//将平均分 放入到人身上
		m[*it].m_Score[index - 1] = avg;

		groupScore.insert(make_pair(avg, *it)); //临时容器 存放数据

		if (num % 6 == 0)
		{
			//每6个人 进入 以下代码块
			//取6个人的前三名 晋级
			/*	cout << "小组比赛成绩如下：" << endl;
				for (multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit != groupScore.end(); mit++)
				{
				cout << "编号： " << mit->second << " 姓名： " << m[mit->second].m_Name << " 分数： " << m[mit->second].m_Score[index - 1] << endl;;
				}*/

			//取前三 晋级
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit != groupScore.end(), count < 3; mit++, count++)
			{
				v2.push_back((*mit).second);
			}

			groupScore.clear();
		}
	}

}

//参数  1  轮数  参数2  晋级人员编号  参数3  所有人员信息
void showScore(int index, vector<int>&v, map<int,Speaker>&m)
{
	cout << "第" << index << "轮 比赛成绩如下：" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "选手编号： " << it->first << " 姓名： " << it->second.m_Name << " 分数： " << it->second.m_Score[index - 1] << endl;
	}

	//晋级人员
	cout << "晋级人员编号 " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << endl;
	}
}


int main(){

	srand((unsigned int)time(NULL));

	vector<int>vSpeaker; //存放选手编号

	map<int, Speaker> mSpeaker; //存放具体的人员以及编号

	//创建选手
	createSpeaker(vSpeaker,mSpeaker);

	//抽签
	speechDraw(vSpeaker);

	//晋级人员编号容器
	vector<int>v2;

	//比赛
	speechContest(1,vSpeaker, mSpeaker, v2);

	//查看比赛结果
	showScore( 1, v2, mSpeaker);


	//第二轮比赛

	//抽签
	speechDraw(v2);
	//第二轮晋级人员容器编号
	vector<int>v3;
	//比赛
	speechContest(2, v2, mSpeaker, v3);
	//查看比赛结果
	showScore(2, v3, mSpeaker);


	//第三轮比赛
	//抽签
	speechDraw(v3);
	//第三轮晋级人员容器编号
	vector<int>v4;
	//比赛
	speechContest(3, v3, mSpeaker, v4);
	//查看比赛结果
	showScore(3, v4, mSpeaker);


	////测试
	//for (map<int, Speaker>::iterator it = mSpeaker.begin(); it != mSpeaker.end(); it++)
	//{
	//	cout << "姓名： " << (*it).second.m_Name << " 编号： " << (*it).first << endl;
	//}

	system("pause");
	return EXIT_SUCCESS;
}