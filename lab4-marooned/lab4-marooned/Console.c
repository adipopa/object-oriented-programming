#include "Console.h"

Console* ConsoleConstructor(SignalController* signalController, HistoryController* historyController) {
	Console* console = (Console*)malloc(sizeof(Console));
	console->signalController = signalController;
	console->historyController = historyController;
	return console;
}

int uiAddSignal(Console* console, char* currentToken) {
	int id, priorityNumber;
	char modulatedSignal[24], type[24];
	currentToken = strtok(NULL, " ");
	if (currentToken == NULL) {
		return -1;
	}
	id = atoi(currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	strcpy(modulatedSignal, currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	strcpy(type, currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	priorityNumber = atoi(currentToken);
	currentToken = strtok(NULL, " ");
	if (currentToken != NULL) {
		return -1;
	}

	Signal* signal = SignalConstructor(id, modulatedSignal, type, priorityNumber);
	int createSignalResult = createSignal(console->signalController, signal);

	if (createSignalResult == 1) {
		Operation* undoOperation = OperationConstructor(deleteSignal, console->signalController, signal);
		Operation* redoOperation = OperationConstructor(createSignal, console->signalController, signal);
		createOperation(console->historyController, undoOperation, redoOperation);
		OperationDestructor(undoOperation);
		OperationDestructor(redoOperation);
	}

	SignalDestructor(signal);

	return createSignalResult;
}

int uiUpdateSignal(Console* console, char* currentToken) {
	int id, newPriorityNumber;
	char newModulatedSignal[16], newType[16];
	currentToken = strtok(NULL, " ");
	if (currentToken == NULL) {
		return -1;
	}
	id = atoi(currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	strcpy(newModulatedSignal, currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	strcpy(newType, currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	newPriorityNumber = atoi(currentToken);
	currentToken = strtok(NULL, " ");
	if (currentToken != NULL) {
		return -1;
	}

	Signal* oldSignal = getSignal(console->signalController, id);
	Signal* newSignal = SignalConstructor(id, newModulatedSignal, newType, newPriorityNumber);
	int updateSignalResult = updateSignal(console->signalController, newSignal);

	if (updateSignalResult == 1) {
		Operation* undoOperation = OperationConstructor(updateSignal, console->signalController, oldSignal);
		Operation* redoOperation = OperationConstructor(updateSignal, console->signalController, newSignal);
		createOperation(console->historyController, undoOperation, redoOperation);
		OperationDestructor(undoOperation);
		OperationDestructor(redoOperation);
	}

	SignalDestructor(oldSignal);
	SignalDestructor(newSignal);

	return updateSignalResult;
}

int uiDeleteSignal(Console* console, char* currentToken) {
	int signalId;
	currentToken = strtok(NULL, " ");
	if (currentToken == NULL) {
		return -1;
	}
	signalId = atoi(currentToken);
	currentToken = strtok(NULL, " ");
	if (currentToken != NULL) {
		return -1;
	}

	Signal* signal = getSignal(console->signalController, signalId);
	int deleteSignalResult = deleteSignal(console->signalController, signal);

	if (deleteSignalResult == 1) {
		Operation* undoOperation = OperationConstructor(createSignal, console->signalController, signal);
		Operation* redoOperation = OperationConstructor(deleteSignal, console->signalController, signal);
		createOperation(console->historyController, undoOperation, redoOperation);
		OperationDestructor(undoOperation);
		OperationDestructor(redoOperation);
	}

	SignalDestructor(signal);

	return deleteSignalResult;
}

int uiListSignals(Console* console, char* currentToken) {
	char listToString[640] = "";
	currentToken = strtok(NULL, " ");

	if (currentToken == NULL) {
		listSignals(console->signalController, listToString);
	}
	else if (strcmp(currentToken, "maximumPriorityNumber") == 0) {
		printf("%s\n", currentToken);
	}
	else {
		char type[20];
		strcpy(type, currentToken);
		currentToken = strtok(NULL, " ");
		if (currentToken != NULL) {
			return -1;
		}
		listSignalsByType(console->signalController, type, listToString);
	}

	printf("%s", listToString);
	return 1;
}

void runConsole(Console* console) {
	int keepAlive = 1;
	while (keepAlive) {
		char inputString[100];

		printf("ship@root:~$ ");
		scanf(" %[^\n]s", inputString);
		char* currentToken = strtok(inputString, " ");

		char command[10];
		strcpy(command, currentToken);

		if (strcmp(command, "add") == 0) {
			int addSignalResult = uiAddSignal(console, currentToken);
			if (addSignalResult == -1) {
				printf("Invalid arguments for 'add' command.\n");
			}
			else if (addSignalResult == 0) {
				printf("Signal with given id already exists.\n");
			}
		}
		else if (strcmp(command, "update") == 0) {
			int updateSignalResult = uiUpdateSignal(console, currentToken);
			if (updateSignalResult == -1) {
				printf("Invalid arguments for 'update' command.\n");
			}
		}
		else if (strcmp(command, "delete") == 0) {
			int deleteSignalResult = uiDeleteSignal(console, currentToken);
			if (deleteSignalResult == -1) {
				printf("Invalid arguments for 'delete' command.\n");
			}
			else if (deleteSignalResult == 0) {
				printf("Signal with given id doesn't exist.\n");
			}
		}
		else if (strcmp(command, "list") == 0) {
			int listSignalsResult = uiListSignals(console, currentToken);
			if (listSignalsResult == -1) {
				printf("Invalid arguments for 'delete' command.\n");
			}
		}
		else if (strcmp(command, "undo") == 0) {
			int undoOperationResult = undoOperation(console->historyController);
			if (undoOperationResult == 0) {
				printf("There is no action left to undo.\n");
			}
		}
		else if (strcmp(command, "redo") == 0) {
			int redoOperationResult = redoOperation(console->historyController);
			if (redoOperationResult == 0) {
				printf("There is no action to redo.\n");
			}
		}
		else if (strcmp(command, "exit") == 0) {
			keepAlive = 0;
		}
		else {
			printf("Invalid command.\n");
		}
	}
}

void ConsoleDestructor(Console* console) {
	if (console != NULL) {
		SignalControllerDestructor(console->signalController);
		HistoryControllerDestructor(console->historyController);
		free(console);
	}
}