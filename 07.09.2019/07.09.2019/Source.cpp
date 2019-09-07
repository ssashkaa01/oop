#include <iostream>
#include <string>

using namespace std;

class ObarivResort
{
private:

	bool pool;
	bool bar;
	bool restaurant;
	bool billiard;
	bool massage;
	int price;

public:

	ObarivResort(bool pool, bool bar, bool restaurant, bool billiard, bool massage)
	{
		price = 0;
		if (pool) GetPool();
		if (bar) GetBar();
		if (restaurant) GetRestaurant();
		if (billiard) GetBilliard();
		if (massage) GetMassage();
	}

	ObarivResort()
	{
		pool = false;
		bar = false;
		restaurant = false;
		billiard = false;
		massage = false;
		price = 0;
	}

	void GetPool()
	{
		pool = true;
		price += 200;
	}

	void ViewPool() const
	{
		cout << "+ Pool" << endl;
	}

	void GetBar()
	{
		bar = true;
		price += 500;
	}

	void ViewBar() const
	{
		cout << "+ Bar" << endl;
	}

	void GetRestaurant()
	{
		restaurant = true;
		price += 1200;
	}

	void ViewRestaurant() const
	{
		cout << "+ Restaurant" << endl;
	}

	void GetBilliard()
	{
		billiard = true;
		price += 300;
	}

	void ViewBilliard() const
	{
		cout << "+ Billiard" << endl;
	}

	void GetMassage()
	{
		massage = true;
		price += 400;
	}

	void ViewMassage() const
	{
		cout << "+ Massage" << endl;
	}

	void ViewServices() const
	{
		cout << "Your Services: " << endl;
		if (pool) ViewPool();
		if (bar) ViewBar();
		if (restaurant) ViewRestaurant();
		if (billiard) ViewBilliard();
		if (massage) ViewMassage();
		cout << "Price: " << GetPrice() << endl;

	}

	int GetPrice() const
	{
		return price;
	}

};

class ObarivResortFacade
{
private:

	ObarivResort obariv;

public:

	ObarivResortFacade(int CountPeople, int years, string sex, bool alco, bool bonus)
	{
		if (CountPeople < 3)
		{
			obariv.GetBilliard();
		}

		if (sex == "female")
		{
			obariv.GetMassage();
		}

		if (alco && years >= 18)
		{
			if (sex == "female")
			{
				obariv.GetRestaurant();
			}
			else
			{
				obariv.GetBar();
			}
		}

		if (bonus)
		{
			obariv.GetPool();
		}
	}

	void ViewServices() const
	{
		obariv.ViewServices();
	}

};

int main()
{

	ObarivResortFacade orf(10, 20, "male", false, true);

	orf.ViewServices();

	system("pause");

	return 0;
}