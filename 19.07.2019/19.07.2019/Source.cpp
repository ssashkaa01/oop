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
	Створіть свої власні класи розумних вказівників.
	Один з класів повинен повторювати функціональність стандартного класу unique_ptr, а інший - shared_ptr.
	Напишіть код по тестуванню ваших класів.

	Обов'язково потрібно реалізувати наступний функціонал:

	Конструктори (параметризовані, по замовчуванню)
	Деструктор
	Оператори розіменовування (* ->)
	Перевантаження оператора приведення типа до bool (повертає true, ящко об'єкт володіє адресою)
	Перевантаження оператора присвоєння (=)

	Та методи (для unique_ptr та shared_ptr їх перелік дещо відрізняється), ось деякі з них:
	Get - повертає адресу якою володіє об'єкт
	Release - також повертає адресу, знімаючи володіння нею з себе
	Reset - приймає нову адресу та перевстановлює володіння на неї, параметр методу має значення по замовчуванню, яке встановлює нову адресу в 0
	Swap - приймає такий ж об'єкт і замінює адреси на які вони вказують
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