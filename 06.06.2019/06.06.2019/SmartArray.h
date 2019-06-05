#pragma once
using namespace std;

class SmartArray
{
private:

	int size;
	int *arr;

public:

	SmartArray();
	SmartArray(const int _size, int _numb);
	SmartArray(int _size, int *_array);

	void addElem(int _numb);
	void delElem(int _index);
	void print() const;
	void clear();

	~SmartArray();
};

