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

	this->len = mystr.len;

	this->str = new char[len + 1];

	strcpy_s(str, len + 1, mystr.str);
}

void mystring::SetString(char *newStr) {

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

	cout << str << endl;
}

void mystring::reLen(char *strr) {

	len = strlen(strr);

}

void mystring::clearString() {

	if (str != nullptr) delete[] str;

}
void mystring::append(char *newStr) {

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
