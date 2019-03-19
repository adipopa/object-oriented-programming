#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "SignalController.h"

typedef void(*OperationFunction)(SignalController*, Signal*);

typedef struct Operation {
	// Field for keeping a pointer to the controller function that needs to be called.
	OperationFunction operationFn;
	// The following fields are the possible parameters of the above function call.
	SignalController* signalController;
	Signal* signal;
} Operation;

Operation* OperationConstructor(OperationFunction operationFn, SignalController* signalController, Signal* signal);

Operation* copyOperation(Operation* operation);

void OperationDestructor(Operation* operation);