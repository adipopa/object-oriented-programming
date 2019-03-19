#include "SignalController.h"

SignalController* SignalControllerConstructor(SignalValidator* signalValidator, SignalRepository* signalRepository) {
	SignalController* signalController = (SignalController*)malloc(sizeof(SignalController));
	signalController->signalValidator = signalValidator;
	signalController->signalRepository = signalRepository;
	return signalController;
}

int createSignal(SignalController* signalController, Signal* signal) {
	if (validateAddSignal(signalController->signalValidator, signal) == 0) {
		return 0;
	}
	addToRepository(signalController->signalRepository, signal);
	return 1;
}

int updateSignal(SignalController* signalController, Signal* signal) {
	updateInRepository(signalController->signalRepository, signal);
	return 1;
}

int deleteSignal(SignalController* signalController, Signal* signal) {
	if (validateDeleteSignal(signalController->signalValidator, signal) == 0) {
		return 0;
	}
	deleteFromRepository(signalController->signalRepository, signal);
	return 1;
}

Signal* getSignal(SignalController* signalController, int signalId) {
	return getFromRepository(signalController->signalRepository, signalId);
}

void listSignals(SignalController* signalController, char* formattedSignalsList) {
	getAll(signalController->signalRepository, formattedSignalsList);
}

void listSignalsByType(SignalController* signalController, char* type, char* formattedSignalsList) {
	getByType(signalController->signalRepository, type, formattedSignalsList);
}

void SignalControllerDestructor(SignalController* signalController) {
	if (signalController != NULL) {
		SignalValidatorDestructor(signalController->signalValidator);
		SignalRepositoryDestructor(signalController->signalRepository);
		free(signalController);
	}
}