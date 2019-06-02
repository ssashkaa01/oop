#include "SmartArray2.h"
#include <ctime>
#include <iostream>

using namespace std;


SmartArray2::SmartArray2(int _rows, int _columns)
{
	rows = _rows;
	colums = _columns;

	arr = new int*[rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[colums];
	}
}

void SmartArray2::fill() {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void SmartArray2::print() {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


void  SmartArray2::addtoindex(int const index) {

	int **atmp = new int*[rows + 1];

	for (int i = 0; i < rows + 1; i++) {
		atmp[i] = new int[colums];
	}

	//Заповнення до
	for (int i = 0; i < index; i++) {
		for (int j = 0; j < colums; j++) {
			atmp[i][j] = arr[i][j];
		}
	}

	//Заповнення після
	for (int i = rows; i > index; i--) {
		for (int j = 0; j < colums; j++) {
			atmp[i][j] = arr[i - 1][j];
		}
	}

	for (int j = 0; j < colums; j++) {
		atmp[index][j] = rand() % 10;
	}

	for (int i = 0; i < rows; i++) {
		delete[]arr[i];
	}

	delete[] arr;

	arr = atmp;
	rows++;
}

void  SmartArray2::addtoindexcol(int const index) {

	int **atmp = new int*[rows];

	for (int i = 0; i < rows; i++) {
		atmp[i] = new int[colums + 1];
	}

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < index; j++) {
			atmp[i][j] = arr[i][j];
		}
		for (int j = index; j < colums+1; j++) {
			atmp[i][j+1] = arr[i][j];
		}

		atmp[i][index] = rand() % 10;
	}

	for (int i = 0; i < rows; i++) {
		delete[]arr[i];
	}

	delete[] arr;

	arr = atmp;
	colums++;
}

void  SmartArray2::delindex(int const index) {

	int **atmp = new int*[rows - 1];

	for (int i = 0; i < rows - 1; i++) {
		atmp[i] = new int[colums];
	}

	//Заповнення до
	for (int i = 0; i < index; i++) {
		for (int j = 0; j < colums; j++) {
			atmp[i][j] = arr[i][j];
		}
	}

	//Заповнення після
	for (int i = index; i < rows - 1; i++) {
		for (int j = 0; j < colums; j++) {
			atmp[i][j] = arr[i+1][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		delete[]arr[i];
	}

	delete[] arr;

	arr = atmp;
	rows--;
}

void SmartArray2::delindexcol(int const index) {

	int **atmp = new int*[rows];

	for (int i = 0; i < rows; i++) {
		atmp[i] = new int[colums - 1];
	}

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < index; j++) {
			atmp[i][j] = arr[i][j];
		}
		for (int j = index; j < colums; j++) {
			atmp[i][j] = arr[i][j + 1];
		}
	}

	for (int i = 0; i < rows; i++) {
		delete[]arr[i];
	}

	delete[] arr;

	arr = atmp;
	colums--;
}


SmartArray2::~SmartArray2()
{

	for (int i = 0; i < rows; i++) {
		delete[]arr[i];
	}

	delete[] arr;
}
