#include <string>
#include <iostream>

using namespace std;

class Proccesor
{
public:
	virtual void Show() = 0;
};

class Memory
{
public:
	virtual void Show() = 0;
};

class Hdd
{
public:
	virtual void Show() = 0;
};

class AmdProccesor : public Proccesor
{
public:
	void Show()
	{
		cout << "AMD 3.0" << endl;
	}
};

class IntelProccesor : public Proccesor
{
public:
	void Show()
	{
		cout << "Intel i9 5.0 9Gen" << endl;
	}
};

class Memory8GB : public Memory
{
public:
	void Show()
	{
		cout << "8 GB Memory" << endl;
	}
};

class Memory24GB : public Memory
{
public:
	void Show()
	{
		cout << "24 GB Memory" << endl;
	}
};

class Hdd2TB : public Hdd
{
public:
	void Show()
	{
		cout << "2 TB HDD" << endl;
	}
};

class Hdd500GB : public Hdd
{
public:
	void Show()
	{
		cout << "500GB HDD" << endl;
	}
};

class PCFactory
{
private:

	Proccesor *pr;
	Memory *mem;
	Hdd *hdd;

public:
	PCFactory()
	{

	}

	virtual Proccesor* CreateProccesor() = 0;

	virtual Memory* CreateMemory() = 0;

	virtual Hdd* CreateHdd() = 0;

	void SetProccessor(Proccesor *_pr)
	{
		pr = _pr;
	}

	void SetMemory(Memory *_mem)
	{
		mem = _mem;
	}

	void SetHdd(Hdd *_hdd)
	{
		hdd = _hdd;
	}

	void Show()
	{
		pr->Show();
		mem->Show();
		hdd->Show();
	}

};

class GamePCFactory : public PCFactory
{
private:

public:
	GamePCFactory() {

	}

	Proccesor *CreateProccesor() {
		return new IntelProccesor();
	}

	Memory *CreateMemory() {
		return new Memory24GB();
	}

	Hdd *CreateHdd() {
		return new Hdd2TB();
	}
};

class HomePCFactory : public PCFactory
{
private:

public:
	HomePCFactory() {

	}

	Proccesor *CreateProccesor() {
		return new AmdProccesor();
	}

	Memory *CreateMemory() {
		return new Memory8GB();
	}

	Hdd *CreateHdd() {
		return new Hdd500GB();
	}
};

int main()
{

	PCFactory *pc = new HomePCFactory();
	pc->SetHdd(pc->CreateHdd());
	pc->SetMemory(pc->CreateMemory());
	pc->SetProccessor(pc->CreateProccesor());
	pc->Show();

	system("pause");
	return 0;
}