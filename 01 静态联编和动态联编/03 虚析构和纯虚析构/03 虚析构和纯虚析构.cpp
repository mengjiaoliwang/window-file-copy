#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "����˵��" << endl;
	}

	//������
	//���������  ����������� ��ָ������Ŀռ䣬��Ҫ�������н����ͷţ���ʱ����Ҫ�ڸ����н�������дΪ������
	//virtual ~Animal()
	//{
	//	cout << "�����������������" << endl;
	//}


	//�������� ����Ҫ��ʵ��
	//�������� ����ʵ��

	//���һ������ ���˴����������� ����ô�����Ҳ��Ϊ �����࣬ ����ʵ��������
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "����� ������������" << endl;
}

class Cat :public Animal
{
public:
	Cat(){};
	Cat(char * name)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}

	virtual void speak()
	{
		cout << "Сè˵��" << endl;
	}

	virtual ~Cat() = 0;
	/*{
		if (this->m_Name !=NULL)
		{
			cout << "Cat��������������" << endl;
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}*/

	char * m_Name; //��������
};
Cat::~Cat()
{
	if (this->m_Name != NULL)
	{
		cout << "Cat��������������" << endl;
		delete[] this->m_Name;
		this->m_Name = NULL;
	}
}
class catdelete:public Cat
{
public:
	catdelete()
	{
		
	};
	~catdelete()
	{
		cout <<"������������" << endl;
	}


};


void test01()
{
	Cat *catelete = new catdelete;
	//Animal * cat = new Cat("Tom");
	//cat->speak();

	//delete cat;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}