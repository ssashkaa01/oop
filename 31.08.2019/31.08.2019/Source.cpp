#include <iostream>

using namespace std;

class Delivery
{

};

class EasyCar : public Delivery
{
public:
	EasyCar()
	{
		this->Print();
	}

	void Print()
	{
		cout << "It`s easy car" << endl;
	}
};

class HardCar : public Delivery
{
public:
	HardCar()
	{
		this->Print();
	}

	void Print()
	{
		cout << "It`s hard car" << endl;
	}
};

class AirPlane : public Delivery
{
public:
	AirPlane()
	{
		this->Print();
	}

	void Print()
	{
		cout << "It`s air plane" << endl;
	}
};

class Ship : public Delivery
{
public:
	Ship()
	{
		this->Print();
	}

	void Print()
	{
		cout << "It`s ship" << endl;
	}
};

class FeedBack : public Delivery
{
public:
	FeedBack()
	{
		this->Print();
	}

	void Print()
	{
		cout << "Back to user" << endl;
	}
};

class NovaPoshta
{
public:

	bool Check(int weight, int size)
	{
		return (weight <= 200 && size <= 4);
	}

	Delivery Get(int weight, int size, int distance)
	{
		if (!this->Check(weight, size))
		{
			cout << "Bad parcel!" << endl;
			return *new FeedBack();
		}

		if (distance >= 1000 && weight > 100)
		{
			return *new Ship();
		}
		else if (distance >= 1000)
		{
			return *new AirPlane();
		}
		else if (distance < 200 && size < 1)
		{
			return *new EasyCar();
		}
		else if (distance < 1000 && size < 3)
		{
			return *new EasyCar();
		}
		else if (distance <= 1500)
		{
			return *new HardCar();
		}

	}

};

int main()
{
	NovaPoshta np;

	// 10 - weight in kg
	// 3 - size in m2
	// 2000 - distance in km
	np.Get(10, 3, 2000);

	system("pause");
	return 0;
}