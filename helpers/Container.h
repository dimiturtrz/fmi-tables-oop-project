#include<iostream>
#include<stdexcept>

#ifndef CONTAINER
#define CONTAINER

template<typename T>
class Container {
protected:
	T* elements;
	int size;
	int capacity;
	
// --------------------- BIG FOUR ---------------------
public:
	Container(const int startCap = 5): elements(NULL), size(0), capacity(startCap) {
		elements = new T[capacity];
	}

	Container(const Container& other): elements(NULL) {
		capacity = other.capacity;
		size = other.size;
		copyElements(other.elements, false);
	}

	Container& operator=(const Container& other) {
		if(this != &other) {
			capacity = other.capacity;
			size = other.size;
			copyElements(other.elements, false);
		}
		return *this;
	}

	~Container() {
		delete [] elements;
	}

// --------------- BASIC CONTAINER METHODS ---------------
protected:
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
// ------------- USER CONTAINER METHODS ------------------
public:
	void reset() {
		delete [] elements;
		size = 0;
		capacity = 5;
		elements = new T[capacity];
	}

	int getSize() const {
		return size;
	}
};

#endif
