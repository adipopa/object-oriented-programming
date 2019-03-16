#include "SignalController.h"

SignalController SignalControllerConstructor(SignalValidator* signalValidator, SignalRepository* signalRepository) {
	SignalController signalController;
	signalController.signalValidator = signalValidator;
	signalController.signalRepository = signalRepository;
	return signalController;
}

int createSignal(SignalController* signalController, int id, char modulatedSignal[], char type[], int priorityNumber) {
	if (validateAddSignal(signalController->signalValidator, id) == 0) {
		return 0;
	}
	Signal signal = SignalConstructor(id, modulatedSignal, type, priorityNumber);
	addToRepository(signalController->signalRepository, signal);
	return 1;
}

int updateSignal(SignalController* signalController, int id, char newModulatedSignal[], char newType[], int newPriorityNumber) {
	Signal signal = SignalConstructor(id, newModulatedSignal, newType, newPriorityNumber);
	updateInRepository(signalController->signalRepository, signal);
	return 1;
}

int deleteSignal(SignalController* signalController, int signalId) {
	if (validateDeleteSignal(signalController->signalValidator, signalId) == 0) {
		return 0;
	}
	deleteFromRepository(signalController->signalRepository, signalId);
	return 1;
}

void listSignals(SignalController* signalController, char* formattedSignalsList) {
	getAll(signalController->signalRepository, formattedSignalsList);
}

void listSignalsByType(SignalController* signalController, char type[], char* formattedSignalsList) {
	getByType(signalController->signalRepository, type, formattedSignalsList);
}