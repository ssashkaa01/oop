#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Database
{
private:

	const string connectionString = "database.txt";
	bool connected;
	fstream fs;

public:

	Database()
	{
		this->fs.open(connectionString, ios::out | ios::in);

		if (this->fs.is_open())
		{
			this->connected = true;
		}
		else
		{
			this->connected = false;
		}
	}

	bool IsConnected() const
	{
		return this->connected;
	}

	void Log(string data)
	{
		this->fs << data << endl;
	}
	~Database()
	{
		fs.close();
	}
};

class ProxyDatabase 
{
private:
	Database *db;
	const string connectionString = "DatabaseProxy.txt";
	fstream fs;

public:

	ProxyDatabase(Database *db)
	{
		this->db = db;
		this->fs.open(connectionString, ios::out | ios::in | ios::app);
	}

	void Log(string data)
	{
		if (this->db->IsConnected())
		{
			this->db->Log(data);
			cout << "Connected to Database!" << endl;
		}
		else
		{
			this->fs << data << endl;
			cout << "Connected failed to Database! Data saved in temp file!" << endl;
		}
	}
};

int main()
{
	Database *db = new Database();
	ProxyDatabase *proxydb = new ProxyDatabase(db);

	proxydb->Log("Hello!");

	system("pause");
	return 0;
}