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

void listSignals(SignalController* signalController, char* formattedSignalsList);

void listSignalsByType(SignalController* signalController, char* type, char* formattedSignalsList);

void SignalControllerDestructor(SignalController* signalController);