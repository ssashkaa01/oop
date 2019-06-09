#include <iostream>
#include "Date.h"
#include <ctime>

using namespace std;

Date::Date(int _year, int _month, int _day)
{
	this->year = _year;
	this->month = _month;
	this->day = _day;
}

int Date::getDays(int _year, int _month, int _day) const {

	int d_days = 0;

	//Високосний
	int M[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	//Не високосний
	int M2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	for (int i = 1970; i < _year; i++) {

		//Не високосний
		if (_year % 4 != 0 || _year % 100 == 0 && _year % 400 != 0) {
			d_days += 365;
		}
		else {
			d_days += 366;
		}
	}

	for (int i = 0; i < _month-1; i++) {

		//Не високосний
		if (_year % 4 != 0 || _year % 100 == 0 && _year % 400 != 0) {
			d_days += M2[i];
		}
		else {
			d_days += M[i];
		}

	}

	d_days += _day;

	
	return d_days;
}

int Date::operator-(const Date& data) const
{
	int diff = getDays(data.year, data.month, data.day) - getDays(year, month, day);
	
	return (diff < 0) ? diff * -1 : diff;
}

Date Date::operator+(int days) const
{
	Date d(this->year, this->month, this->day + days);

	return d;
}

void Date::Show() const{
	cout << endl << "Year: " << this->year << endl;
	cout << "Month: " << this->month << endl;
	cout << "Day: " << this->day << endl << endl;
}

void Date::Show(int _year, int _month, int _day) const {
	cout << endl << "Year: " << _year << endl;
	cout << "Month: " << _month << endl;
	cout << "Day: " << _day << endl << endl;
}

Date::~Date()
{
}
