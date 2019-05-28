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

public:
	Student();
	Student(
		string _name,
		int _yearOfBirth,
		string _address,
		double rating
	);
	void Fill();
	void Show() const;
	void writeFile() const;
	void readFile() const;
	double getRating() const;
	void setAge(int _yearOfBirth);
};

