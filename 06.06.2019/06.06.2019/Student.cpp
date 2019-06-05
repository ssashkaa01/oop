#include "Student.h"
#include <string>
#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

Student::Student()
{
	name = "no name";
	age = 0000;
	yearOfBirth = 0000;
	address = "undefined";
	rating = 0.0;
	skips = 0;
}

Student::Student(
	string _name,
	int _yearOfBirth,
	string _address,
	double _rating,
	int _skips
) 
{
	name = _name;
	yearOfBirth = _yearOfBirth;
	address = _address;
	rating = _rating;
	skips = _skips;
	setAge(_yearOfBirth);
}

void Student::Show() const
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Year of Birth: " << yearOfBirth << endl;
	cout << "Address: " << address << endl;
	cout << "Rating: " << rating << endl;
	cout << "Skips: " << skips << endl;
}

double Student::getRating() const
{
	return rating;
}

int Student::getSkips() const
{
	return skips;
}

Student Student::getGoodStudent(Student &st) const
{

	return (this->rating > st.getRating()) ? *this : st;
}

void Student::setAge(int _yearOfBirth) 
{

	time_t now = time(0);
	tm *ltm = localtime(&now);
	age = 1900 + ltm->tm_year - _yearOfBirth;
}

void Student::Fill() {
	cout << "Name: " << endl;
	cin >> name;
	cout << "Year of Birth: "<< endl;
	cin >> yearOfBirth;
	cout << "Address: " << endl;
	cin >> address;
	cout << "Rating: " << endl;
	cin >> rating;

	cout << "Skips: " << endl;
	cin >> skips;

	setAge(yearOfBirth);

}

