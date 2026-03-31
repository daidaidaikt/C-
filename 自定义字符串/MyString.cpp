#include "MyString.h"

MyString::MyString()
{
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

MyString::MyString(int len)
{
	if (len < 0) len = 0;
	this->len = len;
	this->str = new char[len+1](0);
}

MyString::MyString(const char* str)
{
	if (str == NULL)
	{
		this->str = new char[1];
		this->str[0] = '\0';
		this->len = 0;
	}
	else
	{
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		strcpy(this->str, str);
	}
}

MyString::MyString(const MyString& another)
{
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

MyString::~MyString()
{
	delete[] this->str;
	this->str = NULL;
	this->len = 0;
}

char& MyString::operator[](int index)
{
	if (index < 0 || index >= this->len)
	{
		static char null_char = '\0';
		return null_char;
	}
	return this->str[index];
}

ostream& operator<< (ostream& os, const MyString& str)
{
	os << str.str;
	return os;
}

istream& operator>> (istream& is, MyString& str)
{
	char temp[1024];
	is >> temp;
	str = temp;
	return is;
}

MyString& MyString::operator=(const MyString& another)
{
	//防止自身被赋值
	if (this == &another)
		return *this;
	//现将自身开辟的额外空间回收
	if (this->str != NULL)
	{
		delete[]this->str;
		this->str = NULL;
		this->len = 0;
	}
	//执行深拷贝
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
	return *this;
}

MyString& MyString::operator=(const char* str)
{
	//将自身开辟的额外空间回收
	if (this->str != NULL)
	{
		delete[]this->str;
		this->str = NULL;
		this->len = 0;
	}
	//执行深拷贝
	if (str == NULL)
	{
		this->str = new char[1];
		this->str[0] = '\0';
		this->len = 0;
	}
	else
	{
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		strcpy(this->str, str);
	}
	return *this;
}

bool MyString::operator==(const MyString& another)const
{
	return strcmp(this->str, another.str) == 0;
}
bool MyString::operator==(const char* str)const
{
	if (str == NULL)return this->len == 0;
	return strcmp(this->str, str) == 0;
}