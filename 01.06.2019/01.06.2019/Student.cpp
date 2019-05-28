#include "Student.h"
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#pragma warning(disable : 4996)

using namespace std;

Student::Student()
{
	name = "no name";
	age = 0000;
	yearOfBirth = 0000;
	address = "undefined";
	rating = 0.0;
}

Student::Student(
	string _name,
	int _yearOfBirth,
	string _address,
	double _rating
)
{
	name = _name;
	yearOfBirth = _yearOfBirth;
	address = _address;
	rating = _rating;
	setAge(_yearOfBirth);
}

void Student::Show() const
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Year of Birth: " << yearOfBirth << endl;
	cout << "Address: " << address << endl;
	cout << "Rating: " << rating << endl;
}

double Student::getRating() const
{
	return rating;
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
	cout << "Year of Birth: " << endl;
	cin >> yearOfBirth;
	cout << "Address: " << endl;
	cin >> address;
	cout << "Rating: " << endl;
	cin >> rating;

	setAge(yearOfBirth);

}

void Student::writeFile() const {

	ofstream out("student.txt", ios_base::out | ios::trunc);

	out << "Name: " << name << endl;
	out << "Age: " << age << endl;
	out << "Year of Birth: " << yearOfBirth << endl;
	out << "Address: " << address << endl;
	out << "Rating: " << rating << endl;
	
	out.close();
}
void Student::readFile() const {

	ifstream in("student.txt", ios_base::in);

	string s;

	while (!in.eof()) {

		getline(in, s);

		cout << s << endl;

	}

	in.close();
}
