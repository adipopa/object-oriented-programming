#include "DynamicArray.h"

DynamicArray* DynamicArrayConstructor(CopyFunction copyFn, DestroyFunction destroyFn) {
	DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
	array->capacity = 1;
	array->length = 0;
	array->elements = (TElem*)malloc(sizeof(TElem) * array->capacity);

	array->copyFn = copyFn;
	array->destroyFn = destroyFn;

	return array;
}

void addToArray(DynamicArray* array, TElem element) {
	if (array->length == array->capacity) {
		resizeArray(array);
	}
	array->elements[array->length++] = array->copyFn(element);
}

void updateInArray(DynamicArray* array, int index, TElem element) {
	if (index > -1 && index < array->length) {
		array->destroyFn(array->elements[index]);
		array->elements[index] = array->copyFn(element);
	}
}

void deleteFromArray(DynamicArray* array, int index) {
	if (index > -1 && index < array->length) {
		array->destroyFn(array->elements[index]);
		array->length--;
		for (int j = index; j < array->length; j++) {
			array->elements[j] = array->elements[j + 1];
		}
	}
}

int getElementIndex(DynamicArray* array, CompareFunction compareFn, TElem element) {
	for (int i = 0; i < array->length; i++) {
		if (compareFn(array->elements[i], element)) {
			return i;
		}
	}
	return -1;
}

TElem getFromArray(DynamicArray* array, int index) {
	if (index > -1 && index < array->length) {
		return array->copyFn(array->elements[index]);
	}
	return NULL;
}

void deleteAllFromIndex(DynamicArray* array, int startIndex) {
	for (int i = array->length - 1; i >= startIndex; i--) {
		deleteFromArray(array, i);
	}
}

void resizeArray(DynamicArray* array) {
	array->capacity *= 2;
	TElem* newElements = (TElem*)malloc(sizeof(TElem) * array->capacity);
	for (int i = 0; i < array->length; i++) {
		newElements[i] = array->elements[i];
	}
	free(array->elements);
	array->elements = newElements;
}

DynamicArray* filterArray(DynamicArray* array, FilterFunction filterFn, void* valueToCompare) {
	DynamicArray* filteredArray = copyArray(array);
	for (int i = array->length - 1; i >= 0; i--) {
		if (!filterFn(array->elements[i], valueToCompare)) {
			deleteFromArray(filteredArray, i);
		}
	}
	return filteredArray;
}

DynamicArray* sortArray(DynamicArray* array, SortFunction sortFn) {
	for (int i = 0; i < array->length; i++) {
		for (int j = 0; j < array->length; j++) {
			if (sortFn(array->elements[i], array->elements[j])) {
				TElem* tempElement = array->elements[i];
				array->elements[i] = array->elements[j];
				array->elements[j] = tempElement;
			}
		}
	}
	return array;
}

DynamicArray* copyArray(DynamicArray* array) {
	DynamicArray* newArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	newArray->capacity = array->capacity;
	newArray->length = array->length;
	newArray->elements = (TElem*)malloc(sizeof(TElem) * newArray->capacity);

	newArray->copyFn = array->copyFn;
	newArray->destroyFn = array->destroyFn;

	for (int i = 0; i < array->length; i++) {
		newArray->elements[i] = array->copyFn(array->elements[i]);
	}

	return newArray;
}

void DynamicArrayDestructor(DynamicArray* array) {
	if (array != NULL) {
		for (int i = 0; i < array->length; i++) {
			array->destroyFn(array->elements[i]);
		}
		free(array->elements);
		free(array);
	}
}
