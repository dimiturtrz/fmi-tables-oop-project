#include<iostream>
#include<stdexcept>

#ifndef VECTOR
#define VECTOR

template<typename T>
class Vector {
	T* elements;
	int size;
	int capacity;
	
// --------------------- BIG FOUR ---------------------
public:
	Vector(): elements(NULL), size(0), capacity(5) {
		elements = new T[capacity];
	}

	Vector(const Vector& other): elements(NULL) {
		capacity = other.capacity;
		size = other.size;
		copyElements(other.elements, false);
	}

	Vector& operator=(const Vector& other) {
		if(this != &other) {
			capacity = other.capacity;
			size = other.size;
			copyElements(other.elements, false);
		}
		return *this;
	}

	~Vector() {
		delete [] elements;
	}

// --------------- BASIC VECTOR METHODS ---------------
private:
	void copyElements(T* oldElements, bool andDeleteOld) {
		T* newElements = new T[capacity];
		for(int i = 0; i < size; ++i) {
			newElements[i] = oldElements[i];
		}
		if(andDeleteOld) {
			delete [] oldElements;
		}
		elements = newElements;
	}
	void expand() {
		capacity *= 2;
		copyElements(elements, true);
	}

	void shrink() {
		capacity /= 2;
		copyElements(elements, true);
	}
// ------------- USER VECTOR METHODS ------------------
public:
	const T& get(int index) const {
		if(index >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return elements[index];
	}

	T& operator[](int index) {
		if(index >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return elements[index];
	}

	void add(const T& newElement) {
		if(size >= capacity) {
			expand();
		}
		elements[size++] = newElement;
	}

	int getSize() {
		return size;
	}
};

#endif
