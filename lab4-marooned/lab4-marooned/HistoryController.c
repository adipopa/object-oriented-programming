#include "HistoryController.h"

HistoryController* HistoryControllerConstructor() {
	HistoryController* historyController = (HistoryController*)malloc(sizeof(HistoryController));
	historyController->undoOperations = DynamicArrayConstructor(copyOperation, OperationDestructor);
	historyController->redoOperations = DynamicArrayConstructor(copyOperation, OperationDestructor);
	historyController->operationIndex = -1;
	return historyController;
}

void createOperation(HistoryController* historyController, Operation* undoOperation, Operation* redoOperation) {
	if (canRedo(historyController)) {
		deleteAllFromIndex(historyController->undoOperations, historyController->operationIndex + 1);
		deleteAllFromIndex(historyController->redoOperations, historyController->operationIndex + 1);
	}
	addToArray(historyController->undoOperations, undoOperation);
	addToArray(historyController->redoOperations, redoOperation);
	historyController->operationIndex++;
}

int undoOperation(HistoryController* historyController) {
	if (!canUndo(historyController)) {
		return 0;
	}
	Operation* operation = getUndoOperation(historyController);
	operation->operationFn(operation->signalController, operation->signal);
	OperationDestructor(operation);
	historyController->operationIndex--;
	return 1;
}

int redoOperation(HistoryController* historyController) {
	if (!canRedo(historyController)) {
		return 0;
	}
	historyController->operationIndex++;
	Operation* operation = getRedoOperation(historyController);
	operation->operationFn(operation->signalController, operation->signal);
	OperationDestructor(operation);
	return 1;
}

Operation* getUndoOperation(HistoryController* historyController) {
	return getFromArray(historyController->undoOperations, historyController->operationIndex);
}

Operation* getRedoOperation(HistoryController* historyController) {
	return getFromArray(historyController->redoOperations, historyController->operationIndex);
}

int canUndo(HistoryController* historyController) {
	return historyController->operationIndex > -1;
}

int canRedo(HistoryController* historyController) {
	return historyController->operationIndex < historyController->redoOperations->length - 1;
}

void HistoryControllerDestructor(HistoryController* historyController) {
	if (historyController != NULL) {
		DynamicArrayDestructor(historyController->undoOperations);
		DynamicArrayDestructor(historyController->redoOperations);
		free(historyController);
	}
}