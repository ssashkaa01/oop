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
Розробити додаток, що імітує чергу друку принтера. 
Повинні бути клієнти, що посилають запити на принтер, у кожного з яких є свій пріоритет.
Кожен новий клієнт потрапляє в чергу в залежності від свого пріоритету. 
Необхідно зберігати статистику друку (користувач, час) в окремій черзі.
Передбачити показ статистики на екран.

Для вирішення даного завдання, використати динамічну структуру даних - черга з пріорітетами (пріорітетним ключенням)
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