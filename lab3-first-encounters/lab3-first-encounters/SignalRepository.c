#include "SignalRepository.h"
#include <string.h>

SignalRepository SignalRepositoryConstructor() {
	SignalRepository signalRepository;
	Signal* signals = (Signal*)malloc(sizeof(Signal) * 32);
	signalRepository.signals = signals;
	signalRepository.length = 0;
	return signalRepository;
}

void add(SignalRepository* signalRepository, Signal signal) {
	signalRepository->signals[signalRepository->length++] = signal;
}

void update(SignalRepository* signalRepository, Signal signal) {
	int i;
	for (i = 0; i < signalRepository->length; i++) {
		if (signalRepository->signals[i].id == signal.id) {
			signalRepository->signals[i] = signal;
			return;
		}
	}
}

void delete(SignalRepository* signalRepository, int signalId) {
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