#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1���ڲ������ˣ����������ʹ��ʱ�����ĵ��ã�����һ������ ����һ����

class MyPrint
{
public:
	void operator()(int val) //һԪ�º���
	{
		cout << val << endl;
		count++;
	}
	int count = 0;
};

void test01()
{
	MyPrint myPrint;
	myPrint(10);
}

//2���������󳬳���ͨ�����ĸ���ڲ�����ӵ���Լ���״̬
void test02()
{
	MyPrint myPrint;
	myPrint(10);
	myPrint(10);
	myPrint(10);
	myPrint(10);
	myPrint(10);

	cout <<"���ô���Ϊ��"<<  myPrint.count << endl;
}

//3���������������Ϊ�������д���
void doWork( MyPrint print, int val)
{
	print(val);
}
void test03()
{
	doWork(MyPrint(), 10000);


}


int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}