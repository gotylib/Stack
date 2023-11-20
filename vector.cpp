#pragma once
template<typename T>
class vector_iterator {
private:
    T* ptr;
public:
    vector_iterator(T* ptr) : ptr(ptr) {}
    vector_iterator<T>& operator++() { // префиксный инкремент
        ++ptr;
        return *this;
    }
    vector_iterator<T> operator++(int) { // постфиксный инкремент
        vector_iterator<T> old(*this);
        ++ptr;
        return old;
    }
    bool operator==(const vector_iterator<T>& other) const {
        return ptr == other.ptr;
    }
    bool operator!=(const vector_iterator<T>& other) const {
        return !(*this == other);
    }
    T& operator*() const {
        return *ptr;
    }
};


#pragma once
#include <fstream>
#include "iterator.h"

template <typename T>
class vector {
private:
	T* array;
	int *size;
	int* limitSize;
public:
	vector();
	vector(const vector<T> &other);
	~vector();
	void push_back(T date);
	void remove(int index);
	void pop_back();
	void show();
	int GetSize()const;
	T& operator [](int index);
	vector_iterator<T> begin() const {return vector_iterator<T>(array);}
	vector_iterator<T> end() const {return vector_iterator<T>(array + *size);}
	friend std::ostream& operator<<(std::ostream& os, vector<T>& arr);
	friend std::istream& operator>>(std::istream& in, vector<T>& arr);
};

template<typename T>
vector<T>::vector() {
	array = new T(1);
	size = new int(0);
	limitSize = new int(1);
}
template<typename T>
vector<T>::vector(const vector<T>& other) {
	array = new T(*other.array);
	size = new int(*other.size);
	limitSize = new int(*other.limitSize);
}

template<typename T>
vector<T>::~vector() {
	delete[] array;
	delete size;
	delete limitSize;
}

template<typename T>
int vector<T>::GetSize()const {
	return *size;
}

template<typename T>
void vector<T>::push_back(T date) {
	if (*size < *limitSize) {
		array[*size] = date;
		++*size;
	}
	else {
		*limitSize *= 2;
		T* newArr = new T[*limitSize];
		for (int i = 0; i < *size; ++i) {
			newArr[i] = array[i];
		}
		newArr[*size] = date;
		++*size;
		delete[] array;
		array = newArr;
	}
}

template<typename T>
T& vector<T>::operator[](int index) {
	try {
		if (index<0 || index>*size - 1) {
			throw std::out_of_range("Index out of range");
		}
		else {
			return array[index];
		}
	}
	catch(std::out_of_range& ex) {
		std::cerr << "Index out of range" << ex.what() << "\n";
	}
}

template <typename T>
void vector<T>::remove(int index) {
	try {
		if (index < 0 || index >= *size) {
			throw std::out_of_range("Index out of range");
		}
		else {
			T *newArr = new T[*size - 1];
			int j = 0;
			for (int i = 0; i < *size; ++i) {
				if (i != index) {
					newArr[j] = array[i];
					++j;
				}
			}
			-- * size;
			delete[] array;
			array = newArr;
		}
	}
	catch (std::out_of_range& ex) {
		std::cerr << "Index out of range" << ex.what() << "\n";
	}
}

template<typename T>
void vector<T>::pop_back() {
	try {
		if (*size==0) {
			throw std::out_of_range("Index out of range");
		}
		else {
			T* newArr = new T[*size-1];
			for (int i = 0; i < *size - 1; ++i) {
				newArr[i] = array[i];
			}
			--*size;
			delete[] array;
			array = newArr;
		}
	}
	catch (std::out_of_range& ex) {
		std::cerr << "deleting a non - existing element" << ex.what() << "\n";
	}
}

template<typename T>
void vector<T>::show() {
	for (int i = 0; i < *size; ++i) {
		std::cout << array[i] << std::endl;
	}
}

template< typename T>
std::ostream& operator<<(std::ostream& os, vector<T>& arr)
{
	os << std::endl;
	for (int i=0; i < arr.GetSize(); ++i)
	{
		os << arr[i] << std::endl;
	}
	os << std::endl;
	return os;
}

template <typename T>
std::istream& operator>>(std::istream& in, vector<T>& arr) {
	int size;
	in >> size;
	T date;
	for (int i = 0; i < size; ++i) {
		in >> date;
		arr.push_back(date);
	}
	return in;
}


#include <iostream>
#include "vector.h"

using namespace std;
int main() {
	vector<int> arr;
	std::cin >> arr;
	arr.remove(2);
	vector<int> arr2(arr);
	std::cout << arr << std::endl;

}
