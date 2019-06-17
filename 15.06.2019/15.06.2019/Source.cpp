#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class var
{

private:
	
	int i_data;
	double d_data;
	string s_data;
	string type;

	void setValue(string data)
	{
		this->s_data = data;
		this->type = "string";
	}

	void setValue(int data)
	{
		this->i_data = data;
		this->type = "int";
	}

	void setValue(double data)
	{
		this->d_data = data;
		this->type = "double";
	}

public:

	//Constructor default
	var() 
	{
		this->i_data = 0;
		this->d_data = 0;
		this->s_data = "";
		this->type = "undefined";
	}
	
	//Constructor
	template <typename T>
	var(T data)
	{
		this->setValue(data);
	}

	//Operator =
	template <typename T>
	void operator=(T data)
	{
		this->setValue(data);
	}

	//Operator +
	template <typename T>
	void operator+(T data)
	{
		if (this->type == "string")
		{
			cout << this->s_data << endl;
		}
		else if (this->type == "int")
		{
			cout << this->i_data << endl;
		}
		else if (this->type == "double")
		{
			cout << this->d_data << endl;
		}
	}

	//Show
	void show() {

		if (this->type == "string")
		{
			cout << this->s_data << endl;
		}
		else if (this->type == "int")
		{
			cout << this->i_data << endl;
		}
		else if (this->type == "double")
		{
			cout << this->d_data << endl;
		}
	}
};

int main() {

	var a = 10, b = "120", c;
	c = a + b;
	c.Show(); // Виведе 130

	
	
	system("pause");
	return 0;
}