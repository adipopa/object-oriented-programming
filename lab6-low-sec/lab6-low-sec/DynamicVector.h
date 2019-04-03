#pragma once

#include <functional>
#include <utility>

template <typename TemplateElement>
class DynamicVector {

private:
	TemplateElement* elements;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& vector);

	// destructor for a DynamicVector
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& vector);

	/*
		Overloading the subscript operator
		Input: pos - a valid position within the vector.
		Output: a reference to the element o position pos.
	*/
	TemplateElement& operator[](int position);

	// Adds an element to the current DynamicVector.
	void add(TemplateElement element);

	// Updates an element in the current DynamicVector.
	void update(int index, TemplateElement element);

	// Removes an element from the current DynamicVector.
	void remove(int index);

	using CompareFunction = std::function<bool(const TemplateElement&)>;

	int getIndex(CompareFunction compareFunction) const;

	using FilterFunction = std::function<bool(const TemplateElement&)>;

	void filterVector(FilterFunction filterFunction);

	int getSize() const;

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);

public:
	class Iterator {

	private:
		TemplateElement* pointerToElement;

	public:
		// constructor with parameter DynamicVector<TemplateElement>
		Iterator(DynamicVector<TemplateElement> vector) {
			this->pointerToElement = vector.elements;
		}

		// constructor with parameter TemplateElement*
		Iterator(TemplateElement* pointerToElement) {
			this->pointerToElement = pointerToElement;
		}

		// operator++ - pre-incrementing
		Iterator operator++() const {
			this->pointerToElement++;
			return *this;
		}

		// operator++ - post-incrementing
		Iterator operator++(int) {
			Iterator currentIterator = *this;
			this->pointerToElement++;
			return currentIterator;
		}

		// operator== - equality
		bool operator==(const Iterator& iteratorToCompare) {
			return this->pointerToElement == iteratorToCompare.pointerToElement;
		}

		// operator!= - inequality
		bool operator!=(const Iterator& iteratorToCompare) {
			return this->pointerToElement != iteratorToCompare.pointerToElement;
		}

		// dereferencing operator
		TemplateElement operator*() {
			return *this->pointerToElement;
		}
	};

	Iterator begin() {
		return Iterator{ elements };
	}

	Iterator end() {
		return Iterator{ elements + size };
	}
};

template <typename TemplateElement>
DynamicVector<TemplateElement>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TemplateElement[capacity];
}

template <typename TemplateElement>
DynamicVector<TemplateElement>::DynamicVector(const DynamicVector<TemplateElement>& vector) {
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = new TemplateElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = vector.elements[i];
}

template <typename TemplateElement>
DynamicVector<TemplateElement>::~DynamicVector() {
	delete[] this->elements;
}

template <typename TemplateElement>
DynamicVector<TemplateElement>& DynamicVector<TemplateElement>::operator=(const DynamicVector<TemplateElement>& vectorToCopy) {
	if (this == &vectorToCopy)
		return *this;

	this->size = vectorToCopy.size;
	this->capacity = vectorToCopy.capacity;

	TemplateElement* auxiliaryElements = new TemplateElement[this->capacity];

	delete[] this->elements;
	
	this->elements = auxiliaryElements;
	for (int i = 0; i < this->size; i++)
		this->elements[i] = vectorToCopy.elements[i];

	return *this;
}

template <typename TemplateElement>
TemplateElement& DynamicVector<TemplateElement>::operator[](int position) {
	return this->elements[position];
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::add(TemplateElement element) {
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::resize(double factor) {
	this->capacity *= (int)factor;

	TemplateElement* newElements = new TemplateElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = newElements;
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::update(int index, TemplateElement element) {
	if (index > -1 && index < this->size) {
		this->elements[index] = element;
	}
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::remove(int index) {
	if (index > -1 && index < this->size) {
		this->size--;
		for (int j = index; j < this->size; j++) {
			this->elements[j] = this->elements[j + 1];
		}
	}
}

template <typename TemplateElement>
int DynamicVector<TemplateElement>::getIndex(CompareFunction compareFunction) const {
	for (int i = 0; i < this->size; i++) {
		if (compareFunction(this->elements[i])) {
			return i;
		}
	}
	return -1;
}

template <typename TemplateElement>
void DynamicVector<TemplateElement>::filterVector(FilterFunction filterFunction) {
	for (int i = this->size - 1; i >= 0; i--) {
		if (!filterFunction(this->elements[i])) {
			this->remove(i);
		}
	}
}

template <typename TemplateElement>
int DynamicVector<TemplateElement>::getSize() const {
	return this->size;
}
