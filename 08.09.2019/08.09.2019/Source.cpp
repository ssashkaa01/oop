#include <iostream>
#include <ctime>

using namespace std;

class Strategy
{
private:
	int v1, v2; 
	int a1, a2;
	int counter;
	int user;

public:

	Strategy()
	{
		user = 0;
		GenerateGate();
		UpdateCounter();
		GenerateActions();
	}

	int *GetAllData()
	{
		int *data = new int[6];

		data[0] = v1;
		data[1] = v2;
		data[2] = a1;
		data[3] = a2;
		data[4] = counter;
		data[5] = user;

		return data;
	}

	void InsertAllData(int *data)
	{
		v1 = data[0];
		v2 = data[1];
		a1 = data[2];
		a2 = data[3];
		counter = data[4];
		user = data[5];
	}

	void GenerateGate()
	{
		v1 = rand() % 20 + 1;
		v2 = v1 + 3;
	}

	void UpdateCounter()
	{
		counter = 5;
	}

	void MinusCounter()
	{
		counter--;
	}

	int GetCounter()
	{
		return counter;
	}

	int GetUserPos()
	{
		return user;
	}

	void GenerateActions()
	{
		if (counter == 1)
		{
			a1 = (user - v1 - 1)*-1;
		}
		else
		{
			a1 = (rand() % 20 - (v2 + 1)) + 3;
		}

		a2 = rand() % (v1 + v2) + 2;
	}

	bool CheckGameOver()
	{
		if (counter <= 0)
		{
			if (user > v1 && user < v2)
			{
				GenerateGate();
				UpdateCounter();
				GenerateActions();
				return false;
			}
			else return true;
			
		}
		else
			return false;
	}

	void ViewAction()
	{
		cout << "User " << user << endl;
		cout << "v1 " << v1 << endl;
		cout << "v2 " << v2 << endl;
		cout << "1 - action " << a1 << endl;
		cout << "2 - action " << a2 << endl;
	}

	void DoAction(int action)
	{
		switch (action)
		{
		case 1:
			user += a1;
			break;
		case 2:
			user += a2;
			break;
		}
		MinusCounter();
		GenerateActions();
	}
};

class Memento
{
private:
	int *data;
public:

	int *GetAllData()
	{
		return data;
	}

	void InsertAllData(int *data)
	{
		this->data = data;
	}

};


int main()
{
	srand(time(NULL));

	Strategy s;
	Memento m;
	int action;

	while (!s.CheckGameOver())
	{
		s.ViewAction();

		cin >> action;

		switch (action)
		{
		case 1: 
			s.DoAction(1);
			break;
		case 2:
			s.DoAction(2);
			break;
		case 3:
			cout << "Your Data Was Saved!" << endl;
			m.InsertAllData(s.GetAllData());
			break;	
		case 4:
			cout << "Your Data Was Restore!" << endl;
			s.InsertAllData(m.GetAllData());
			break;
		default:
			break;
		}
	}

	cout << "Game Over!" << endl;

	system("pause");
	return 0;
}