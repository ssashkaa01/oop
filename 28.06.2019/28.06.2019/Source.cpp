#include <iostream>
#include "List.h"
#include <ctime>

using namespace std;

int main() {

	List users;
	List users2;
	users.Add(1, 4);
	users.Add(1, 5);
	users.Add(1, 7);
	users2.Add(1, 2);
	users2.Add(1,3);
	/*users = users + users2;
	users.ShowList();*/

	users = -users;
	users.ShowList();

	system("pause");
	return 0;
}