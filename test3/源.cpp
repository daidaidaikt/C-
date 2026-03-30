#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct Info {
	int count;
	int* indices;
};
template <typename T>
class Arr_Analyzer
{
public:
	Arr_Analyzer()
	{
		//录入数组
		cout << "请输入数组长度：";
		cin >> len;
		arr = new T[len];
		cout << "请输入" << len << "个元素：";
		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}
		//初始化统计信息
		unique_vals = new T[len];
		infos = new Info[len];
		unique_count = 0;
		//查找相异元素，并统计
		for (int i = 0; i < len; i++)
		{
			int idx = find_index(arr[i]);
			if (idx == -1)
			{
				unique_vals[unique_count] = arr[i];
				infos[unique_count] = { 1,new int[len]};
				infos[unique_count].indices[0] = i;
				unique_count++;
			}
			else
			{
				infos[idx].indices[infos[idx].count] = i;
				infos[idx].count++;
			}
		}
	}
	~Arr_Analyzer()
	{
		delete[] arr;
		delete[] unique_vals;
		for (int i = 0; i < unique_count; i++)
		{
			delete[] infos[i].indices;
		}
		delete[] infos;
	}
	//打印结果
	void print_result()
	{
		cout << "----------相异元素的统计结果----------" << endl;
		for (int i = 0; i < unique_count; i++)
		{
			cout << "元素 " << unique_vals[i] << " 出现 " << infos[i].count << " 次，下标为：";
			for (int j = 0; j < infos[i].count; j++)
			{
				cout << infos[i].indices[j] << " ";
			}
			cout << endl;
		}
	}

private:
	T* arr;
	int len;
	T* unique_vals;
	Info* infos;
	int unique_count;

	int find_index(T val)
	{
		for (int i = 0; i < unique_count; i++)
		{
			if (unique_vals[i] == val)
				return i;
		}
		return -1;
	}
};
int main()
{
	cout << "请选择数据类型(1-int   2-double   3-char)" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		Arr_Analyzer<int> a;
		a.print_result();
		break;
	}
	case 2:
	{
		Arr_Analyzer<double> a;
		a.print_result();
		break;
	}
	case 3:
	{
		Arr_Analyzer<char> a;
		a.print_result();
		break;
	}
	}
	return 0;
}