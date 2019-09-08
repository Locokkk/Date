#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Date
{
public:
	int GetMonthDay(int year, int month)//准确给出每个月的天数
	{
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (month == 2 && \
			((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))//判断闰年的2月
		{
			return 29;
		}
		else
		{
			return monthDays[month];
		}
	}

	// Date d1(2018, 2, 29);
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		if (year >= 1900
			&& month > 0 && month < 13
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			cout << year << "-" << month << "-" << day << "-" << endl;
		}
		else
		{

		}
	}

	// 拷贝 赋值 析构 / 都要去练习写一下

	bool operator<(const Date& d)
	{
		if ((_year < d._year) || (_year == d._year&&_month < d._month) || (_month == d._month&&_day < d._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const Date& d)
	{
		return (*this < d) || (*this == d);
	}
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}
	bool operator==(const Date& d)
	{
		return (_year == d._year) && (_month == d._month) && (_day == d._day);

	}
	bool operator!=(const Date& d)
	{
		return (_year != d._year) || (_month != d._month) || (_day != d._day);
	}

	// d + 100
	Date operator+(int day)
	{
		if (day < 0)
		{
			return *this - (-day);
		}
		Date d(*this);
		d._day += day;
		while (d._day > GetMonthDay(d._year, d._month))
		{
			d._day -= GetMonthDay(d._year, d._month;
			d._month++;
			if (d._month > 12)
			{
				d._year++;
				d._month = 1;
			}
		}
		return d;
	}

	Date operator-(int day)
	{
		if (day < 0)
		{
			return *this + (-day);
		}
		Date d(*this);
		d._day -= day;
		while (d._day <= 0)
		{
			d._month--;
			if (d._month < 1)
			{
				d._year--;
				d._month = 12;
			}
			d._day += GetMonthDay(d._year, d._month);
		}
		return d;
	}

	Date operator+=(int day)
	{
		return *this = *this + day;
	}

	Date operator-=(int day)
	{
		return *this = *this - day;
	}
	//计算日期差
	int operator-(const Date& d)
	{

	}


	// ++d d.operator++(&d)前置
	Date operator++()
	{
		return *this += 1;
	}
	// d++ d.operator++(&d, 0)后置
	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}
	// --d d.operator--(&d)前置
	Date operator++()
	{
		return *this -= 1;
	}
	// d-- d.operator--(&d, 0)后置
	Date operator++(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

private:
	int _year;
	int _month;
	int _day;
};