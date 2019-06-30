#include "Tree.h"
#include <iostream>
using namespace std;

void main()
{
	/*
	��������.
���������� ���� ����� ��� �� �������� ���������� �� ��������� �������� ������.
������ ��������� ����� ����������, ��������� ����� - ������ �������������. ���� ��������� �������� � ������ ���,
�� � ����� �'��������� ����� �����, �� ������ "��� ��� ��������������" ���� �������� ���������, ���� �, �� ��� ���������� � �������� ������.

��������� ����� ���������� ������� ��������:
 - ����� ���������� ���� ����� (�� �������� ����� � ������ �������������, �� ��������� �� ����);
 - ���������� ����� �� �������� ������;
 - ���������� ����� �� ��������� ������.
	*/
	Tree tree;

	//ADD NUMBERS TO DATABASE
	tree.Add("AB3435BB");
	tree.Add("BK3266OO");
	tree.Add("AB5430BR");

	//ADD OFFENSE
	tree.AddOffense("BK3266OO", "Very big speed");

	//PRINT DATA
	tree.PrintData("BK3266OO");

	//PRINT ALL DATABASE
	tree.PrintSort();
	
	//PRINT DIAPAZON
	tree.PrintSortDiapazon("AB");

	system("pause");
}