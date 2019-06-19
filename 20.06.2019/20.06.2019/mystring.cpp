#include "mystring.h"
#include <iostream>

using namespace std;

mystring::mystring()
{
	len = 0;
	str = nullptr;
}

mystring::mystring(char a, int size)
{

	str = new char[size + 1];

	for (int i = 0; i < size; i++) {

		str[i] = a;

	}

	str[size] = '\0';

	reLen(str);
}

mystring::mystring(const mystring &mystr)
{

	cout << "copy" << endl;

	this->len = mystr.len;

	this->str = new char[len + 1];

	for (int i = 0; i < this->len; i++) {
		this->str[i] = mystr.str[i];
	}
	//strcpy_s(str, len + 1, mystr.str);
	this->str[this->len] = '\0';
}

mystring::mystring(mystring &&mystr)
{

	cout << "move" << endl;

	this->str = mystr.str;
	
	this->len = mystr.len;

	mystr.str = nullptr;
}

void mystring::SetString(const char *newStr) {

	if (str != nullptr) delete[] str;

	reLen(newStr);

	str = new char[len + 1];

	strcpy_s(str, len + 1, newStr);

}

void mystring::SetStringFromKeyboard() {

	char newStr[255];

	cout << "Please enter string:" << endl;
	cin.getline(newStr, 255);

	if (str != nullptr) delete[] str;

	reLen(newStr);

	str = new char[len + 1];

	strcpy_s(str, len + 1, newStr);

}
void mystring::showString() {

	if (str == nullptr) return;

	cout << str << endl;
}

void mystring::reLen(const char *strr) {

	len = strlen(strr);

}

void mystring::clearString() {

	if (str != nullptr) delete[] str;

}
void mystring::append(const char *newStr) {

	int c_str = strlen(str);
	int c_newStr = strlen(newStr);

	char *newstr = new char[c_str + c_newStr + 1];

	strcpy_s(newstr, c_str + 1, str);

	if (str != nullptr) delete[] str;

	strcat_s(newstr, c_str + c_newStr + 1, newStr);

	reLen(newStr);

	str = newstr;
}

int mystring::getLength() {

	return len;

}

mystring::~mystring()
{

	if (str != nullptr) delete[] str;
}

mystring mystring::operator=(mystring& const s)
{

	
	SetString(s.str);
	reLen(s.str);

	return *this;
}
void mystring::operator+(mystring& const s)
{
	this->append(s.str);
}