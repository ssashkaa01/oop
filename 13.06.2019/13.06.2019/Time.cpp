#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int seconds, int minutes, int hours) {

	time = seconds + minutes * 60 + hours * 3600;
}
Time::Time(int seconds) {

	time = seconds;

}

int Time::getTime() const {
	return time;
}
void Time::Print() const {

	int test = (time > 0) ? 10 : 5;

	cout << test << endl;

	int hours = time / 3600;
	int minutes = 0;
	int seconds = 0;
	int tmp = time;

	tmp -= hours * 3600;

	if (tmp > 0) minutes = tmp / 60;

	tmp -= minutes * 60;

	seconds = tmp;

	cout << "Time: " << seconds << ":" << minutes << ":" << hours << endl;
}
bool operator==(const Time& t1, const Time& t2) {

	return t1.time == t2.time;
}
bool Time::operator!=(const Time& t) const {

	return t.time != time;
}

bool Time::operator<=(const Time& t) const {

	return t.time <= time;
}
bool Time::operator>=(const Time& t) const {

	return t.time >= time;
}

Time operator++(Time& t) {

	++t.time;

	return t;

}
Time operator--(Time& t) {

	--t.time;

	return t;

}
Time operator++(Time& t,int i) {

	Time tmp(t.getTime());

	t.addTime(1);

	return tmp;
}
Time operator--(Time& t, int i) {

	Time tmp(t.getTime());

	t.addTime(-1);

	return tmp;
}

Time::~Time()
{
}

void Time::operator()(int seconds, int minutes, int hours) {

	time += seconds + minutes * 60 + hours * 3600;
}

void Time::operator()(int seconds) {

	time += seconds;
}

bool operator>(const Time& t1, const Time& t2) {

	return t1.getTime() > t2.getTime();
}
bool operator<(const Time& t1, const Time& t2) {

	return t1.getTime() < t2.getTime();
}

void Time::addTime(int s) {
	time += s;
}