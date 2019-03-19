#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

typedef void* TElem;
typedef TElem(*CopyFunction)(TElem);
typedef int(*CompareFunction)(TElem, TElem);
typedef int(*FilterFunction)(TElem, void*);
typedef int(*SortFunction)(TElem, TElem);
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

int getElementIndex(DynamicArray* array, CompareFunction compareFn, TElem element);

TElem getFromArray(DynamicArray* array, int index);

void deleteAllFromIndex(DynamicArray* array, int startIndex);

void resizeArray(DynamicArray* array);

DynamicArray* filterArray(DynamicArray* array, FilterFunction filterFn, void* valueToCompare);

DynamicArray* sortArray(DynamicArray* array, SortFunction sortFn);

DynamicArray* copyArray(DynamicArray* array);

void DynamicArrayDestructor(DynamicArray* array);