#pragma  once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	explicit MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		//开辟空间
		this->pAddress = new T[this->m_Capacity];
	}

	MyArray(const MyArray & array)
	{
		this->m_Capacity = array.m_Capacity;
		this->m_Size = array.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < array.m_Size;i++)
		{
			this->pAddress[i] = array.pAddress[i];
		}
	}
	//重载[]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//尾插法
	void push_back(const T &val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void pop_back()
	{
		//如果容器中一个数据都没有，那么就不要做尾删了
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//获取数组的元素个数
	int getSize()
	{
		return this->m_Size;
	}



	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete [] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	T * pAddress; //指向堆区空间的指针
	int m_Capacity; //容量
	int m_Size; //大小

};