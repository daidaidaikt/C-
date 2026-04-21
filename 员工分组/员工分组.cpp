#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	Worker(string name, int salary)
	{
		this->name = name;
		this->salary = salary;
	}
	void print_worker()
	{
		cout << "name:" << this->name << "," << "salary:" << this->salary << "," << endl;
	}
private:
	string name;
	int salary;
};

void creat_workers(vector<Worker>& v)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "员工";
		name += nameseed[i];
		int salary = rand() % 10000 + 10000;//10000~19999
		Worker worker(name, salary);
		v.push_back(worker);
	}
}

void set_group(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int id = rand() % 3;//0,1,2
		m.insert(pair<int, Worker>(id, *it));//m.insert(make_pair(id,*it));
	}
}

void show_worker_group(multimap<int, Worker>& m)
{
	cout << "策划部门" << endl;
	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		pos->second.print_worker();
	}
	cout << "--------------------------" << endl;

	cout << "美术部门" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		pos->second.print_worker();
	}
	cout << "--------------------------" << endl;

	cout << "研发部门" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		pos->second.print_worker();
	}
	cout << "--------------------------" << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker>Workers;
	creat_workers(Workers);

	multimap<int, Worker>Group;
	set_group(Workers, Group);

	show_worker_group(Group);

	return 0;
}