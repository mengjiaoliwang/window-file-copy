#pragma  once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
class FileManager
{

public:

	//����CSV��ʽ�ĺ���

	void loadCSVData(string path, map<string,map<string,string>> &m );

	//������������ ���ҽ������������ ���뵽������
	void parseLineToVector(string line, vector<string>&v);

};