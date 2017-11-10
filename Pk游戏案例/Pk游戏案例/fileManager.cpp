#include "fileManager.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

void FileManager::parseLineToVector(string firstLine, vector<string>&v)
{
	//����,���зָ�����
	int pos = -1;
	int start = 0;
	while (true)
	{
		// heroId,heroName,heroAtk,heroInfo
		pos = firstLine.find(",", start);

		if (pos == -1) //�˳�����
		{
			//�˳�����ǰ �������һ������
			string tmpStr = firstLine.substr(start, firstLine.size() - start);
			v.push_back(tmpStr);
			break;
		}

		string tmpStr = firstLine.substr(start, pos - start);

		v.push_back(tmpStr); //����ȡ�����ַ���  ���뵽������
		start = pos + 1;
	}

}

//����CSV�ļ�
void FileManager::loadCSVData(string path, map<string, map<string, string>> &fileDataMap)
{
	ifstream ifs(path);

	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	string firstLine;
	ifs >> firstLine;

	//cout << firstLine << endl;

	//vector����  ��ŵ�һ�е������ֶ�
	vector<string> v;


	//�����������ݷ�װ
	parseLineToVector(firstLine, v);


	//for_each(v.begin(), v.end(), [](string str){ cout << str << endl; });


	//������������ ���ҷŵ� ��map������ 
	//���map�����ṹ  map<string ,  map<string,string>> m
	//������map��
	//map<string, map<string, string>> fileDataMap;

	string data;
	while (ifs >> data)
	{
		//cout << data << endl;

		vector<string>dataV; //��ʱ����  ��Ž�����Ľ��

		parseLineToVector(data, dataV);
		//for_each(dataV.begin(), dataV.end(), [](string str){ cout << str << endl; });
		map<string, string> dataM; //Сmap��

		for (int i = 0; i < dataV.size();i++)
		{
			dataM.insert(make_pair(v[i], dataV[i]));
		}
		
		//��Сmap�� ���뵽��map����
		fileDataMap.insert(make_pair(dataV[0], dataM));
	}
	

	//cout << fileDataMap["1"]["heroName"] << endl;
	//cout << fileDataMap["1"]["heroAtk"] << endl;
	//cout << fileDataMap["1"]["heroDef"] << endl;
	//cout << fileDataMap["2"]["heroName"] << endl;
	//cout << fileDataMap["3"]["heroName"] << endl;

	

}


