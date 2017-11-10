#include "fileManager.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

void FileManager::parseLineToVector(string firstLine, vector<string>&v)
{
	//根据,进行分割数据
	int pos = -1;
	int start = 0;
	while (true)
	{
		// heroId,heroName,heroAtk,heroInfo
		pos = firstLine.find(",", start);

		if (pos == -1) //退出条件
		{
			//退出条件前 拿走最后一个数据
			string tmpStr = firstLine.substr(start, firstLine.size() - start);
			v.push_back(tmpStr);
			break;
		}

		string tmpStr = firstLine.substr(start, pos - start);

		v.push_back(tmpStr); //将截取出的字符串  放入到容器中
		start = pos + 1;
	}

}

//加载CSV文件
void FileManager::loadCSVData(string path, map<string, map<string, string>> &fileDataMap)
{
	ifstream ifs(path);

	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}

	string firstLine;
	ifs >> firstLine;

	//cout << firstLine << endl;

	//vector容器  存放第一行的所有字段
	vector<string> v;


	//解析单行数据封装
	parseLineToVector(firstLine, v);


	//for_each(v.begin(), v.end(), [](string str){ cout << str << endl; });


	//解析所有数据 并且放到 大map容器中 
	//最大map容器结构  map<string ,  map<string,string>> m
	//声明大map表
	//map<string, map<string, string>> fileDataMap;

	string data;
	while (ifs >> data)
	{
		//cout << data << endl;

		vector<string>dataV; //临时容器  存放解析后的结果

		parseLineToVector(data, dataV);
		//for_each(dataV.begin(), dataV.end(), [](string str){ cout << str << endl; });
		map<string, string> dataM; //小map表

		for (int i = 0; i < dataV.size();i++)
		{
			dataM.insert(make_pair(v[i], dataV[i]));
		}
		
		//将小map表 放入到大map表中
		fileDataMap.insert(make_pair(dataV[0], dataM));
	}
	

	//cout << fileDataMap["1"]["heroName"] << endl;
	//cout << fileDataMap["1"]["heroAtk"] << endl;
	//cout << fileDataMap["1"]["heroDef"] << endl;
	//cout << fileDataMap["2"]["heroName"] << endl;
	//cout << fileDataMap["3"]["heroName"] << endl;

	

}


