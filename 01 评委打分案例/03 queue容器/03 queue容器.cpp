#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>

/*
���� �Ƚ��ȳ����ݽṹ
3.5.3.1 queue���캯��
queue<T> queT;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ��
queue(const queue &que);//�������캯��
3.5.3.2 queue��ȡ�������ɾ������
push(elem);//����β���Ԫ��
pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
back();//�������һ��Ԫ��
front();//���ص�һ��Ԫ��

3.5.3.3 queue��ֵ����
queue& operator=(const queue &que);//���صȺŲ�����
3.5.3.4 queue��С����
empty();//�ж϶����Ƿ�Ϊ��
size();//���ض��еĴ�С

*/

void test01()
{
	queue<int>q;

	//���β���Ԫ��
	q.push(10);
	q.push(40);
	q.push(20);
	q.push(60);

	while (!q.empty())
	{
		cout << "��ͷԪ�أ� " << q.front() << endl;
		cout << "��βԪ�أ� " << q.back() << endl;

		//�Ƴ���ͷԪ��
		q.pop();
	}

	cout << "size  = " << q.size() << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}