#include "SignalRepository.h"
#include <stdlib.h>
#include <string.h>

SignalRepository SignalRepositoryConstructor() {
	SignalRepository signalRepository;
	Signal* signals = (Signal*)malloc(sizeof(Signal) * 32);
	signalRepository.signals = signals;
	signalRepository.length = 0;
	return signalRepository;
}

void addToRepository(SignalRepository* signalRepository, Signal signal) {
	signalRepository->signals[signalRepository->length++] = signal;
}

void updateInRepository(SignalRepository* signalRepository, Signal signal) {
	int i;
	for (i = 0; i < signalRepository->length; i++) {
		if (signalRepository->signals[i].id == signal.id) {
			signalRepository->signals[i] = signal;
			return;
		}
	}
}

void deleteFromRepository(SignalRepository* signalRepository, int signalId) {
	int i;
	for (i = 0; i < signalRepository->length; i++) {
		if (signalRepository->signals[i].id == signalId) {
			signalRepository->length--;
			int j;
			for (j = i; j < signalRepository->length; j++) {
				signalRepository->signals[j] = signalRepository->signals[j + 1];
			}
			return;
		}
	}
}

void getAll(SignalRepository* signalRepository, char* formattedSignalsList) {
	for (int i = 0; i < signalRepository->length; i++) {
		char formattedSignal[32] = "";
		signalToString(signalRepository->signals[i], formattedSignal);
		strcat(formattedSignalsList, formattedSignal);
	}
}

void getByType(SignalRepository* signalRepository, char type[], char* formattedSignalsList) {
	for (int i = 0; i < signalRepository->length; i++) {
		if (strcmp(signalRepository->signals[i].type, type) == 0) {
			char formattedSignal[32] = "";
			signalToString(signalRepository->signals[i], formattedSignal);
			strcat(formattedSignalsList, formattedSignal);
		}
	}
}

void SignalRepositoryDestructor(SignalRepository* signalRepository) {
	free(signalRepository->signals);
}