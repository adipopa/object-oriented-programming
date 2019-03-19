#include "Operation.h"

Operation* OperationConstructor(OperationFunction operationFn, SignalController* signalController, Signal* signal) {
	Operation* operation = (Operation*)malloc(sizeof(Operation));
	operation->operationFn = operationFn;
	operation->signalController = signalController;
	operation->signal = copySignal(signal);
	return operation;
}

Operation* copyOperation(Operation* operation) {
	Operation* operationCopy = (Operation*)malloc(sizeof(Operation));
	operationCopy->operationFn = operation->operationFn;
	operationCopy->signalController = operation->signalController;
	operationCopy->signal = copySignal(operation->signal);
	return operationCopy;
}

void OperationDestructor(Operation* operation) {
	if (operation != NULL) {
		// Free the memory which was allocated for the component fields.
		SignalDestructor(operation->signal);
		// Free the memory which was allocated for the Operation structure.
		free(operation);
	}
}