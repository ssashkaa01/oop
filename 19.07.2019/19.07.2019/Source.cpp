#include <iostream>

using namespace std;

template <class T>
class my_unique_ptr
{
private:
	T *ptr;

public:
	my_unique_ptr(T *ptr) : ptr(ptr) {

	}
	~my_unique_ptr() {
		delete ptr;
	}

	T* release() {
		T *tmp = ptr;
		ptr = nullptr;
		return tmp;
	}

	T get() {
		return *ptr;
	}

	T operator * () const
	{
		return *ptr;
	}

	void swap(my_unique_ptr& other) {
		T *tmp = ptr;
		ptr = other.get();
		other.ptr = tmp;
	}

	explicit operator bool() const {
		if (ptr != nullptr) {
			return true;
		}
		else return false;
	}

	T &operator=(unique_ptr <T>&&other) {
		if (other.ptr != nullptr) {

			if (this->ptr != nullptr) {
				delete this->ptr;
			}
			this->ptr = other.ptr;
			other.ptr = nullptr;

		}
		return *this;
	}
	
	my_unique_ptr<T> *operator->() {
		return *ptr;
	}
};


int main() {

	/*
	������� ��� ����� ����� �������� ���������.
	���� � ����� ������� ����������� ��������������� ������������ ����� unique_ptr, � ����� - shared_ptr.
	�������� ��� �� ���������� ����� �����.

	����'������ ������� ���������� ��������� ����������:

	������������ (��������������, �� ������������)
	����������
	��������� �������������� (* ->)
	�������������� ��������� ���������� ���� �� bool (������� true, ���� ��'��� ����䳺 �������)
	�������������� ��������� ��������� (=)

	�� ������ (��� unique_ptr �� shared_ptr �� ������ ���� �����������), ��� ���� � ���:
	Get - ������� ������ ���� ����䳺 ��'���
	Release - ����� ������� ������, ������� �������� ��� � ����
	Reset - ������ ���� ������ �� �������������� �������� �� ��, �������� ������ �� �������� �� ������������, ��� ���������� ���� ������ � 0
	Swap - ������ ����� � ��'��� � ������ ������ �� �� ���� ��������
	*/

	my_unique_ptr<int> ukaz(new int(4));
	my_unique_ptr<int> ukaz2(new int(5));

	//ukaz2.swap(ukaz);
	//(&ukaz)->get();
	ukaz->get();
	//cout << *(ukaz.get()) << endl;
	//cout << *(ukaz.get()) << endl;

	my_unique_ptr<int> ukaz3 = ukaz.release();

	if (ukaz) {
		cout << "isset" << endl;
	}
	else {
		cout << "not isset" << endl;
	}

	system("pause");
	return 0;
}