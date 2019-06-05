#pragma once
#include "Student.h"
class Group
{

	Student *st;
	int count = 0;
	double mediumRating = 0;
public:

	Group(int const);
	double getMediumRating() const;
	void setMediumRating();
	void show() const;
	void fill();
	void addStudent();
	Group getGoodGroup(Group &gp);
	void showSuccessStudent(int rat) const;
	void sortFromRating();
	void sortFromSkips();
};

