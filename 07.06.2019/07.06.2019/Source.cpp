#include <iostream>
#include <string>
#include "SmartArray2.h"
# include <ctime>

using namespace std;


int main() {

	srand(unsigned(time(NULL)));

	SmartArray2 arr(2,4);
	arr.fill();
	arr.print();

	SmartArray2 arr2(arr);
	cout << endl;

	arr2.print();
	
	//cout << endl << arr.min() << endl;
	//cout << endl << arr.max() << endl;

	cout << endl;

	

	system("pause");
	return 0;
}