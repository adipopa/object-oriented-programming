#include "SignalValidator.h"

SignalValidator* SignalValidatorConstructor(SignalRepository* signalRepository) {
	SignalValidator* signalValidator = (SignalValidator*)malloc(sizeof(SignalValidator));
	signalValidator->signalRepository = signalRepository;
	return signalValidator;
}

int validateAddSignal(SignalValidator* signalValidator, Signal* signal) {
	for (int i = 0; i < signalValidator->signalRepository->signals->length; i++) {
		if (((Signal*)signalValidator->signalRepository->signals->elements[i])->id == signal->id) {
			return 0;
		}
	}
	return 1;
}

int validateDeleteSignal(SignalValidator* signalValidator, Signal* signal) {
	return signal != NULL;
}

void SignalValidatorDestructor(SignalValidator * signalValidator) {
	if (signalValidator != NULL) {
		free(signalValidator);
	}
}
