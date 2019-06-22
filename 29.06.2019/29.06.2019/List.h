#pragma once

// �����'����� ������
class List
{
private:
	// ���� ��������
	struct Element
	{
		int num;		// ���
		Element * next;	// ��'���� � ��������� ���������
		Element * prev;	// ��'���� � ��������� ���������
	};

	Element * head;		// ������ ������ (������ �������)
	Element * tail;		// ���� ������ (������� �������)

	int size;

public:
	// ����������� �� ������������
	List()
	{
		// �� ������� ������ �������,
		// ����� ������� �������� �� ����
		head = tail = nullptr;
		size = 0;
	}

	List( List & newList ) {
		this->size = newList.size;
		this->head = newList.head;
		this->tail = newList.tail;
	}

	bool IsEmpty() const { return size == 0; }

	// ���������� �������� ������ ������
	void AddTail(int data);
	// ���������� �������� �� ������� ������
	void AddHead(int data);

	// ���������� �������� � �������
	void Add(int pos, int data);

	// ��������� ������ (������� ��������)
	void DeleteHead();

	void DeleteTail();

	void DeleteFromIndex(int);

	bool searchNumber(int);

	int searchNumberPosition(int);

	List sort(bool);

	List &operator=(const List &);
	List &operator=(List &&);

	// ����� ��� ��������
	void ShowList() const;
};