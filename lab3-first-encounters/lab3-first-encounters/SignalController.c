#include "SignalValidator.h"
#include "SignalController.h"
#include <stdio.h>
#include <string.h>

SignalController SignalControllerConstructor(SignalValidator* signalValidator, SignalRepository* signalRepository) {
	SignalController signalController;
	signalController.signalValidator = signalValidator;
	signalController.signalRepository = signalRepository;
	return signalController;
}

int createSignal(SignalController* signalController, int id, int modulatedSignal, char type[], int priorityNumber) {
	if (validateAddSignal(signalController->signalValidator, id) == 0) {
		return 0;
	}
	Signal signal = SignalConstructor(id, modulatedSignal, type, priorityNumber);
	add(signalController->signalRepository, signal);
	return 1;
}

int updateSignal(SignalController* signalController, int id, int newModulatedSignal, char newType[], int newPriorityNumber) {
	Signal signal = SignalConstructor(id, newModulatedSignal, newType, newPriorityNumber);
	update(signalController->signalRepository, signal);
	return 1;
}

int deleteSignal(SignalController* signalController, int signalId) {
	if (validateDeleteSignal(signalController->signalValidator, signalId) == 0) {
		return 0;
	}
	delete(signalController->signalRepository, signalId);
	return 1;
}

void signalToString(Signal signal, char* formattedSignal) {
	sprintf(formattedSignal, "%d", signal.id);
	strcat(formattedSignal, " ");
	sprintf(formattedSignal + strlen(formattedSignal), "%d", signal.modulatedSignal);
	strcat(formattedSignal, " ");
	strcat(formattedSignal, signal.type);
	strcat(formattedSignal, " ");
	sprintf(formattedSignal + strlen(formattedSignal), "%d", signal.priorityNumber);
	strcat(formattedSignal, "\n");
}

void listSignals(SignalController* signalController, char* formattedSignalsList) {
	for (int i = 0; i < signalController->signalRepository->length; i++) {
		Signal signal = signalController->signalRepository->signals[i];
		char formattedSignal[32] = "";
		signalToString(signal, formattedSignal);
		strcat(formattedSignalsList, formattedSignal);
	}
}

void listSignalsByType(SignalController* signalController, char type[], char* formattedSignalsList) {
	for (int i = 0; i < signalController->signalRepository->length; i++) {
		Signal signal = signalController->signalRepository->signals[i];
		if (strcmp(signal.type, type) == 0) {
			char formattedSignal[32] = "";
			signalToString(signal, formattedSignal);
			strcat(formattedSignalsList, formattedSignal);
		}
	}

}