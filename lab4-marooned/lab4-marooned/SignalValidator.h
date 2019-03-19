#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "SignalRepository.h"

typedef struct SignalValidator {
	SignalRepository* signalRepository;
} SignalValidator;

SignalValidator* SignalValidatorConstructor(SignalRepository* signalRepository);

int validateAddSignal(SignalValidator* signalValidator, Signal* signal);

int validateDeleteSignal(SignalValidator* signalValidator, Signal* signal);

void SignalValidatorDestructor(SignalValidator* signalValidator);