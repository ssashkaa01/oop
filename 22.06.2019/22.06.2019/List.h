#pragma once

// Двузв'язний список
class List
{
private:
	// Опис елемента
	struct Element
	{
		int num;		// дані
		Element * next;	// зв'язок з наступним елементом
		Element * prev;	// зв'язок з попереднім елементом
	};

	Element * head;		// голова списка (перший елемент)
	Element * tail;		// хвіст списка (останній елемент)

	int size;

public:
	// Конструктор по замовчуванню
	List()
	{
		// На початку список порожній,
		// тобто першого елемента не існує
		head = tail = nullptr;
		size = 0;
	}

	List(List & newList) {
		this->size = newList.size;
		this->head = newList.head;
		this->tail = newList.tail;
	}

	bool IsEmpty() const { return size == 0; }

	// Добавлення елемента вкінець списку
	void AddTail(int data);
	// Добавлення елемента на початок списку
	void AddHead(int data);

	// Добавлення елемента в позицію
	void Add(int pos, int data);

	// Видалення голови (першого елемента)
	void DeleteHead();

	void DeleteTail();

	void DeleteFromIndex(int);

	bool searchNumber(int);

	int searchNumberPosition(int);

	List sort(bool);

	List &operator=(const List &);
	List &operator=(List &&);

	bool operator==(const List &);

	// Показ всіх елементів
	void ShowList() const;

	void clearAll();

	int getSize() const;

	void ShowComby() const;
};