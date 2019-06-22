#include <iostream>
#include "List.h"
#include <ctime>

using namespace std;

class  Printer 
{
private:
	List users;
	List prior;
	int printed;
public:

	Printer() : printed(0) {}

	void addRequest(int userPrior, int userID) 
	{

		int i = 0;

		while (true) {
			
			i++;

			if (prior.getNum(i) <= userPrior) {
				prior.Add(i, userPrior);
				users.Add(i, userID);
				return;
			}
		}
	}
	
	void startPrint() {

		while (prior.getSize() > 0) {

			cout << "Printed for user " << users.getNum(1) << " :: Prior " << prior.getNum(1) << endl;

			prior.DeleteHead();
			users.DeleteHead();

			printed++;
			//system("pause");
		}
	}

	void viewStat() const {

		cout << "Printed: " << printed << endl;
	}
};




/*
��������� �������, �� ���� ����� ����� ��������. 
������ ���� �볺���, �� ��������� ������ �� �������, � ������� � ���� � ��� ��������.
����� ����� �볺�� ��������� � ����� � ��������� �� ����� ���������. 
��������� �������� ���������� ����� (����������, ���) � ������ ����.
����������� ����� ���������� �� �����.

��� �������� ������ ��������, ����������� �������� ��������� ����� - ����� � ���������� (���������� ���������)
*/
int main() {

	Printer printer;

	printer.addRequest(1, 4);
	printer.addRequest(8, 3);
	printer.addRequest(3, 5);
	printer.addRequest(4, 8);

	printer.startPrint();
	printer.viewStat();
	
	system("pause");
	return 0;
}