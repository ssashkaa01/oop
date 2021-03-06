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

	mystring news;

	news.SetString(s.str);
	news.reLen(s.str);

	return news;
}
void mystring::operator+(mystring& const s)
{
	this->append(s.str);
}
mystring mystring::operator*(mystring& const s)
{
	mystring news;

	news.len = 0;
	news.SetString("");

	//for (int i = 0; i < this->len; i++) 
	//{
	//	for(int j = 0; j < s.len; j++)
	//	{

	//		if (this->str[j] == s.str[i]) 
	//		{
	//			
	//			++news.len;

	//			char *tmp = new char[news.len];
	//			
	//			strcpy_s(s.str, news.len + 1, tmp);

	//			//tmp[news.len-1] = s.str[i];
	//			cout << tmp << endl;
	//			//delete[] news.str;

	//			//*news.str = *tmp;
	//			//news.append(&this->str[i]);
	//		}
	//	}
	//}

	
	return news;
}