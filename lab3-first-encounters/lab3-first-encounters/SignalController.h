#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SignalValidator.h"
#include "SignalRepository.h"

typedef struct SignalController {
	SignalValidator* signalValidator;
	SignalRepository* signalRepository;
} SignalController;

SignalController SignalControllerConstructor(SignalValidator* signalValidator, SignalRepository* signalRepository);

int createSignal(SignalController* signalController, int id, int modulatedSignal, char type[], int priorityNumber);

int updateSignal(SignalController* signalController, int id, int newModulatedSignal, char type[], int newPriorityNumber);

int deleteSignal(SignalController* signalController, int signalId);

char* retrieveSignals(SignalController* signalController);

char* retrieveSignalsByType(SignalController* signalController, char type[]);