#pragma once

namespace QueueSpace {
	// ����� - �������� ��������� �����, �� ����������� ��
	// ���� ������������� ���� ��������, � ��� 䳺 �������
	// FIFO (First In First Out) ��� ������� ������� ������ ����
	class Queue
	{
		// �����
		int * data;
		// ������������ ����� �����
		int maxSize;
		// �������� ����� �����
		int size;

	public:
		// �����������
		Queue(int maxSize);
		// ����������
		~Queue();

		// ���������� �������� � �����
		void Add(int elem);
		// ��������� �������� � �����
		int Extract();
		// �������� �� ����� � ���������
		bool IsEmpty() const;
		// �������� �� ����� � �����
		bool IsFull() const;
		// ʳ������ �������� � ����
		int GetCount() const;
		// ������� �����
		void Clear();
		// ����� �������� � ����
		void Show() const;
	};
}