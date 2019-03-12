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

const char* signalToString(Signal signal) {
	char signalToString[32] = "";
	sprintf(signalToString, "%d", signal.id);
	strcat(signalToString, " ");
	sprintf(signalToString + strlen(signalToString), "%d", signal.modulatedSignal);
	strcat(signalToString, " ");
	strcat(signalToString, signal.type);
	strcat(signalToString, " ");
	sprintf(signalToString + strlen(signalToString), "%d", signal.priorityNumber);
	strcat(signalToString, "\n");
	return signalToString;
}

char* retrieveSignals(SignalController* signalController) {
	char formattedSignalsList[640] = "";
	for (int i = 0; i < signalController->signalRepository->length; i++) {
		Signal signal = signalController->signalRepository->signals[i];
		strcat(formattedSignalsList, signalToString(signal));
	}
	return formattedSignalsList;
}

char* retrieveSignalsByType(SignalController* signalController, char type[]) {
	char formattedSignalsList[640] = "";
	for (int i = 0; i < signalController->signalRepository->length; i++) {
		Signal signal = signalController->signalRepository->signals[i];
		if (strcmp(signal.type, type) == 0) {
			strcat(formattedSignalsList, signalToString(signal));
		}
	}
	return formattedSignalsList;

}