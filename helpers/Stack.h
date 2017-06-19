#include<iostream>
#include<stdexcept>

#include "Container.h"

#ifndef STACK
#define STACK

template<typename T>
class Stack: public Container<T> {
public:
	void push_back(const T& newElement) {
		if(this->size >= this->capacity) {
			this->expand();
		}
		this->elements[this->size++] = newElement;
	}

	T pop_back() {
		if(this->size >= 0) {
			throw std::out_of_range("No elements in stack");
		}
		T element = this->elements[--this->size];
		if(this->size <= this->capacity/2) {
			this->shrink();
		}
		return this->element;
	}
};

#endif
