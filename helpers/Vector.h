#include<iostream>
#include<stdexcept>

#include "Container.h"

#ifndef VECTOR
#define VECTOR

template<typename T>
class Vector: public Container<T> {

// ------------- USER VECTOR METHODS ------------------
public:
	const T& get(int index) const {
		if(index >= this->size) {
			throw std::out_of_range("Index out of bounds");
		}
		return this->elements[index];
	}

	T& operator[](int index) {
		if(index >= this->size) {
			throw std::out_of_range("Index out of bounds");
		}
		return this->elements[index];
	}

	void add(const T& newElement) {
		if(this->size >= this->capacity) {
			this->expand();
		}
		this->elements[this->size++] = newElement;
	}
};

#endif
