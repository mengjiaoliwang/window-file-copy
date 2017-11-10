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
���������
1) ����ѡ�� �� ABCDEFGHIJKLMNOPQRSTUVWX �� �������÷֣�ѡ�ֱ��

2) ��1��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
3) ��2��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
4) ��3��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
*/

//ѡ����
class Speaker
{
public:
	string m_Name;  //����
	int m_Score[3]; //����
};

void createSpeaker(vector<int>&v, map<int,Speaker>&m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";

	for (int i = 0; i < 24;i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 3;j++)
		{
			sp.m_Score[j] = 0;
		}

		v.push_back(100 + i); //��ű��

		m.insert(make_pair(100 + i, sp)); //��ű���Լ���Ӧ����Ա
	}

}


void speechDraw( vector<int>&v)
{
	random_shuffle(v.begin(), v.end());
}


void speechContest( int index, vector<int>&v, map<int,Speaker>&m, vector<int>&v2)
{
	multimap<int, int, greater<int>> groupScore; //��ʱ���� ����6���� key ����  value ������   greater�Ӵ�С����
	int num = 0;
	//����ѡ��  ���д��
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		num++;
		deque<int>d;
		for (int i = 0; i < 10;i++)
		{
			int score = rand() % 41 + 60; // 60 ~100
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		//ȥ�������ͷ�
		d.pop_back(); //���
		d.pop_front(); // ���

		//�ܷ�
		int sum = accumulate(d.begin(), d.end(), 0);
		//ƽ����
		int avg = sum / d.size();

		//��ƽ���� ���뵽������
		m[*it].m_Score[index - 1] = avg;

		groupScore.insert(make_pair(avg, *it)); //��ʱ���� �������

		if (num % 6 == 0)
		{
			//ÿ6���� ���� ���´����
			//ȡ6���˵�ǰ���� ����
			/*	cout << "С������ɼ����£�" << endl;
				for (multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit != groupScore.end(); mit++)
				{
				cout << "��ţ� " << mit->second << " ������ " << m[mit->second].m_Name << " ������ " << m[mit->second].m_Score[index - 1] << endl;;
				}*/

			//ȡǰ�� ����
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit != groupScore.end(), count < 3; mit++, count++)
			{
				v2.push_back((*mit).second);
			}

			groupScore.clear();
		}
	}

}

//����  1  ����  ����2  ������Ա���  ����3  ������Ա��Ϣ
void showScore(int index, vector<int>&v, map<int,Speaker>&m)
{
	cout << "��" << index << "�� �����ɼ����£�" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "ѡ�ֱ�ţ� " << it->first << " ������ " << it->second.m_Name << " ������ " << it->second.m_Score[index - 1] << endl;
	}

	//������Ա
	cout << "������Ա��� " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << endl;
	}
}


int main(){

	srand((unsigned int)time(NULL));

	vector<int>vSpeaker; //���ѡ�ֱ��

	map<int, Speaker> mSpeaker; //��ž������Ա�Լ����

	//����ѡ��
	createSpeaker(vSpeaker,mSpeaker);

	//��ǩ
	speechDraw(vSpeaker);

	//������Ա�������
	vector<int>v2;

	//����
	speechContest(1,vSpeaker, mSpeaker, v2);

	//�鿴�������
	showScore( 1, v2, mSpeaker);


	//�ڶ��ֱ���

	//��ǩ
	speechDraw(v2);
	//�ڶ��ֽ�����Ա�������
	vector<int>v3;
	//����
	speechContest(2, v2, mSpeaker, v3);
	//�鿴�������
	showScore(2, v3, mSpeaker);


	//�����ֱ���
	//��ǩ
	speechDraw(v3);
	//�����ֽ�����Ա�������
	vector<int>v4;
	//����
	speechContest(3, v3, mSpeaker, v4);
	//�鿴�������
	showScore(3, v4, mSpeaker);


	////����
	//for (map<int, Speaker>::iterator it = mSpeaker.begin(); it != mSpeaker.end(); it++)
	//{
	//	cout << "������ " << (*it).second.m_Name << " ��ţ� " << (*it).first << endl;
	//}

	system("pause");
	return EXIT_SUCCESS;
}