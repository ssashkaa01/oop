#pragma once
class SmartArray2
{
private:
	int **arr;
	int rows;
	int colums;

public:
	SmartArray2(int, int);

	void fill();

	void print();
	
	int min();

	int max();

	void addtoindex(int const);

	void addtoindexcol(int const);

	void delindex(int const);

	void delindexcol(int const);

	~SmartArray2();
};

