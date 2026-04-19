#include<iostream>
#include<list>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}
	friend ostream& operator<<(ostream& os, const Person& c);
	friend class compare_person;
private:
	string name;
	int age;
	int height;
};

ostream& operator<<(ostream& os, const Person& c)
{
	os << "name:" << c.name << " " << "age:" << c.age << " " << "heigth:" << c.height;
	return os;
}

void print_list(const list<Person>& l)
{
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
}

class compare_person
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		if (p1.age == p2.age)
		{
			return p1.height > p2.height;
		}
		else
		{
			return p1.age < p2.age;
		}
	}
};
int main()
{
	list<Person>L;
	Person p1("代1", 10, 160);
	Person p2("代2", 11, 170);
	Person p3("代3", 12, 180);
	Person p4("代4", 13, 190);
	Person p5("代5", 14, 190);
	Person p6("代6", 15, 190);
	Person p7("代7", 16, 190);
	Person p8("代8", 17, 190);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);
	L.push_back(p8);

	print_list(L);
	cout << "-----------------------------------" << endl;
	L.sort(compare_person());
	print_list(L);

	return 0;
}