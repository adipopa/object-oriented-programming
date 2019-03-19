#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "DynamicArray.h"
#include "Signal.h"

typedef struct SignalRepository {
	DynamicArray* signals;
} SignalRepository;

SignalRepository* SignalRepositoryConstructor();

void addToRepository(SignalRepository* signalRepository, Signal* signal);

void updateInRepository(SignalRepository* signalRepository, Signal* signal);

void deleteFromRepository(SignalRepository* signalRepository, Signal* signal);

Signal* getFromRepository(SignalRepository* signalRepository, int signalId);

DynamicArray* getAll(SignalRepository* signalRepository);

DynamicArray* getByModulatedSignal(SignalRepository* signalRepository, char* modulatedSignal);

DynamicArray* getByType(SignalRepository* signalRepository, char* type);

DynamicArray* getByPriorityNumberAsc(SignalRepository* signalRepository, int priorityNumber);

DynamicArray* getByPriorityNumberDesc(SignalRepository* signalRepository, int priorityNumber);

void signalsToString(DynamicArray* signals, char* formattedSignalsList);

void SignalRepositoryDestructor(SignalRepository* signalRepository);