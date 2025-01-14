#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "SignalValidator.h"
#include "SignalRepository.h"

typedef struct SignalController {
	SignalValidator* signalValidator;
	SignalRepository* signalRepository;
} SignalController;

SignalController SignalControllerConstructor(SignalValidator* signalValidator, SignalRepository* signalRepository);

int createSignal(SignalController* signalController, int id, char modulatedSignal[], char type[], int priorityNumber);

int updateSignal(SignalController* signalController, int id, char newModulatedSignal[], char type[], int newPriorityNumber);

int deleteSignal(SignalController* signalController, int signalId);

void listSignals(SignalController* signalController, char* formattedSignalsList);

void listSignalsByType(SignalController* signalController, char type[], char* formattedSignalsList);