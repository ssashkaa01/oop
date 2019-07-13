#include "Queue.h"
#include <iostream>

using namespace QueueSpace;

Queue::Queue(int maxSize)
{
	// �������� ������������ ����� �����
	this->maxSize = maxSize;
	// ��������� ����
	data = new int[maxSize];
	// �� ������� ����� �������
	size = 0;
}

Queue::~Queue()
{
	// ��������� �����
	delete[]data;
}

void Queue::Add(int elem)
{
	// ���� ����� �� ����,
	// ��� ���������� ����� �������
	// � �������� ����� �����
	if (!IsFull())
		data[size++] = elem;
}

int Queue::Extract()
{
	// ���� ����� �� �������, ��� ���������
	// ���, ���� ������� ������ � "��������" �����
	if (!IsEmpty())
	{
		// �������� ������ �������
		int first = data[0];
		// ϳ������� �� ��������
		for (int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}

		// ������ �����
		//--size;					// �������� ����� �����

		// ʳ������ �����
		data[size - 1] = first;	// ���������� ������ ������� ������
								// �� ������� ����� �����

		return first; // ��������� ���������� �������
	}
}

bool Queue::IsEmpty() const
{
	// �������?
	return size == 0;
}

bool Queue::IsFull() const
{
	// ����������� ���������?
	return size == maxSize;
}

int Queue::GetCount() const
{
	// ����� �����
	return size;
}

void Queue::Clear()
{
	// ������� �����
	size = 0;
}

void Queue::Show() const
{
	std::cout << "\n-----------------------------------\n";
	// ����� �����
	for (int i = 0; i < maxSize; i++)
		std::cout << data[i] << " ";
	std::cout << "\n-----------------------------------\n";
}
