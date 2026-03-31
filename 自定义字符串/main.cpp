#include"MyString.h"

int main()
{
	MyString s1;
	MyString s2("hello world");
	MyString s3(s2);
	MyString s4(10);

	s1 = s2;
	s4 = "DAIKUNTAO";

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;

	cout << "s2[0]:" << s2[0] << endl;
	s2[0] = 'H';
	cout << "修改后的s2[0]:" << s2[0] << endl;

	return 0;
}