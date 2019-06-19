#include "List.h"
#include <iostream>
using namespace std;

void main()
{
	List list;

	list.AddTail(4);
	list.AddTail(100);
	list.AddTail(30);
	list.AddTail(400);
	list.AddTail(50);
//	list.DeleteFromIndex(2);
//	list.DeleteFromIndex(2);
	list.ShowList();
	cout << "--------------------\n";
	list.sort();
	
	cout << "--------------------\n";

	if (list.searchNumber(10)) {
		cout << "Number founded" << endl;
	}
	else {
		cout << "Not found!" << endl;
	}

	cout << "Position: " << list.searchNumberPosition(10) << endl;

	cout << "--------------------\n";

	/*list.Add(1, 3);
	list.ShowList();
	cout << "--------------------\n";

	list.Add(2, 9);
	list.ShowList();
	cout << "--------------------\n";*/

	list.Add(40, 29);
	cout <<"Replace: " << list.replace(400, 4) << endl;
	cout << "--------------------\n";
	list.ShowList();
	cout << "--------------------\n";

	system("pause");
}