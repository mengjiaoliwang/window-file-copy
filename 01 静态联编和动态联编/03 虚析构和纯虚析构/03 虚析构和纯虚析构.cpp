#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "动物说话" << endl;
	}

	//虚析构
	//解决的问题  如果在子类中 有指向堆区的空间，需要在子类中进行释放，这时候需要在父类中将析构改写为虚析构
	//virtual ~Animal()
	//{
	//	cout << "动物的析构函数调用" << endl;
	//}


	//纯虚析构 必须要做实现
	//类内声明 类外实现

	//如果一个类中 有了纯虚析构函数 ，那么这个类也称为 抽象类， 不能实例化对象
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "动物的 纯虚析构调用" << endl;
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
		cout << "小猫说话" << endl;
	}

	virtual ~Cat() = 0;
	/*{
		if (this->m_Name !=NULL)
		{
			cout << "Cat的析构函数调用" << endl;
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}*/

	char * m_Name; //动物名称
};
Cat::~Cat()
{
	if (this->m_Name != NULL)
	{
		cout << "Cat的析构函数调用" << endl;
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
		cout <<"调用析构函数" << endl;
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