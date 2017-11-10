#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//需求： 对于int  char类型的数组进行 排序，排序规则 从大到小，利用排序方式  选择排序


//交换通用数据函数
template<class T>
void mySwap(T & a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> // 等价于 template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		int max = i; //最大数下标
		for (int j = i + 1; j < len;j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //最大数下标 不等于i ，交换数据
		{
			mySwap(arr[max], arr[i]);
		}
	}
}

//通用的打印数组
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

	//测试int类型
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