#include <iostream>
#include "List.h"
#include <ctime>

using namespace std;

/*�������� ������� ��� "��������� ������".
���������, ��� ��������� ������ �Enter� ���������� �����������
����� �������� (������� �������� ������� � ��� ���������� ���������), �� ���� �������� ��� ������
� ���� ������ ����� ���������, �� ������� ������ ������ ������.

�������� ���� �������� � ������������� Queue (������� ��������� ����� - �����)
*/
int main() {

	srand(unsigned(time(NULL)));

	int count = 0;
	bool win = false;

	List list; // user comby
	List listWin; // win comby

	while (true) {

		list.clearAll();
		listWin.clearAll();

		system("cls");

		system("pause");

		//start
		win = false;

		//gen win comby
		for (int i = 0; i < 3; i++) {

			listWin.AddHead(rand() % 8 + 1);

		}

		count = rand() % 8 + 3;

		for (int i = 0; i < count; i++) {

			if (list.getSize() == 3) {

				cout << "INFO: " << endl;
				cout << "Your Comby: "; list.ShowComby(); cout << endl;
				cout << "Win Comby: "; listWin.ShowComby(); cout << endl;
				
				//Check comby
				if (list == listWin) {

					cout << "YOU WIN!" << endl;
				}

				list.DeleteTail();
				system("pause");
			}

			list.AddHead(rand() % 8 + 1);
		}
	}


	system("pause");
	return 0;
}