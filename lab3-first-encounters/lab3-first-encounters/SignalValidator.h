#pragma once

#include "SignalRepository.h"

typedef struct SignalValidator {
	SignalRepository* signalRepository;
} SignalValidator;

SignalValidator SignalValidatorConstructor(SignalRepository* signalRepository);

int validateAddSignal(SignalValidator* signalValidator, int signalId);

int validateDeleteSignal(SignalValidator* signalValidator, int signalId);