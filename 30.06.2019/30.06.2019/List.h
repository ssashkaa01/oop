#pragma once
#include <string>

using namespace std;

// Äâóçâ'ÿçíèé ñïèñîê
class List
{
private:
	// Îïèñ åëåìåíòà
	struct Element
	{
		string num;		// äàí³
		Element * next;	// çâ'ÿçîê ç íàñòóïíèì åëåìåíòîì
		Element * prev;	// çâ'ÿçîê ç ïîïåðåäí³ì åëåìåíòîì
	};

	Element * head;		// ãîëîâà ñïèñêà (ïåðøèé åëåìåíò)
	Element * tail;		// õâ³ñò ñïèñêà (îñòàíí³é åëåìåíò)

	int size;

public:
	// Êîíñòðóêòîð ïî çàìîâ÷óâàííþ
	List()
	{
		// Íà ïî÷àòêó ñïèñîê ïîðîæí³é,
		// òîáòî ïåðøîãî åëåìåíòà íå ³ñíóº
		head = tail = nullptr;
		size = 0;
	}

	List(List & newList) {
		this->size = newList.size;
		this->head = newList.head;
		this->tail = newList.tail;
	}

	bool IsEmpty() const { return size == 0; }

	// Äîáàâëåííÿ åëåìåíòà âê³íåöü ñïèñêó
	void AddTail(string data);
	// Äîáàâëåííÿ åëåìåíòà íà ïî÷àòîê ñïèñêó
	void AddHead(string data);

	// Äîáàâëåííÿ åëåìåíòà â ïîçèö³þ
	void Add(int pos, string data);

	// Âèäàëåííÿ ãîëîâè (ïåðøîãî åëåìåíòà)
	void DeleteHead();

	void DeleteTail();

	void DeleteFromIndex(int);

	List &operator=(const List &);
	List &operator=(List &&);

	bool operator==(const List &);

	// Ïîêàç âñ³õ åëåìåíò³â
	void ShowList() const;

	void clearAll();

	int getSize() const;

	~List();
};