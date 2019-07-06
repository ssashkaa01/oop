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

	virtual void Sound() {
		cout << "Sound..." << endl;
	}

	void Type() {
		cout << "Type: " << type << endl;
	}

	void Show() {
		cout << "Speed: " << speed << endl;
		cout << "Weight: " << weight << endl;
		cout << "Environment: " << environment << endl;
	}
};

class Dog : public Animal {

private:
	
public:
	Dog(string type, int speed, int weight, string environment) : Animal(type, speed, weight, environment) {}

	virtual void Sound() {
		cout << "GaV , GaV..." << endl;
	}

	void Show() {
		Animal::Show();
		Animal::Type();
	}
};

class Cat : public Animal {

private:

public:
	Cat(string type, int speed, int weight, string environment) : Animal(type, speed, weight, environment) {}

	virtual void Sound() {
		cout << "Myu..." << endl;
	}

	void Show() {
		Animal::Show();
		Animal::Type();
	}
};

class Parrot : public Animal {

private:

public:
	Parrot(string type, int speed, int weight, string environment) : Animal(type, speed, weight, environment) {}

	virtual void Sound() {
		cout << "Cir, Cir..." << endl;
	}

	void Show() {
		Animal::Show();
		Animal::Type();
	}
};

class Frog : public Animal {

private:

public:
	Frog(string type, int speed, int weight, string environment) : Animal(type, speed, weight, environment) {}

	virtual void Sound() {
		cout << "Hru-hru..." << endl;
	}

	void Show() {
		Animal::Show();
		Animal::Type();
	}
};

int main() {

	Dog Bars("Dog", 60, 35, "ground");

	Bars.Show();
	Bars.Sound();

	system("pause");
	return 0;
}