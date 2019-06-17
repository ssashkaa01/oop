#include <iostream>
#include <string>

using namespace std;

class var
{

private:
	
	int i_data;
	double d_data;
	string s_data;
	string type;

	template <typename T1, typename T2>
	friend var operator+(T1 data1, T2 data2);

	template <typename T1, typename T2>
	friend var operator-(T1 data1, T2 data2);
	
	template <typename T1, typename T2>
	friend var operator*(T1 data1, T2 data2);

	template <typename T1, typename T2>
	friend var operator/(T1 data1, T2 data2);

	template <typename T1, typename T2>
	friend var operator+=(T1 &data1, T2 data2);

	template <typename T1, typename T2>
	friend var operator-=(T1 &data1, T2 data2);

	template <typename T1, typename T2>
	friend var operator*=(T1 &data1, T2 data2);

	template <typename T1, typename T2>
	friend var operator/=(T1 &data1, T2 data2);

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

	bool operator>(var &data) {

		if (this->type == data.type) {

			if (data.type == "string")
			{
				return (this->s_data.size() > data.s_data.size());
			}
			else if (data.type == "int")
			{
				return (this->i_data > data.i_data);
			}
			else if (data.type == "double")
			{
				return (this->d_data > data.d_data);
			}

		}
		
		return false;
	}

	bool operator<(var &data) {

		if (this->type == data.type) {

			if (data.type == "string")
			{
				return (this->s_data.size() < data.s_data.size());
			}
			else if (data.type == "int")
			{
				return (this->i_data < data.i_data);
			}
			else if (data.type == "double")
			{
				return (this->d_data < data.d_data);
			}

		}

		return false;
	}

	bool operator>=(var &data) {

		if (this->type == data.type) {

			if (data.type == "string")
			{
				return (this->s_data.size() >= data.s_data.size());
			}
			else if (data.type == "int")
			{
				return (this->i_data >= data.i_data);
			}
			else if (data.type == "double")
			{
				return (this->d_data >= data.d_data);
			}

		}

		return false;
	}

	bool operator<=(var &data) {

		if (this->type == data.type) {

			if (data.type == "string")
			{
				return (this->s_data.size() <= data.s_data.size());
			}
			else if (data.type == "int")
			{
				return (this->i_data <= data.i_data);
			}
			else if (data.type == "double")
			{
				return (this->d_data <= data.d_data);
			}

		}

		return false;
	}

	bool operator==(var &data) {

		if (this->type == data.type) {

			if (data.type == "string")
			{

				if (this->s_data.size() == data.s_data.size()) {

					int len = this->s_data.size();

					for (int i = 0; i < len; i++) {

						if (this->s_data[i] != data.s_data[i]) {
							return false;
						}
					}

					return true;
				}
				else return false;
				
			}
			else if (data.type == "int")
			{
				return (this->i_data == data.i_data);
			}
			else if (data.type == "double")
			{
				return (this->d_data == data.d_data);
			}

		}

		return false;
	}

	bool operator!=(var &data) {

		if (this->type == data.type) {

			if (data.type == "string")
			{
				if (this->s_data.size() == data.s_data.size()) {

					int len = this->s_data.size();

					for (int i = 0; i < len; i++) {

						if (this->s_data[i] != data.s_data[i]) {
							return true;
						}
					}

					return false;
				}
				else return true;
			}
			else if (data.type == "int")
			{
				return (this->i_data != data.i_data);
			}
			else if (data.type == "double")
			{
				return (this->d_data != data.d_data);
			}

		}

		return false;
	}
};

template <typename T1, typename T2>
var operator+(T1 data1, T2 data2) {

	var res;

	if (data1.type == data2.type)
	{
		if (data1.type == "string")
		{
			res = data1.s_data + data2.s_data;
		}
		else if (data1.type == "int")
		{
			res = data1.i_data + data2.i_data;
		}
		else if (data1.type == "double")
		{
			res = data1.d_data + data2.d_data;
		}
		
	}
	else {

		if (data1.type == "string") {

			if (data2.type == "int")
			{
				string tmp = to_string(data2.i_data);
				res = data1.s_data + tmp;
			}
			else if (data2.type == "double")
			{
				string tmp = to_string(data2.d_data);
				res = data1.s_data + tmp;
			}
			
		}
		else {
			
			int i;
			int tmp = 0;

			if(sscanf_s(data2.s_data.c_str(), "%d", &i) == 1){
				tmp = stoi(data2.s_data);
			}
			
			if (data1.type == "int")
			{
				res = data1.i_data + tmp;
			}
			else if (data1.type == "double")
			{
				res = data1.d_data + tmp;
			}
		}
	}
	return res;
}

