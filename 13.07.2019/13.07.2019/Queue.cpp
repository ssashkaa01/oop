#include "Queue.h"
#include <iostream>

using namespace QueueSpace;

Queue::Queue(int maxSize)
{
	// Отримуємо максимальний розмір черги
	this->maxSize = maxSize;
	// Створюємо черу
	data = new int[maxSize];
	// На початку черга порожня
	size = 0;
}

Queue::~Queue()
{
	// Видалення черги
	delete[]data;
}

void Queue::Add(int elem)
{
	// Якщо черга має місце,
	// тоді добавляємо новий елемент
	// і змільшуємо розмір черги
	if (!IsFull())
		data[size++] = elem;
}

int Queue::Extract()
{
	// Якщо черга не порожня, тоді повертаємо
	// той, який прийшов перший і "підсовуємо" чергу
	if (!IsEmpty())
	{
		// Зберігаємо перший елемент
		int first = data[0];
		// Підсовуємо всі елементи
		for (int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}

		// Проста черга
		//--size;					// зменшуємо розмір черги

		// Кільцева черга
		data[size - 1] = first;	// переносимо перший елемент вкінець
								// не змінюючи розмір черги

		return first; // повертаємо збережений елемент
	}
}

bool Queue::IsEmpty() const
{
	// Порожня?
	return size == 0;
}

bool Queue::IsFull() const
{
	// Максимально заповнена?
	return size == maxSize;
}

int Queue::GetCount() const
{
	// Розмір черги
	return size;
}

void Queue::Clear()
{
	// Очистка черги
	size = 0;
}

void Queue::Show() const
{
	std::cout << "\n-----------------------------------\n";
	// Показ черги
	for (int i = 0; i < maxSize; i++)
		std::cout << data[i] << " ";
	std::cout << "\n-----------------------------------\n";
}
