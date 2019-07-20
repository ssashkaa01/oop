#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Time
{
	int h, m;

	void Show() const {
		cout << h << "H " << m << "m" << endl;
	}

	bool operator > (const Time& other) {

		if (h == other.h) {
			return m > other.m;
		}
		else {
			return h > other.h;
		}
	}
};

class Train {

private:

	int number;
	Time time;
	string station;

public:

	Train(int number, Time time, string station) : number(number), time(time), station(station)
	{

	}

	Train() {}

	void Show() const {
		cout << "Number: " << number << endl;
		cout << "Time: "; time.Show();
		cout << "Station: " << station << endl;
		cout << "- - - - - - - - - - - - - - - - -" << endl;
	}

	int GetNumber() const {
		return number;
	}

	void SetNewTime(Time &newtime) {
		time = newtime;
	}

	void SetNumber(int number) {
		this->number = number;
	}

	void SetNumber(string station) {
		this->station = station;
	}

	string GetStation() const {
		return station;
	}

	Time GetTime() const {
		return time;
	}
};

class RailWay {

private:

	vector<Train> trains;

public:
	RailWay() {

	}

	void Addtrain(Train &train) {
		trains.push_back(train);
	}

	void ShowAll() const {

		for (Train item : trains) {
			item.Show();
		}
	}

	void SortTime() {
		sort(trains.begin(), trains.end(), [](Train const& a, Train const& b) { return !(a.GetTime() > b.GetTime()); });
	}

	void ShowStation(string station) const {

		for (Train item : trains) {
			if (item.GetStation() == station) {
				item.Show();
			}
			
		}

	}

	void ShowTrain(int number) const {

		for (Train item : trains) {
			if (item.GetNumber() == number) {
				item.Show();
				return;
			}
		}

		cout << "Train not faund!" << endl;
	}

	void SetNewTime(int number, Time &newtime) {

		for (Train& item : trains) {
			if (item.GetNumber() == number)
			{
				item.SetNewTime(newtime);
				return;
			}

		}

		cout << "Train not found!" << endl;
	}

	friend ofstream operator<<(ofstream &, RailWay &);
	friend ifstream& operator>> (ifstream &, RailWay &);
};

ofstream operator<<(ofstream &out, RailWay &way)
{

	for (vector<Train>::iterator i = way.trains.begin(); i != way.trains.end(); ++i) {
		out << i->GetNumber() << "\n" << i->GetTime().h << "\n" << i->GetTime().m<< "\n" << i->GetStation() << "\n";
	}

	return ofstream();
}

ifstream &operator>>(ifstream & in, RailWay & way)
{

	string data;
	Train train;
	Time time;
	int counter = 1;

	while (!in.eof()) {

		getline(in, data);

		switch (counter)
		{
		case 1:
			train.SetNumber(atoi(data.c_str()));
			counter++;
			break;
		case 2:
			time.h = atoi(data.c_str());
			counter++;
			break;
		case 3:
			time.m = atoi(data.c_str());
			counter++;
			break;
		case 4:
			train.SetNumber(data);
			counter++;
			break;
		case 5:
			train.SetNewTime(time);
			counter = 2;
			way.Addtrain(train);
			train.SetNumber(atoi(data.c_str()));
			break;
		default:
			return in;
			break;
		}
	}

	return in;
}

int main() {

	/*
	■ Записати список в файл;
	■ Зчитати список з файлу.

	*/

	Train t1(1, { 20,25 }, "Kiew");
	Train t2(2, { 16,20 }, "Warshawa");
	Train t3(3, { 18,10 }, "Kiew");

	RailWay way;

	//way.Addtrain(t1);
	//way.Addtrain(t2);
	//way.Addtrain(t3);

	//way.ShowStation("Kiew");

	//way.ShowAll();
	//cout << endl << endl;
	//way.SortTime();
	//way.ShowAll();
	//Time t = { 11,50 };

	//way.SetNewTime(1, t);
	//way.ShowTrain(1);

	// write file

	/*ofstream ofile; 
	ofile.open("data.txt", ios::out);
	ofile << way;
	ofile.close();*/

	// read file

	/*ifstream ifile; 
	ifile.open("data.txt", ios::in);
	ifile >> way;
	ifile.close();

	way.ShowAll();*/

	system("pause");
	return 0;
}