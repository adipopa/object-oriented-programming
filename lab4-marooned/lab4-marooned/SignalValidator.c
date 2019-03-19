#include "SignalValidator.h"

SignalValidator* SignalValidatorConstructor(SignalRepository* signalRepository) {
	SignalValidator* signalValidator = (SignalValidator*)malloc(sizeof(SignalValidator));
	signalValidator->signalRepository = signalRepository;
	return signalValidator;
}

int validateAddSignal(SignalValidator* signalValidator, Signal* signal) {
	int signalIndex = getElementIndex(signalValidator->signalRepository->signals, signalCompareFn, signal);
	return signalIndex == -1;
}

int validateDeleteSignal(SignalValidator* signalValidator, Signal* signal) {
	return signal != NULL;
}

void SignalValidatorDestructor(SignalValidator * signalValidator) {
	if (signalValidator != NULL) {
		free(signalValidator);
	}
}
