#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <fstream> //���ļ���д��ͷ�ļ�

//д�ļ�
void test01()
{
	//����1   ���ĸ�λ��д�ļ�������2 ���ļ���ģʽ
	//ofstream ofs("./test.txt", ios::out | ios::trunc);

	ofstream ofs;
	//���ƶ��򿪷�ʽ
	ofs.open("./test.txt", ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	ofs << "�����������" << endl;
	ofs << "���䣺2000" << endl;
	ofs << "�Ա�����" << endl;

	ofs.close();

}

//���ļ�
void test02()
{
	ifstream ifs;
	ifs.open("./test.txt", ios::in); //����1  ָ�����ĸ��ļ�  ����2  ���ļ���ģʽ

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	//��ȡ�ļ����� 
	//��ʽ1
	//char buf[1024] = { 0 };
	//while (ifs >> buf) //��ȡÿ�е�����
	//{
	//	cout << buf << endl;
	//}

	//��ʽ2
	//char buf[1024];
	//while (!ifs.eof()) //���û�ж����ļ�β һֱ��
	//{
	//	ifs.getline(buf,sizeof(buf));
	//	cout << buf << endl;
	//}

	//��ʽ3 
	//һ��һ���ַ��Ķ�
	char c;
	while (  (c = ifs.get())  != EOF)   //���û�ж����ļ�β��һ��һ���ַ��Ķ�ȡ
	{
		cout << c;
	}

	//�ر�������
	ifs.close();


}




int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}