#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <stdexcept>
/*
string ���캯��
string();//����һ���յ��ַ��� ����: string str;
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ��

3.1.2.2 string������ֵ����
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);//���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���

*/

void test01()
{
	string str1; //Ĭ�Ϲ���
	string str2 = str1; //��������
	string str3 = "abcdef"; //�вι���
	string str4(10, 'a');// 10���ַ�a
	cout << str3 << endl;
	cout << str4 << endl;

	string str5;
	str5.assign("abcde", 2);
	cout << str5 << endl;

	//string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ��� start��0��ʼ���Ǵ�1��ʼ���𰸴�0��ʼ
	string str6;
	str6.assign(str3, 3, 3);
	cout << str6 << endl;

}

/*
string��ȡ�ַ�����
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�
*/
void test02()
{
	string str = "helloworld";
	//for (int i = 0; i < str.size();i++)
	//{
	//	//cout << str[i] << endl;
	//	//cout << str.at(i) << endl;
	//}

	//at���ʺ� []�������� []����Խ��  ֱ�ӹҵ�  at����Խ�� ���׳��쳣 out_of_range

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
		cout << "�������쳣" << endl;
	}
}


/*
3.1.2.4 stringƴ�Ӳ���
string& operator+=(const string& str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������
string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string &s);//ͬoperator+=()
string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c

3.1.2.5 string���Һ��滻
int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

*/

void test03()
{
	string s1 = "��";
	string s2 = "������";
	s1 += s2;

	cout << s1 << endl;

	s1.append("�찲��");

	cout << s1 << endl;

	//find
	string str = "abcdefgbcd";
	int pos = str.find("bcd"); //����1  ���ҵ��ַ���  ����2 �ǲ��ҵ���ʼλ��
	cout << "pos = " << pos << endl; //����ҵ� ���ص�һ���ַ����±꣬����Ҳ���������-1

	pos = str.rfind("bcd"); //�����������
	cout << "pos = " << pos << endl;

	//replace �滻
	//�滻��pos��ʼn���ַ�Ϊ�ַ���str   "alllefgbcd";
	string strNew = str.replace(1, 3, "llll");
	cout << strNew << endl;

}

/*
3.1.2.6 string�Ƚϲ���
compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
��д��A��Сд��aС��
int compare(const string &s) const;//���ַ���s�Ƚ�
int compare(const char *s) const;//���ַ���s�Ƚ�
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
3.1.2.7 string�Ӵ�
string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���
*/
void test05()
{
	//string str = "abcdefg";

	//string subStr = str.substr(2, 4);
	//cout << subStr << endl;


	string email = "zhangtao@sina.com";
	//���������û����ַ���

	int pos = email.find("@"); // 8

	string usrName = email.substr(0, pos); //��0λ�ÿ�ʼ ��8���ַ�

	cout << "usrName:  " << usrName << endl;
}

/*
string�����ɾ������
string& insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ�
*/

void test06()
{
	//����
	string str1 = "abcdef";
	str1.insert(1, "ppp");
	// apppbcdef
	cout << str1 << endl;

	//ɾ�� 
	str1.erase(1, 3);
	cout << str1 << endl;
}


/*
3.1.2.9 string��c-style�ַ���ת��
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

	//doWork(str2); //û�гɹ�

	doWork2(str3); //char* ������ʽ����ת��Ϊ string������֮������

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

	//������·����ַ�ˣ���ôԭ�������ʧЧ���Ͳ�Ҫ���зǷ�������
	s = "pppppppppppppppppppppp";

	/*a = '3';
	b = '4';*/


	cout << s << endl;
	cout << (int*)s.c_str() << endl;


}

//дһ�������������ڲ���string�ַ����е�����Сд��ĸ����Ϊ��д��ĸ��
void test09()
{
	string str = "abcDeFg";

	for (int i = 0; i < str.size(); i++)
	{
		//str[i] = toupper(str[i]); // ת��д

		str[i] = tolower(str[i]); //תСд

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