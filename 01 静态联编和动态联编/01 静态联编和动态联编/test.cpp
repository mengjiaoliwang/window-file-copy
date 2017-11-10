#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	//加上virtual后变为 虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "动物在吃饭" << endl;
	}
};

class Cat :public Animal
{
public:
	//在子类中 virtual可加可不加
	virtual void speak()
	{
		cout << "小猫在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "小猫在吃饭" << endl;
	}
};

class Dog :public Animal
{
public:
	//在子类中 virtual可加可不加
	virtual void speak()
	{
		cout << "狗在说话" << endl;
	}

	virtual void eat(int a)
	{
		cout << "狗在吃饭" << endl;
	}
};


//如果是父子类的关系，可以相互转换
//加入虚函数中 ，animal.speak()的调用不会在编译阶段就绑定好函数的地址，而是在运行时找函数的地址，地址晚绑定，动态联编，发生多态
//多态  父类的指针或者引用 指向子类对象
//多态产生条件  必须有继承，必须有虚函数
void doSpeak(Animal &animal)//Animal &animal = cat;
{
	//在编译期间 ，这个animal.speak();就已经绑定好了地址,地址的早绑定，静态联编
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
	//多态
	//父类的指针或引用指向子类的对象
	Animal * animal = new Cat;
	//animal->speak();


	//内部调用speak原理
	// *(int*)*(int*)animal  函数的地址  &Cat::speak的具体地址
	((void(*)()) (*(int*)*(int*)animal))();


	//__cdecl //C++默认调用方式
	//我们用的调用方式 __stdcall
	//调用约定不同导致抛出异常
	//调用eat小猫吃饭

	//解决方式  告诉编译器利用 __stdcall的方式去调用函数
	typedef void(__stdcall *FUNCCAT)(int);

	(FUNCCAT(*((int*)*(int*)animal + 1)))(10);
}

int main(){
	test01();
	//test02();

	system("pause");
	return EXIT_SUCCESS;
}