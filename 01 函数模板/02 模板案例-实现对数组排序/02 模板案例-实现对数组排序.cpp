#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���� ����int  char���͵�������� ����������� �Ӵ�С����������ʽ  ѡ������


//����ͨ�����ݺ���
template<class T>
void mySwap(T & a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> // �ȼ��� template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		int max = i; //������±�
		for (int j = i + 1; j < len;j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //������±� ������i ����������
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

//ͨ�õĴ�ӡ����
template< typename T>
void myPrint(T arr[] , int len)
{
	for (int i = 0; i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01()
{
	char charArray[] = "helloworld";
	int len = sizeof(charArray) / sizeof(char);
	mySort(charArray, len);

	myPrint(charArray, len);

	//����int����
	int intArray[5] = { 1, 3, 8, 4, 2 };
	int len2 = sizeof(intArray) / sizeof(int);
	mySort(intArray, len2);
	myPrint(intArray, len2);
}



int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}