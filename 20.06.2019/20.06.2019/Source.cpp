#include <iostream>
#include "mystring.h"

using namespace std;

int main() {

	mystring s1;
	mystring s2;

 	s1.SetString("dsd");
	s1.showString();


	s2 = s1;

	s2.showString();
	//s1.showString();
	//s1.SetString("2223");
	//s1.showString();

	system("pause");
	return 0;
}