template <typename T1, typename T2>
var operator-(T1 data1, T2 data2) {
	
	var res;

	if (data1.type != "string")
	{
		
		int tmp = 0;

		if (data2.type == "string") {
			
			int i;
			if (sscanf_s(data2.s_data.c_str(), "%d", &i) == 1) {
				tmp = stoi(data2.s_data);
			}
			else {
				tmp = 0;
			}
		}
		else {
			if (data2.type == "int")
			{
				tmp = data2.i_data;
			}
			else if (data2.type == "double")
			{
				tmp = data2.d_data;
			}	
		}

		if (data1.type == "int")
		{
			res = data1.i_data - tmp;
		}
		else if (data1.type == "double")
		{
			res = data1.d_data - tmp;
		}
	}
	
	return res;
}

template <typename T1, typename T2>
var operator*(T1 data1, T2 data2) {

	var res;
	res.type = "string";

	if (data1.type == "string" && data2.type == "string")
	{
		int len1 = data1.s_data.size();
		int len2 = data2.s_data.size();

		bool notfound;

		for (int i = 0; i < len1; i++) {

			notfound = true;

			for (int j = 0; j < len2; j++) {

				if (data1.s_data[i] == data2.s_data[j]) {
					
					notfound = false;
					continue;
				}
				
			}
			if(!notfound)
				res.s_data += data1.s_data[i];
		}
	}

	return res;
}

template <typename T1, typename T2>
var operator/(T1 data1, T2 data2) {

	var res;
	res.type = "string";

	if (data1.type == "string" && data2.type == "string")
	{
		int len1 = data1.s_data.size();
		int len2 = data2.s_data.size();

		bool notfound;

		for (int i = 0; i < len1; i++) {

			notfound = false;

			for (int j = 0; j < len2; j++) {

				if (data1.s_data[i] == data2.s_data[j]) {
					
					notfound = true;
					continue;
				}
				
			}
			if(!notfound)
				res.s_data += data1.s_data[i];
		}
	}

	return res;
}

template <typename T1, typename T2>
var operator+=(T1 &data1, T2 data2) {
	
	return data1 = data1 + data2;
}

template <typename T1, typename T2>
var operator-=(T1 &data1, T2 data2) {

	return data1 = data1 - data2;
}

template <typename T1, typename T2>
var operator*=(T1 &data1, T2 data2) {

	return data1 = data1 * data2;
}

template <typename T1, typename T2>
var operator/=(T1 &data1, T2 data2) {

	return data1 = data1 / data2;
}



int main() {

	//Включено перевірку при конвертації String to int, по дефолту String = 0;
	//var a = 10, b = "dg12r0", c;
	//c = a - b;
	//c.show();

	//var a = 10, b = "120", c;
	//c = a + b;
	//c.show(); // Виведе 130

	//var a = 10, b = "120", c;
	//c = b + a;
	//c.show(); // Виведе "12010"

	//var a = "Microsoft", b = "Windows", c;
	//c = a / b;
	//c.show(); // Виведе "Mcrft"

	//var a = "Microsoft", b = "Windows", c;
	//c = a * b;
	//c.show(); // Виведе "ioso"

	//var a = 10, b = "120";
	//a += b;
	//a.show(); // Виведе 130

	//var a = "ab", b = "a";

	////Різниця String визначається по кількості символів
	//if (a > b) {
	//	cout << "a > b" << endl;
	//}
	//

	//var a = "a", b = "a";

	////Рівність String визначається по значенні символів
	//if (a == b) {
	//	cout << "a == b" << endl;
	//}
	
	//var a = "a", b = "da";

	////Рівність String визначається по значенні символів
	//if (a != b) {
	//	cout << "a != b" << endl;
	//}
	
	system("pause");
	return 0;
}
