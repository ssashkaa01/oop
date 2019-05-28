#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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

int main()
{

	int i = 0;
	const int size = 10;
	Player p[size];
	bool menu = true;
	int action = 0;

	LoadFromFile(p, i);

	while (menu) {

		cout << "0 - exit" << endl;
		cout << "1 - create User" << endl;
		cout << "2 - view all User" << endl;
		cout << "3 - save to file" << endl;

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

		}
	}

	system("pause");

	return 0;
}