#include <iostream>
#include <string>

using namespace std;

class AirPlane
{
private:
	string model;
	string type;
	int countPeople;
	int maxCountPeople;

	friend bool operator==(AirPlane &ap1, AirPlane &ap2);
	friend bool operator>(AirPlane &ap1, AirPlane &ap2);

public:
	AirPlane() {
		model = "undefined";
		type = "undefined";
		countPeople = 0;
		maxCountPeople = 0;
	}
	AirPlane(string model, string type, int countPeople, int maxCountPeople) {
		this->model = model;
		this->type = type;
		this->countPeople = countPeople;
		this->maxCountPeople = maxCountPeople;
	}

	void operator()(int add) {
		if (this->maxCountPeople > this->countPeople)
			this->countPeople += add;
	}

	void operator++() {
		if (this->maxCountPeople > this->countPeople)
			++this->countPeople;
	}

	void operator--() {
		if (this->countPeople > 0)
			--this->countPeople;
	}

	void show() const {
		cout << endl << "Model: " << model << endl;
		cout << "Type: " << type << endl;
		cout << "Count People: " << countPeople << endl;
		cout << "Max Count People: " << maxCountPeople << endl;
	}

};

bool operator==(AirPlane &ap1, AirPlane &ap2) {

	return ap1.type == ap2.type;
}

bool operator>(AirPlane &ap1, AirPlane &ap2) {

	return ap1.maxCountPeople > ap2.maxCountPeople;
}

int main() {

	AirPlane ap1("AH-170", "mini", 45, 60);
	AirPlane ap2("AL-111", "Big", 200, 290);

	ap1.show();
	++ap1;
	ap1.show();
	if (ap1 == ap2) cout << "Airplanes has one type!" << endl;

	system("pause");
	return 0;
}