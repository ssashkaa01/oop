#include <iostream>
#include <string>

using namespace std;

class Animal {

private:
	string type;
	int speed;
	int weight;
	string environment;
public:
	Animal(string type, int speed, int weight, string environment) :
		type(type), speed(speed), weight(weight), environment(environment) {}

	void Move() {
		cout << "Moving..." << endl;
	}

	void Show() {
		cout << "Type: " << type << endl;
		cout << "Speed: " << speed << endl;
		cout << "Weight: " << weight << endl;
		cout << "Environment: " << environment << endl;
	}
};

class Bird : public Animal {

private:
	string color;

public:
	Bird(string type, int speed, int weight, string environment, string color) : Animal(type, speed, weight, environment), color(color) {}

	virtual void Move() {
		cout << "Flying..." << endl;
	}

	virtual void Show() {
		Animal::Show();
		cout << "Color: " << color << endl;
	}
};

class Stork : public Bird {

private:
	const string name = "Stork";

public:
	Stork(string type, int speed, int weight, string environment, string color) : Bird(type, speed, weight, environment, color) {}

	virtual void Show() {
		cout << "Name: " << name << endl;
		Bird::Show();
	}
};

int main() {

	Stork stork("Bird", 40, 35, "airy", "white");

	stork.Show();

	system("pause");
	return 0;
}