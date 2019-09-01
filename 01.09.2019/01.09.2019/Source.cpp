#include <iostream>

using namespace std;

class AutoTechnology
{
public:

	virtual void BuildBody() = 0;
	virtual void InstallEngine() = 0;
	virtual void InstallWheels() = 0;
	virtual void Paint() = 0;
	virtual void PrepareSalon() = 0;
};

class MiniAuto
{
public:
	void BuildBody()
	{
		cout << "Build mini body" << endl;
	}
	virtual void InstallEngine()
	{
		cout << "Install engine 1.2" << endl;
	}
	virtual void InstallWheels()
	{
		cout << "Install street wheels" << endl;
	}
	virtual void Paint()
	{
		cout << "Paint in white color" << endl;
	}
	virtual void PrepareSalon()
	{
		cout << "Prepare default salon" << endl;
	}
};

class SportsCar
{
public:
	void BuildBody()
	{
		cout << "Build sport body" << endl;
	}
	virtual void InstallEngine()
	{
		cout << "Install engine 3.0" << endl;
	}
	virtual void InstallWheels()
	{
		cout << "Install sport wheels" << endl;
	}
	virtual void Paint()
	{
		cout << "Paint in black color" << endl;
	}
	virtual void PrepareSalon()
	{
		cout << "Prepare sport salon" << endl;
	}
};

class SUVAuto
{
public:
	void BuildBody()
	{
		cout << "Build big body" << endl;
	}
	virtual void InstallEngine()
	{
		cout << "Install engine 5.2" << endl;
	}
	virtual void InstallWheels()
	{
		cout << "Install big wheels" << endl;
	}
	virtual void Paint()
	{
		cout << "Paint in green color" << endl;
	}
	virtual void PrepareSalon()
	{
		cout << "Prepare default salon" << endl;
	}
};

class Conveyor
{
private:
	MiniAuto technology;

public:

	void Build()
	{
		technology.BuildBody();
		technology.InstallEngine();
		technology.InstallWheels();
		technology.Paint();
		technology.PrepareSalon();
	}
};

int main()
{
	Conveyor c;
	c.Build();

	system("pause");
	return 0;
}