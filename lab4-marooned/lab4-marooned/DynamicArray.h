#pragma once

typedef void* TElem;
typedef TElem(*CopyFunction)(TElem);
typedef int(*CompareFunction)(TElem1, TElem2);
typedef void(*DestroyFunction)(TElem);

typedef struct DynamicArray {
	TElem* elements;
	int length, capacity;
	CopyFunction copyFn;
	DestroyFunction destroyFn;
} DynamicArray;

DynamicArray* DynamicArrayConstructor(CopyFunction copyFn, DestroyFunction destroyFn);

void addToArray(DynamicArray* array, TElem element);

void updateInArray(DynamicArray* array, int index, TElem element);

void deleteFromArray(DynamicArray* array, int index);

int getElementIndex(DynamicArray* array, TElem element, CompareFunction compareFn);

void deleteAllFromIndex(DynamicArray* array, int startIndex);

void resizeArray(DynamicArray* array);

DynamicArray* copyArray(DynamicArray* array);

void DynamicArrayDestructor(DynamicArray* array);