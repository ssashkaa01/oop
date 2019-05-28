#include "SmartArray.h"
#include <iostream>
using namespace std;

SmartArray::SmartArray() {
	size = 0;
	arr = nullptr;
}

SmartArray::SmartArray(int _size, int _numb)
{

	size = _size;

	arr = new int[_size];


	for (int i = 0; i < _size; i++) {
		arr[i] = _numb;
	}
}

SmartArray::SmartArray(int _size, int *_array)
{

	arr = new int[_size];

	for (int i = 0; i < _size; i++) {
		arr[i] = _array[i];
	}

}

void SmartArray::addElem(int _numb) 
{

	int *newArr = new int[size+1];

	for (int i = 0; i < size+1; i++) {
		newArr[i] = arr[i];
	}

	newArr[size] = _numb;

	delete[] arr;
	arr = newArr;
	size++;
}

void SmartArray::delElem(int _index) 
{


	int *newArr = new int[size - 1];

	for (int i = 0; i < _index; i++) {
		newArr[i] = arr[i];
	}

	for (int i = _index+1; i < size; i++) {
		newArr[i-1] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	size--;

}

void SmartArray::print() const 
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

void SmartArray::clear()
{
	delete[] arr;
	arr = nullptr;
}

SmartArray::~SmartArray() {
	clear();
	cout << "Bye!" << endl;
}