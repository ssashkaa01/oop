#include <iostream>
#include "Time.h"

using namespace std;
Time operator--(Time& t, int i);
Time operator++(Time& t, int i);
int main() {

	Time t(267);

	t.Print();
	t++;

	//t(3, 56, 7);
	//t(6);
	t.Print();


	system("pause");
	return 0;
}