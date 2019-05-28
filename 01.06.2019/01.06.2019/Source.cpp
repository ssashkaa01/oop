#include <iostream>
#include <string>
#include "Student.h"
#include "SmartArray.h"

using namespace std;

int main() {
	
	Student st;

	st.Fill();
	cout << endl << "Created student" << endl << endl;
	st.Show();
	st.writeFile();
	cout << endl << "From file" << endl << endl;
	st.readFile();

	system("pause");
	return 0;
}