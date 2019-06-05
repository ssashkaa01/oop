#pragma once
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int age;
	int yearOfBirth;
	string address;
	double rating;
	int skips;
public:
	Student();
	Student(
		string _name,
		int _yearOfBirth,
		string _address,
		double rating,
		int
	);
	void Fill();
	void Show() const;
	double getRating() const;
	int getSkips() const;
	Student getGoodStudent(Student &st) const;
	void setAge(int _yearOfBirth);
};

