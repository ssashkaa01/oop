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

	void operator++() {
		if(this->maxCountPeople > this->countPeople) 
			++this->countPeople;
	}

	void operator--() {
		--this->countPeople;
	}

	void operator()(int add) {
		this->countPeople += add;
	}

	bool operator==(AirPlane &ap) const {

		return this->type == ap.type;
	}

	bool operator>(AirPlane &ap) const {

		return this->maxCountPeople > ap.maxCountPeople;
	}

	void show() const {
		cout << endl << "Model: " << model << endl;
		cout << "Type: " << type << endl;
		cout << "Count People: " << countPeople << endl;
		cout << "Max Count People: " << maxCountPeople << endl;
	}

};

int main() {

	AirPlane ap1("AH-170", "mini", 45, 60);
	AirPlane ap2("AL-111","Big",200,290);

	ap1.show();
	++ap1;
	ap1.show();
	if (ap1 == ap2) cout << "Airplanes has one type!" << endl;

	system("pause");
	return 0;
}