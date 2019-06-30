#include "List.h"
#include <iostream>
#include <string>

using namespace std;

void List::AddTail(string data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->next = nullptr;
	newElement->prev = nullptr;

	if (head == nullptr)
		head = tail = newElement;
	else
	{
		tail->next = newElement;
		newElement->prev = tail;
		tail = newElement;
	}
	++size;
}

void List::AddHead(string data)
{
	Element * newElement = new Element;
	newElement->num = data;
	newElement->prev = nullptr;
	newElement->next = nullptr;

	if (head == nullptr)
		head = tail = newElement;
	else
	{
		newElement->next = head;
		head->prev = newElement;
		head = newElement;
	}
	++size;
}

void List::Add(int pos, string data)
{
	if (pos > size + 1 || pos <= 0)
		return;

	if (pos == 1)
	{
		AddHead(data);
		return;
	}
	if (pos == size + 1)
	{
		AddTail(data);
		return;
	}

	Element * newElem = new Element;
	newElem->num = data;

	Element * temp = head;
	/*int counter = 0;
	while (temp != nullptr && counter != pos - 2)
	{
		temp = temp->next;
		++counter;
	}*/

	for (int p = 1; p != pos; ++p)
		temp = temp->next;

	newElem->next = temp;
	newElem->prev = temp->prev;
	temp->prev->next = newElem;
	temp->prev = newElem;

	++size;
}

void List::DeleteHead()
{
	if (!IsEmpty())
	{
		Element * temp = head;
		head = head->next;
		//head->prev = nullptr;
		delete temp;

		if (head == nullptr)
			tail = nullptr;

		--size;
	}
}

void List::DeleteTail()
{
	if (!IsEmpty())
	{
		Element * temp = tail;

		tail = temp->prev;
		tail->next = nullptr;
		delete temp;
		--size;
	}
}

void List::DeleteFromIndex(int index) {


	if (!IsEmpty())
	{
		if (index > size - 1 || index < 0)
			return;

		if (index == 0)
		{
			DeleteHead();
			return;
		}
		if (index == size - 1)
		{
			DeleteTail();
			return;
		}

		Element * temp = head;

		for (int i = 0; i < index; i++) {

			if (temp == nullptr)
				return;

			temp = temp->next;
		}

		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;

		size--;
	}
}

List &List::operator=(const List &newList)
{

	// copy
	cout << "copy" << endl;
	Element *temp = head;

	while (temp != nullptr) {

		temp = temp->next;
		delete[] temp->prev;
	}

	temp = newList.head;

	while (temp != nullptr) {

		this->AddTail(temp->num);
		temp = temp->next;

	}

	return *this;
}

List &List::operator=(List &&newList)
{
	cout << "move" << endl;
	this->size = newList.size;
	this->head = newList.head;
	this->tail = newList.tail;

	newList.size = 0;
	newList.head = nullptr;
	newList.tail = nullptr;

	return *this;
}

bool List::operator==(const List &list)
{

	Element *temp1 = this->head;
	Element *temp2 = list.head;

	while (temp1 != nullptr) {

		if (temp2 == nullptr)
			return false;

		if (temp1->num != temp2->num)
			return false;

		temp1 = temp1->next;
		temp2 = temp2->next;

	}

	if ((temp1 == nullptr && temp2 != nullptr) || (temp1 != nullptr && temp2 == nullptr))
		return false;

	return true;
}

void List::ShowList() const
{
	if (IsEmpty())
	{
		cout << "List is empty!\n";
		return;
	}

	/*Element * current = head;
	do
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	} while (current->next != nullptr);*/

	for (Element * item = head; item != nullptr; item = item->next)
	{
		cout << "Offense: " << item->num << endl;
	}

	/*Element * current = head;
	while (current != nullptr)
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	}*/
}

void List::clearAll()
{
	if (!IsEmpty())
	{
		for (Element * item = head; item != nullptr; item = item->next)
		{
			if (item != head) {
				delete item->prev;
			}
		}

		head = nullptr;

		if (tail != nullptr) {
			delete tail;
			tail = nullptr;
		}

		size = 0;
	}
}

int List::getSize() const
{
	return this->size;
}

List::~List()
{
	this->clearAll();
}