#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//#include <iostream>
//#include <string>
//#include <fstream>
//#include <math.h>
//using namespace std;
//
//
//int main()
//{
//
//	int numb = 9;
//	int sqr = sqrt(numb);
//
//	for (int i = 1; i <= sqr; i++) {
//
//	for (int j = 0; j < sqr; j++) {
//
//	cout << i+(j*sqr) << " ";
//	}
//	cout << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}




string getElement(string str, int endSpace) {

	string word;
	int startSpace = endSpace - 1;
	int countSpace = 0;

	for (int i = 0; i < str.length(); i++) {

		if (int(str[i]) != 32 && countSpace == endSpace) {

			word.push_back(str[i]);
		}
		else if (int(str[i]) == 32) {
			countSpace++;
		}
	}

	return word;
}

struct Player {

	string name;
	string surname;
	int age;
	int games;
	int points;
	double avgPointPerGame;
};

void showPlayer(const Player & Players) {

	cout << "Name:" << Players.name << endl
		<< "Surname:" << Players.surname << endl;
	cout << "Age:" << Players.age << endl;
	cout << "Games:" << Players.games << endl;
	cout << "Points:" << Players.points << endl;
	cout << "AvgPointPerGame:" << Players.avgPointPerGame << endl;
}

double AveragePoint(const Player& p)
{
	return (double)p.games / p.points;
}

Player CreatePlayer()
{
	Player p;
	cout << "Please enter name:" << endl;
	cin >> p.name;

	cout << "Please enter surname:" << endl;
	cin >> p.surname;

	cout << "Please enter age:" << endl;
	cin >> p.age;

	cout << "Please enter games:" << endl;
	cin >> p.games;

	cout << "Please enter points:" << endl;
	cin >> p.points;

	p.avgPointPerGame = AveragePoint(p); // обчислення середньої кількості

	return p;
}


void SaveInFile(const Player player[10], int i = 0)
{
	ofstream out("Players.txt", ios_base::out | ios::trunc);

	for (int j = 0; j < i; j++)
	{
		out << player[j].name << ' ';
		out << player[j].surname << ' ';
		out << player[j].age << ' ';
		out << player[j].games << ' ';
		out << player[j].points << ' ';
		out << player[j].avgPointPerGame << endl;
	}


	out.close();
}

void LoadFromFile(Player *p, int &i)
{

	ifstream in("Players.txt", ios_base::in);

	string s;

	while (!in.eof()) {

		getline(in, s);

		if (getElement(s, 0) == "") {
			return;
		}

		p[i].name = getElement(s, 0);
		p[i].surname = getElement(s, 1);
		p[i].age = atoi(getElement(s, 2).c_str());
		p[i].games = atoi(getElement(s, 3).c_str());
		p[i].points = atoi(getElement(s, 4).c_str());
		p[i].avgPointPerGame = atof(getElement(s, 5).c_str());

		++i;

	}

	in.close();

}

void add(Player *&arr, int &size, const Player &newPlayer) {

	const int newSize = size + 1;
	Player *newArray = new Player[newSize];

	for (int i = 0; i < size; i++) {

		newArray[i] = arr[i];
	}

	newArray[size] = newPlayer;

	delete[]arr;

	arr = newArray;

	size++;
}

void del(Player *arr, int &size, int &idx) {

	cout << idx << endl;
	system("pause");

	const int newSize = ((size - 1) < 0) ? 0 : size - 1;
	Player *newArray = new Player[newSize];

	for (int i = 0; i < idx; i++) {
		newArray[i] = arr[i];
	}

	for (int i = idx; i < newSize; i++) {
		newArray[i] = arr[i+1];
	}

	//delete[]arr;

	arr = newArray;

	size--;

}

int search(Player *arr, int &size, string name) {

	string str;

	for (int i = 0; i < size; i++) {

		str = arr[i].name + arr[i].surname;

		if (str.find(name) != string::npos)
		{
			return i;
		}
	}

	return -1;
}

int main()
{

	int i = 0;
	const int size = 10;
	Player p[size];
	bool menu = true;
	int action = 0;
	string name;
	int index;
	int tmp;

	LoadFromFile(p, i);

	while (menu) {

		cout << "0 - exit" << endl;
		cout << "1 - create User" << endl;
		cout << "2 - view all User" << endl;
		cout << "3 - save all players" << endl;
		cout << "4 - find player" << endl;
		cout << "5 - remove player" << endl;

		cin >> action;

		switch (action)
		{
		case 0:
			menu = false;
			break;
		case 1:
			p[i] = CreatePlayer();
			i++;
			break;
		case 2:
			for (int j = 0; j < i; j++)
			{
				showPlayer(p[j]);
			}
			break;
		case 3:

			SaveInFile(p, i);
			break;

		case 4:

			cout << "Please enter name or surname:" << endl;

			cin >> name;
			tmp = search(p, i, name);

			if (tmp >= 0) {
				showPlayer(p[tmp]);
			}
			else {
				cout << "Not faund" << endl;
			}

			break;

		case 5:

			cout << "Please enter name or surname:" << endl;

			cin >> name;
			tmp = search(p, i, name);

			if (tmp >= 0) {
				cout << "WILL DELETED" << endl;
				showPlayer(p[tmp]);
				del(p, i, tmp);
			}
			else {
				cout << "Not faund" << endl;
			}

			
			break;

		}
	}

	system("pause");

	return 0;
}
