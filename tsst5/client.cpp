#include"Time.h"

int main()
{
	//无参构造
	Time t1;
	//普通构造
	Time t2(16, 54, 31);
	//拷贝构造
	Time t3(t2);
	Time t4 = t1;

	//显示功能
	t1.ShowTime();
	t2.ShowTime();
	t3.ShowTime();
	t4.ShowTime();

	return 0;
}