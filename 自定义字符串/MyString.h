#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
using namespace::std;

class MyString
{
public:
	//默认无参构造函数
	MyString();

	//按长度构造
	MyString(int len);

	//从C字符串构造
	MyString(const char* str);

	//拷贝构造函数
	MyString(const MyString& another);

	//析构函数
	~MyString();

	//重载[]运算符
	char& operator[](int index);

	//重载<<运算符
	friend ostream& operator<<(ostream& os, const MyString& str);

	//重载>>运算符
	friend istream& operator>> (istream& is, MyString& str);

	//重载等号运算符
	MyString& operator=(const MyString& another);
	MyString& operator=(const char* str);

	//重载==操作符
	bool operator==(const MyString& another)const;
	bool operator==(const char* str)const;

private:
	char* str;
	int len;
};



