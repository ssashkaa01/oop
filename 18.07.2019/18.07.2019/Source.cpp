#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

struct Company {
	string name;
	string owner;
	string phone;
	string address;
	string category;

	Company() {}

	Company(string name, string owner, string phone, string address, string category) : 
		name(name), owner(owner), phone(phone), address(address), category(category) {}

	void Show() const{
		cout << "Name: " << name << endl;
		cout << "Owner: " << owner << endl;
		cout << "Phone: " << phone << endl;
		cout << "Address: " << address << endl;
		cout << "Category: " << category << endl;
		cout << "- - - - - - - - - - - - - - - - - -" << endl;
	}
};

class Directory
{

	list<Company> directory;

public:

	Directory() {}

	void addCompany(Company &company) {
		this->directory.push_back(company);
	}

	void addCompany(string name, string owner, string phone, string address, string category) {

		Company tmp(name, owner, phone, address, category);
		this->directory.push_back(tmp);
	}

	void showAll() {

		for (list<Company>::iterator i = this->directory.begin(); i != this->directory.end(); ++i) {
			i->Show();
		}
	}

	void searchWithName(string name) {

		for (list<Company>::iterator i = this->directory.begin(); i != this->directory.end(); ++i) {
			if (i->name == name) {
				i->Show();
			}
		}
	}

	void searchWithOwner(string owner) {

		for (list<Company>::iterator i = this->directory.begin(); i != this->directory.end(); ++i) {
			if (i->owner == owner) {
				i->Show();
			}
		}
	}

	void searchWithPhone(string phone) {

		for (list<Company>::iterator i = this->directory.begin(); i != this->directory.end(); ++i) {
			if (i->phone == phone) {
				i->Show();
			}
		}
	}

	void searchWithCategory(string category) {
		for (list<Company>::iterator i = this->directory.begin(); i != this->directory.end(); ++i) {
			if (i->category == category) {
				i->Show();
			}
		}
	}

	friend ofstream operator<<(ofstream &, Directory &);
	friend ifstream& operator>> (ifstream &, Directory &);
};

ofstream operator<<(ofstream & out, Directory & dir)
{
	for (list<Company>::iterator i = dir.directory.begin(); i != dir.directory.end(); ++i) {	
		out << i->name << "\n" << i->owner << "\n" << i->phone << "\n" << i->address << "\n" << i->category << "\n";
	}
	
	return ofstream();
}


ifstream &operator>>(ifstream & in, Directory & dir)
{

	string data;
	Company tmp;
	int counter = 1;

	while (!in.eof()) {
		
		getline(in, data);

		switch (counter)
		{
		case 1:
			tmp.name = data;
			counter++;
			break;
		case 2:
			tmp.owner = data;
			counter++;
			break;
		case 3:
			tmp.phone = data;
			counter++;
			break;
		case 4:
			tmp.address = data;
			counter++;
			break;
		case 5:
			tmp.category = data;
			counter++;
			break;

		case 6:
			counter = 2;
			tmp.Show();
			dir.addCompany(tmp);
			tmp.name = data;
		default:
			return in;
		}
	}

	return in;
}


int main() {

	Directory directory;

	// add function

	//directory.addCompany("Flex", "Geigts", "92032333223", "New York", "Business");
	//directory.addCompany("Herts", "Oliver", "1133442222", "Chikago", "Fun");

	// main function

	//directory.showAll();

	// search function 

	//directory.searchWithName("Flex");
	//directory.searchWithOwner("Oliver");
	//directory.searchWithPhone(92032333223);
	//directory.searchWithCategory("Fun");

	// write file

	//ofstream ofile; 
	//ofile.open("data.txt", ios::out);
	//ofile << directory;
	//ofile.close();

	// read file

	//ifstream ifile; 
	//ifile.open("data.txt", ios::in);
	//ifile >> directory;
	//ifile.close();

	//directory.showAll();

	system("pause");
	return 0;
}

