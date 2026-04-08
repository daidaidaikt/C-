#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	friend void setScore(vector<Person>& v);
	friend void showScore(const vector<Person>& v);
private:
	string name;
	int score;
};

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数，放入deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//使分数在60~100
			d.push_back(score);
		}

		sort(d.begin(), d.end());

		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		int avg = sum / d.size();

		it->score = avg;
	}
}

void showScore(const vector<Person>& v)
{
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->name << "平均分：" << it->score << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<Person>v;
	createPerson(v);

	setScore(v);

	showScore(v);

	return 0;
}