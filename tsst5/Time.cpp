#include "Time.h"
//无参构造函数
Time::Time()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
//普通构造函数
Time::Time(int hour, int minute, int second)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}
//拷贝构造函数
Time::Time(const Time& another)
{
	this->hour = another.hour;
	this->minute = another.minute;
	this->second = another.second;
}
//显示功能
void Time::ShowTime()
{
	cout << this->hour << "时" << this->minute << "分" << this->second << "秒" << endl;
}
//析构函数
Time::~Time()
{

}