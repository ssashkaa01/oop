#pragma once
class mystring
{
private:
	char *str;
	int len;
public:
	mystring();
	mystring(const mystring &);
	mystring(char, int);
	void SetStringFromKeyboard();
	void SetString(char *);
	void showString();
	void clearString();
	void append(char *);
	int getLength();
	void reLen(char *);

	~mystring();
};

