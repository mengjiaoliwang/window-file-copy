#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	//����virtual���Ϊ �麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}

	virtual void eat(int a)
	{
		cout << "�����ڳԷ�" << endl;
	}
};

class Cat :public Animal
{
public:
	//�������� virtual�ɼӿɲ���
	virtual void speak()
	{
		cout << "Сè��˵��" << endl;
	}

	virtual void eat(int a)
	{
		cout << "Сè�ڳԷ�" << endl;
	}
};

class Dog :public Animal
{
public:
	//�������� virtual�ɼӿɲ���
	virtual void speak()
	{
		cout << "����˵��" << endl;
	}

	virtual void eat(int a)
	{
		cout << "���ڳԷ�" << endl;
	}
};


//����Ǹ�����Ĺ�ϵ�������໥ת��
//�����麯���� ��animal.speak()�ĵ��ò����ڱ���׶ξͰ󶨺ú����ĵ�ַ������������ʱ�Һ����ĵ�ַ����ַ��󶨣���̬���࣬������̬
//��̬  �����ָ��������� ָ���������
//��̬��������  �����м̳У��������麯��
void doSpeak(Animal &animal)//Animal &animal = cat;
{
	//�ڱ����ڼ� �����animal.speak();���Ѿ��󶨺��˵�ַ,��ַ����󶨣���̬����
	animal.speak();
}

//void doEat(Animal & animal)
//{
//	animal.eat();
//}

void test01()
{
	Cat cat;
	doSpeak(cat);
	//cout << sizeof(Animal) << endl;

	//doEat(cat);
	Dog dog;
	doSpeak(dog);
}

void test02()
{
	//��̬
	//�����ָ�������ָ������Ķ���
	Animal * animal = new Cat;
	//animal->speak();


	//�ڲ�����speakԭ��
	// *(int*)*(int*)animal  �����ĵ�ַ  &Cat::speak�ľ����ַ
	((void(*)()) (*(int*)*(int*)animal))();


	//__cdecl //C++Ĭ�ϵ��÷�ʽ
	//�����õĵ��÷�ʽ __stdcall
	//����Լ����ͬ�����׳��쳣
	//����eatСè�Է�

	//�����ʽ  ���߱��������� __stdcall�ķ�ʽȥ���ú���
	typedef void(__stdcall *FUNCCAT)(int);

	(FUNCCAT(*((int*)*(int*)animal + 1)))(10);
}

int main(){
	test01();
	//test02();

	system("pause");
	return EXIT_SUCCESS;
}