#include <iostream>
#include <string>

using namespace std;

class Wheel
{
private:
	int diam;
	bool good;
public:

	Wheel(int diam = 0, bool good = true) {
		this->diam = diam;
		this->good = good;
	}

	void Show() const {
		cout << "-------------------------------------" << endl;
		cout << "WHEEL:" << endl;
		cout << "Diametr: " << this->diam << endl;
		cout << "Status: " << ((this->good) ? "good" : "bad") << endl;
		cout << "-------------------------------------" << endl;
	}
};

class Corps
{
private:
	string color;
	bool good;
public:

	Corps(string color, bool good = true) {
		this->color = color;
		this->good = good;
	}

	void Show() const {
		cout << "-------------------------------------" << endl;
		cout << "CORPS:" << endl;
		cout << "Color: " << this->color << endl;
		cout << "Status: " << ((this->good) ? "good" : "bad") << endl;
		cout << "-------------------------------------" << endl;
	}
};

class Engine
{
private:
	double capacity;
	bool good;
public:

	Engine(double capacity, bool good = true) {
		this->capacity = capacity;
		this->good = good;
	}

	void Show() const {
		cout << "-------------------------------------" << endl;
		cout << "ENGINE:" << endl;
		cout << "Capacity: " << this->capacity << endl;
		cout << "Status: " << ((this->good) ? "good" : "bad") << endl;
		cout << "-------------------------------------" << endl;
	}
};


class Driver {

private:
	string name;
	string surname;
	int age;
	int ageDrive;
public:
	Driver(string name, string surname, int age, int ageDrive) : name(name), surname(surname), age(age), ageDrive(ageDrive) {}

	void Show() const {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
		cout << "Age drive: " << ageDrive << endl;
	}
};


class Car {
private:
	Wheel *wheel;
	Corps *corps;
	Engine *engine;
	int countWheel;

	Driver* driver;


public:
	Car(Wheel *Wheel1, Corps *Corps1, Engine *Engine1) {
		this->wheel = Wheel1;
		this->corps = Corps1;
		this->engine = Engine1;
	}

	Car(int wheel0, int wheel1, bool whhel2, string corps1, bool corps2, double engine1, bool engine2) {

		wheel = new Wheel[wheel0];
		countWheel = wheel0;
		for (int i = 0; i < wheel0; i++) {
			wheel[i] = Wheel(wheel1, whhel2);
		}

		corps = new Corps(corps1, corps2);
		engine = new Engine(engine1, engine2);
	}

	Car(int wheel0, int wheel1, bool whhel2, string corps1, bool corps2, double engine1, bool engine2, Driver* driver) : driver(driver) {

		wheel = new Wheel[wheel0];
		countWheel = wheel0;
		for (int i = 0; i < wheel0; i++) {
			wheel[i] = Wheel(wheel1, whhel2);
		}

		corps = new Corps(corps1, corps2);
		engine = new Engine(engine1, engine2);
	}

	void AddDriver(Driver* driver){
		if (this->driver != nullptr) {
			delete this->driver;
		}
		this->driver = driver;
	}

	void Show() const {
		corps->Show();
		for (int i = 0; i < countWheel; i++) {
			wheel->Show();
		}
		engine->Show();

		if (driver != nullptr) {
			cout << "Driver: " << endl;
			driver->Show();
		}
		else {
			cout << "Driver not found!" << endl;
		}
	}
};



int main() {

	//Car car(new Wheel(16, false), new Corps("red", true), new Engine(1.7, true));
	Car car(4, 16, false, "red", true, 1.7, true);
	Driver *driver = new Driver("Andrey", "Rilly", 29, 3);
	car.AddDriver(driver);
	car.Show();

	system("pause");
	return 0;
}