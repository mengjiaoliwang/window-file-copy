#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stack>
/*
//����  �Ƚ����   ����ȳ�
3.4.3.1 stack���캯��
stack<T> stkT;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ��
stack(const stack &stk);//�������캯��
3.4.3.2 stack��ֵ����
stack& operator=(const stack &stk);//���صȺŲ�����
3.4.3.3 stack���ݴ�ȡ����
push(elem);//��ջ�����Ԫ��
pop();//��ջ���Ƴ���һ��Ԫ��
top();//����ջ��Ԫ��
3.4.3.4 stack��С����
empty();//�ж϶�ջ�Ƿ�Ϊ��
size();//���ض�ջ�Ĵ�С

*/

void test01()
{
	stack<int>s;

	//ѹջ ��ջ 
	s.push(10);
	s.push(40);
	s.push(20);
	s.push(60);

	while (s.size()> 0)
	{
		cout << "ջ��Ԫ�أ� " << s.top() << endl;

		//�Ƴ�ջ��Ԫ��
		s.pop();
	}
	cout << "size  = " << s.size() << endl;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}