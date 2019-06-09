#pragma once
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int, int, int);
	void Show() const;
	void Show(int, int, int) const;
	int operator-(const Date& data) const;
	Date operator+(int days) const;
	int getDays(int, int, int) const;
	~Date();
};

