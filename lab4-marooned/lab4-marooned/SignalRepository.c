#include "SignalRepository.h"

SignalRepository* SignalRepositoryConstructor() {
	SignalRepository* signalRepository = (SignalRepository*)malloc(sizeof(SignalRepository));
	signalRepository->signals = DynamicArrayConstructor(copySignal, SignalDestructor);
	return signalRepository;
}

void addToRepository(SignalRepository* signalRepository, Signal* signal) {
	addToArray(signalRepository->signals, signal);
}

void updateInRepository(SignalRepository* signalRepository, Signal* signal) {
	int signalIndex = getElementIndex(signalRepository->signals, signal, compareSignal);
	updateInArray(signalRepository->signals, signalIndex, signal);
}

void deleteFromRepository(SignalRepository* signalRepository, Signal* signal) {
	int signalIndex = getElementIndex(signalRepository->signals, signal, compareSignal);
	deleteFromArray(signalRepository->signals, signalIndex);
}

Signal* getFromRepository(SignalRepository* signalRepository, int signalId) {
	for (int i = 0; i < signalRepository->signals->length; i++) {
		if (((Signal*)signalRepository->signals->elements[i])->id == signalId) {
			return copySignal(signalRepository->signals->elements[i]);
		}
	}
	return NULL;
}

void getAll(SignalRepository* signalRepository, char* formattedSignalsList) {
	for (int i = 0; i < signalRepository->signals->length; i++) {
		char formattedSignal[32] = "";
		signalToString(((Signal*)signalRepository->signals->elements[i]), formattedSignal);
		strcat(formattedSignalsList, formattedSignal);
	}
}

void getByType(SignalRepository* signalRepository, char type[], char* formattedSignalsList) {
	for (int i = 0; i < signalRepository->signals->length; i++) {
		if (strcmp(((Signal*)signalRepository->signals->elements[i])->type, type) == 0) {
			char formattedSignal[32] = "";
			signalToString(((Signal*)signalRepository->signals->elements[i]), formattedSignal);
			strcat(formattedSignalsList, formattedSignal);
		}
	}
}

void SignalRepositoryDestructor(SignalRepository* signalRepository) {
	if (signalRepository != NULL) {
		DynamicArrayDestructor(signalRepository->signals);
		free(signalRepository);
	}
}