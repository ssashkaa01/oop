#include <iostream>
#include <string>
#include "Student.h"
#include "group.h"
#include "SmartArray.h"

using namespace std;

int main() {

	Group g(3);
	g.fill();
	g.show();
	g.setMediumRating();

	cout << endl << "Medium rating: " << g.getMediumRating() << endl;

	g.sortFromRating();
	g.show();


	system("pause");
	return 0;
}