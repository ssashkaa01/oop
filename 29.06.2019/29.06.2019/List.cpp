#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

void List::AddTail(int data)
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

void List::AddHead(int data)
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

void List::Add(int pos, int data)
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
		head->prev = nullptr;
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

bool List::searchNumber(int number)
{
	Element *temp = head;
	while (temp != nullptr) {

		if (temp->num == number) return true;

		temp = temp->next;
	}

	return false;
}

int List::searchNumberPosition(int number)
{
	Element *temp = head;
	int counter = 0;

	while (temp != nullptr) {

		counter++;

		if (temp->num == number) return counter;

		temp = temp->next;
	}

	return 0;
}

List List::sort()
{

	List *newList = new List();

	//����� ������
	Element *temp = head;
	int buf = 0;

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size - 1; j++) {

			if (temp->num > temp->next->num) {
				
				//newList->AddHead(temp->next->num);
				buf = temp->next->num;
				temp->next->num = temp->num;
				temp->num = buf;
			}

			temp = temp->next;

		}

		temp = this->head;
	}

	return *this;
}

List &List::operator=(List &newList)
{
	this->size = newList.size;
	this->head = newList.head;
	this->tail = newList.tail;
	
	return *this;
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
		cout << "Element: " << item->num << endl;
	}

	/*Element * current = head;
	while (current != nullptr)
	{
		cout << "Element: " << current->num << endl;
		current = current->next;
	}*/
}