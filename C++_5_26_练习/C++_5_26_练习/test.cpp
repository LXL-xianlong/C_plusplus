#define _CRT_SECURE_NO_WARNINGS 1
class Date
{

public:
	// 1.无参构造函数
	Date()
	{}

	// 2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1; // 调用无参构造函数
	Date d2(2015, 1, 1); // 调用带参的构造函数
	Date d3();
}


class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year;
	int _month;
	int _day;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}