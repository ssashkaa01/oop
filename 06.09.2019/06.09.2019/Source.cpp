#include <iostream>

using namespace std;

class RealCar
{
public:

	virtual void PressGasPedal()
	{
		cout << "Press Gas Pedal" << endl;
	}

	virtual void PressTormozPedal()
	{
		cout << "Press Tormoz Pedal" << endl;
	}

	virtual void PressLeft()
	{
		cout << "Press Left" << endl;
	}

	virtual void PressRight()
	{
		cout << "Left" << endl;
	}

	virtual void ChangeSpeed()
	{
		cout << "Change Speed" << endl;
	}

	virtual void ChangeLight()
	{
		cout << "Change light" << endl;
	}
};

class GameCar
{
public:

	void PressLeft()
	{
		cout << "Press Left" << endl;
	}

	void PressRight()
	{
		cout << "Left" << endl;
	}

	void PressUp()
	{
		cout << "Press Up" << endl;
	}

	void PressDown()
	{
		cout << "Press Down" << endl;
	}

	void PressC()
	{
		cout << "Press C" << endl;
	}
};

class Driver : public RealCar
{

private:

	GameCar &gc;

public:

	Driver(GameCar & _gc) : gc(_gc)
	{

	}

	void PressGasPedal()
	{
		gc.PressUp();
	}

	void PressTormozPedal()
	{
		gc.PressDown();
	}

	void ChangeLight()
	{
		gc.PressC();
	}

	void PressLeft()
	{
		gc.PressLeft();
	}

	void PressRight()
	{
		gc.PressRight();
	}
};


int main()
{
	GameCar gc;

	Driver ad(gc);

	ad.PressGasPedal();

	system("pause");
	return 0;
}