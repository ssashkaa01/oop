#include "group.h"
#include <iostream>

using namespace std;


Group::Group(int const size) {
	st = new Student[size];
	count = size;
}

void Group::setMediumRating() {

	mediumRating = 0;

	for (int i = 0; i < count; i++) {
		mediumRating += st[i].getRating();
	}

	mediumRating /= (double)count;
}

double Group::getMediumRating() const{
	return mediumRating;
}
void Group::show() const {
	for (int i = 0; i < count; i++) { 
		cout << endl;
		st[i].Show();
	}
}

void Group::fill() {
	for (int i = 0; i < count; i++) {
		st[i].Fill();
	}
}

void Group::addStudent() {

	Student* st2 = new Student[count + 1];

	for (int i = 0; i < count; i++) {
		st2[i] = st[i];
	}

	st2[count].Fill();

	count++;

	delete[] st;

	st = st2;
}

Group Group::getGoodGroup(Group &gp)
{
	this->setMediumRating();

	gp.setMediumRating();

	return (this->getMediumRating() > gp.getMediumRating()) ? *this : gp;
}

void Group::showSuccessStudent(int rat) const {
	
	for (int i = 0; i < count; i++) {
		cout << endl;
		
		if (st[i].getRating() >= rat) {
			st[i].Show();
		}
	}
}

void Group::sortFromRating() {

	Student* st2 = new Student[count];

	int maxRat = 0;
	int minRat = 0;
	int idx = 0;
	
	//Пошук найбільшого по рейтингу
	for (int i = 0; i < count; i++) {
		
		if (st[i].getRating() >= maxRat) {
			st2[0] = st[i];
			maxRat = st[i].getRating();
		}
	}

	//Сортуємо
	for (int i = 1; i < count; i++) {

		minRat = 0;

		for (int j = 0; j < count; j++) {

			if (st[j].getRating() < maxRat && minRat < st[j].getRating()) {
				minRat = st[j].getRating();
				idx = j;
			}
		}
		maxRat = st[idx].getRating();
		st2[i] = st[idx];
	}

	delete[] st;

	st = st2;
}

void Group::sortFromSkips() {

	Student* st2 = new Student[count];

	int maxRat = 0;
	int minRat = 0;
	int idx = 0;

	//Пошук найбільшого по рейтингу
	for (int i = 0; i < count; i++) {

		if (st[i].getSkips() >= maxRat) {
			st2[0] = st[i];
			maxRat = st[i].getSkips();
		}
	}

	//Сортуємо
	for (int i = 1; i < count; i++) {

		minRat = 0;

		for (int j = 0; j < count; j++) {

			if (st[j].getSkips() < maxRat && minRat < st[j].getSkips()) {
				minRat = st[j].getSkips();
				idx = j;
			}
		}
		maxRat = st[idx].getSkips();
		st2[i] = st[idx];
	}

	delete[] st;

	st = st2;
}


