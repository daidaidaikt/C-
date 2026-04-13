#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Time
{
public:
	//无参构造函数
	Time();

	//普通构造函数
	Time(int hour, int minute, int second);

	//拷贝构造函数
	Time(const Time& another);

	//显示功能
	void ShowTime();

	//析构函数
	~Time();

private:
	int hour;
	int minute;
	int second;
};

