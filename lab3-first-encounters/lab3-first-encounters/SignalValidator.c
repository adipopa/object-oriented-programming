#include "SignalValidator.h"

SignalValidator SignalValidatorConstructor(SignalRepository* signalRepository) {
	SignalValidator signalValidator;
	signalValidator.signalRepository = signalRepository;
	return signalValidator;
}

int validateAddSignal(SignalValidator* signalValidator, int signalId) {
	int i;
	for (i = 0; i < signalValidator->signalRepository->length; i++) {
		if (signalValidator->signalRepository->signals[i].id == signalId) {
			return 0;
		}
	}
	return 1;
}

int validateDeleteSignal(SignalValidator* signalValidator, int signalId) {
	int i;
	for (i = 0; i < signalValidator->signalRepository->length; i++) {
		if (signalValidator->signalRepository->signals[i].id == signalId) {
			return 1;
		}
	}
	return 0;
}