#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class MobilePhone
{
public:
	MobilePhone(const char* brand, const char* model)
	{
		//深拷贝brand
		int len_brand = strlen(brand);
		this->brand = new char[len_brand+1];
		strcpy(this->brand, brand);
		//深拷贝model
		int len_model = strlen(model);
		this->model = new char[len_model+1];
		strcpy(this->model, model);

		this->battery_level = 100;
	}
	void charge(int minutes)
	{
		this->battery_level += minutes * 2;
		if (this->battery_level > 100)
		{
			this->battery_level = 100;
		}
		cout << "充电到 " << this->battery_level << "%" << endl;
	}
	void use(int minutes)
	{
		int temp = this->battery_level;
		this->battery_level -= minutes * 5;
		if (this->battery_level <= 0)
		{
			this->battery_level = 0;
			cout << this->brand << " " << this->model << " 电量耗尽，已关机！" << endl;
			return;
		}
		cout << temp << " -> " << this->battery_level << endl;
		return;
	}
	void display_info()
	{
		cout << this->brand << " " << this->model << " 当前电量：" << this->battery_level << endl;
	}
	~MobilePhone()
	{
		delete[]brand;
		delete[]model;
	}
private:
	char* brand;
	char* model;
	int battery_level;
};

int main()
{
	MobilePhone phone("Apple", "iphone 16");
	phone.use(15);
	phone.display_info();
	phone.charge(5);
	phone.display_info();
	phone.use(6);
	phone.use(20);
	return 0;
}