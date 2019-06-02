#include <iostream>
#include <string>
#include "mystring.h"
#include "SmartArray2.h"
# include <ctime>

using namespace std;


int main() {

	srand(unsigned(time(NULL)));

	SmartArray2 arr(2,4);
	arr.fill();
	arr.print();
	
	cout << endl;
	
	arr.addtoindexcol(3);
	arr.addtoindex(1);

	arr.print();
	cout << endl;

	arr.delindexcol(3);
	arr.delindex(1);

	arr.print();
	cout << endl;

	//char a = 'a';
	//mystring str(a, 4);
	//mystring str;
	//char aa[] = "dsfsfjkdfk";
	//str.SetStringFromKeyboard();
	//str.append(aa);
	//str.showString();

	

	system("pause");
	return 0;
}