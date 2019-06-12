#pragma once
class Time
{
private:
	int time;
public:
	Time(int, int, int);
	Time(int);
	void Print() const;
	void addTime(int);
	friend bool operator==(const Time&, const Time&);
	bool operator!=(const Time&) const;
	bool operator<=(const Time&) const;
	bool operator>=(const Time&) const;
	friend Time operator++(Time&);
	friend Time operator--(Time&);
	void operator()(int, int, int);
	void operator()(int);
	int getTime() const;
	~Time();
};

bool operator>(const Time&, const Time&);
bool operator<(const Time&, const Time&);

