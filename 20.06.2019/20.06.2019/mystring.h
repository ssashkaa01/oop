#pragma once
class mystring
{
private:
	char *str;
	int len;
public:
	mystring();
	mystring(const mystring &);
	mystring(mystring &&);
	mystring(char, int);
	void SetStringFromKeyboard();
	void SetString(const char *);
	void showString();
	void clearString();
	void append(const char *);
	int getLength();
	void reLen(const char *);

	mystring operator=(mystring& const);
	void operator+(mystring& const);
	
	~mystring();
};

