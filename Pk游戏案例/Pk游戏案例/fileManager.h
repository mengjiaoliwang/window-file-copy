#pragma  once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
class FileManager
{

public:

	//加载CSV格式的函数

	void loadCSVData(string path, map<string,map<string,string>> &m );

	//解析单行数据 并且将解析后的内容 放入到容器中
	void parseLineToVector(string line, vector<string>&v);

};