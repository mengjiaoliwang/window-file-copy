#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <list>


void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++){
		v.push_back(i);
		cout << v.capacity() << endl;  // v.capacity()����������
	}
	//������2���Ĵ�С������չ
}


/*
3.2.4.1 vector���캯��
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����

//���� ʹ�õڶ������캯�� ���ǿ���...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector���ø�ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
vector& operator=(const vector  &vec);//���صȺŲ�����
swap(vec);// ��vec�뱾���Ԫ�ػ�����

3.2.4.3 vector��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	int array[] = { 2, 5, 8, 9, 1 };
	vector <int>v1(array, array + sizeof(array) / sizeof(int));
	printVector(v1);

	vector<int>v2(v1.begin(), v1.end());
	//printVector(v2);

	vector<int>v3 = v2; //��������

	vector<int>v4(10, 100);
	printVector(v4);

	//swap����
	cout << "v1�� v4������" << endl;

	v1.swap(v4);
	printVector(v1);
	printVector(v4);


	cout << "v4�����Ĵ�С��" << v4.size() << endl;
	//�ж������Ƿ�Ϊ��
	if (v4.empty())
	{
		cout << "v4����Ϊ��" << endl;
	}
	else
	{
		cout << "v4������Ϊ��" << endl;
	}

	//resize����ָ����С  v4    2, 5, 8, 9, 1��Ĭ����0 ���
	v4.resize(10,10000); //����2 �����޸�Ĭ�����ֵ

	printVector(v4);

	v4.resize(3);

	printVector(v4);

}


// ����swap�����ڴ�
void test03()
{
	vector<int>v;
	for (int i = 0; i < 100000;i++)
	{
		v.push_back(i);
	}

	cout << "������ " << v.capacity() << endl;
	cout << "��С�� " << v.size() << endl;

	v.resize(3);
	cout << "������ " << v.capacity() << endl;
	cout << "��С�� " << v.size() << endl;


	vector<int>(v).swap(v);
	cout << "������ " << v.capacity() << endl;
	cout << "��С�� " << v.size() << endl;

}

//����reserveԤ���ռ�
//reverse ��ת
void test04()
{
	vector<int>v;

	//����Ѿ�֪�����ݵ�������������Ԥ������ַ
	v.reserve(100000);

	int * p = NULL;
	int num = 0;
	for (int i = 0; i < 100000;i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	// ��¼���˿����˶��ٴ� �µĿռ�
	cout << "num = " << num << endl;
}

/*
3.2.4.4 vector���ݴ�ȡ����
at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
operator[];//��������idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
front();//���������е�һ������Ԫ��
back();//�������������һ������Ԫ��

3.2.4.5 vector�����ɾ������
insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele.
push_back(ele); //β������Ԫ��ele
pop_back();//ɾ�����һ��Ԫ��
erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);//ɾ��������ָ���Ԫ��
clear();//ɾ������������Ԫ��

*/
void test05()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	cout << "v.front = " << v.front() << endl; //��һ��Ԫ��
	cout << "v.back = " << v.back() << endl;//���һ��Ԫ��

	//insert����
	v.insert(v.begin(), 100); //��һ�������ǵ����� ������int����
	v.insert(v.begin(), 2,1000);

	printVector(v);

	//βɾ
	v.pop_back();
	printVector(v);

	//ɾ��  ����Ҳ�ǵ�����
	v.erase(v.begin());
	printVector(v);

	//v.erase(v.begin(), v.end());  //��յ�һ������
	v.clear();  //��յڶ��ַ���
	printVector(v);
}

/*
	�������
*/
void test06()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//reverse_iterator ��ת������
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend();it++)
	{
		cout << *it << endl;
	}

	//����ж�һ���������Ƿ�֧���������

	vector<int>::iterator itBegin = v.begin();
	itBegin = itBegin + 1; //�������д��+ ��Ծʽ���ʣ���ô��������ĵ�������������ʵĵ�����

	//list�����������ǲ�֧��������ʵ�
	/*list<int>L;
	list<int>::iterator Lit = L.begin();
	Lit = Lit + 1;*/

}


int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	
	
	system("pause");
	return EXIT_SUCCESS;
}