#include <iostream>
#include <array> // STL array
#include <ctime>

using namespace std;

class Spots
{
private:

	int action; // your action
	array <int, 16> place; // places 

public:

	Spots() {
		this->CreateMap();
	}

	// start game
	void Start() {

		while (!this->CheckWin()) {

			this->ShowPlaces();

			this->EnterDibToReplace();

			system("cls");
		}

		cout << "YOU WIN !" << endl;
	}

	// enter dib to replace
	void EnterDibToReplace() {
		
		cout << endl << endl << "\tPleace enter dib to replace:" << endl;
		cin >> action;
		
		// check action
		if (CheckDib(action)) {

			int futurePos = CheckDibToReplace(action);

			if (futurePos != -1) {
				ReplaceDib(action, futurePos);
			}
		}
	}

	// search position
	int SearchPosDib(int dib) const {

		for (int i = 0; i < 16; i++) {

			if (place[i] == dib) return i;
		}
	}

	// replace dib
	void ReplaceDib(int dib, int futurePos) {

		place[SearchPosDib(dib)] = 0;
		place[futurePos] = dib;
	}

	// check replace, return pos replace
	int CheckDibToReplace(int dib) {

		int pos = SearchPosDib(dib);
	
		if (this->CheckDiapazon(pos + 4)) {
			
			if (place[pos + 4] == 0) return (pos + 4);
		}
		
		if (this->CheckDiapazon(pos - 4)) {
			
			if (place[pos - 4] == 0) return (pos - 4);
		}

		if (this->CheckDiapazon(pos - 1)) {
			
			if (place[pos - 1] == 0 && (pos) % 4 != 0) return (pos - 1);
		}

		if (this->CheckDiapazon(pos + 1)) {
			
			if (place[pos + 1] == 0 && (pos + 1) % 4 != 0) return (pos + 1);

		}

		return -1;
	}

	// check dib diapazon
	bool CheckDib(int dib) const {

		return (dib > 0 && dib < 16);
	}

	// check dib diapazon
	bool CheckDiapazon(int pos) const {

		return (pos >= 0 && pos < 16);
	}

	// check win
	bool CheckWin() {

		if (place[0] == 0) {
			
			for (int i = 1; i < 16; i++) {

				if (place[i] != i) return false;
			}
		}
		else if (place[15] == 0) {
			
			for (int i = 0; i < 15; i++) {

				if (place[i] != i+1) return false;
			}
		}
		else return false;

		return true;
	}

	// create map
	void CreateMap() {

		// random fill places
		for (int i = 0; i < 15; i++) {
			
			place[i] = this->GenerateDib();
		}

		place[15] = 0;
	}

	// generation dib
	int GenerateDib() {

		int dib = 0;

		while (!this->DibIsUnique(dib)) {
			
			dib = (rand() % 15 + 1);
		}

		return dib;
	}

	// check dib unique
	bool DibIsUnique(int dib) const {

		for (int i = 0; i < 16; i++) {

			if (place[i] == dib || dib == 0) return false;

		}

		return true;
	}

	// show all dib
	void ShowPlaces() const {

		cout << "\n\t    Created by STORYM.PRO\n\n\t\t   Spots\n\n";

		for (int i = 0; i < 16; i++) {

			if (((i) % 4) == 0 || i == 0) cout << endl << "\t\t";

			if (place[i] > 0 && place[i] < 10) {
				cout << place[i] << "  ";
			}
			else if (place[i] == 0) {
				cout << "*  ";
			}
			else {
				cout << place[i] << " ";
			}
		}
	}
};

int main() {

	srand(time(NULL));

	/*
	19. Написати програму, що вирішує гру-головоломку «Гра в 15».
Початкове розміщення номерів — випадкове. Передбачити два режими
демонстрації рішення: безперервний (з деякою затримкою візуалізації) і
покроковий (по натисканню на будь-яку клавішу). У програмі використовувати
контейнерні класи STL.

	*/

	Spots game;
	game.Start();

	system("pause");
	return 0;
}