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

	T* get() {
		return ptr;
	}

	void reset(my_unique_ptr <T>& other) {
		
		if(ptr != nullptr) delete ptr;

		if (other.ptr != nullptr) {
			ptr = other.release();
		}
		else {
			ptr = 0;
		}
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

	T &operator=(my_unique_ptr <T>&&other) {
		if (other.ptr != nullptr) {

			if (this->ptr != nullptr) {
				delete this->ptr;
			}
			this->ptr = other.ptr;
			other.ptr = nullptr;

		}
		return *this;
	}

	T* operator->() {
		return ptr;
	}
};

template <class T>
class my_shared_ptr
{
private:
	T *ptr;

public:
	my_shared_ptr(T *ptr) : ptr(ptr) {

	}
	my_shared_ptr() {

	}
	~my_shared_ptr() {
		delete ptr;
	}

	T* release() {
		T *tmp = ptr;
		ptr = nullptr;
		return tmp;
	}

	T* get() {
		return ptr;
	}

	void reset(my_shared_ptr <T>& other) {

		if (ptr != nullptr) delete ptr;

		if (other.ptr != nullptr) {
			ptr = other.release();
		}
		else {
			ptr = 0;
		}
	}

	T operator * () const
	{
		return *ptr;
	}

	void swap(my_shared_ptr& other) {
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

	my_shared_ptr<T>& operator= (const my_shared_ptr<T> &other)
	{
		this->ptr = other.ptr;
	
		return *this;
	}

	T* operator->() {
		return ptr;
	}
};

int main() {

	/*my_unique_ptr<int> ukaz(new int(5));
	my_unique_ptr<int> ukaz2(new int(6));*/

	//ukaz2.swap(ukaz);
	//cout << *(ukaz.get());
	//cout << ukaz.get();
	
	//my_unique_ptr<int> ukaz3 = ukaz.release();

	/*ukaz.reset(ukaz2);

	if (ukaz) {
		cout << "isset" << endl;
	}
	else {
		cout << "not isset" << endl;
	}*/
	//my_shared_ptr<int> ukaz(new int(5));


	system("pause");
	return 0;
}
