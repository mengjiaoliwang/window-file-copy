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
		//���ٿռ�
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
	//����[]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//β�巨
	void push_back(const T &val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//βɾ��
	void pop_back()
	{
		//���������һ�����ݶ�û�У���ô�Ͳ�Ҫ��βɾ��
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//��ȡ�����Ԫ�ظ���
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
	T * pAddress; //ָ������ռ��ָ��
	int m_Capacity; //����
	int m_Size; //��С

};