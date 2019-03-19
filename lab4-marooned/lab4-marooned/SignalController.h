#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "SignalValidator.h"
#include "SignalRepository.h"

typedef struct SignalController {
	SignalValidator* signalValidator;
	SignalRepository* signalRepository;
} SignalController;

SignalController* SignalControllerConstructor(SignalValidator* signalValidator, SignalRepository* signalRepository);

int createSignal(SignalController* signalController, Signal* signal);

int updateSignal(SignalController* signalController, Signal* signal);

int deleteSignal(SignalController* signalController, Signal* signal);

Signal* getSignal(SignalController* signalController, int signalId);

DynamicArray* getSignals(SignalController* signalController);

DynamicArray* getSignalsByModulatedSignal(SignalController* signalController, char* modulatedSignal);

DynamicArray* getSignalsByType(SignalController* signalController, char* type);

DynamicArray* getSignalsByPriorityNumberAsc(SignalController* signalController, int priorityNumber);

DynamicArray* getSignalsByPriorityNumberDesc(SignalController* signalController, int priorityNumber);

void SignalControllerDestructor(SignalController* signalController);