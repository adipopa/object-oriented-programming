#include "Console.h"

Console* ConsoleConstructor(SignalController* signalController) {
	Console* console = (Console*)malloc(sizeof(Console));
	console->signalController = signalController;
	console->historyController = HistoryControllerConstructor();
	console->historyListController = HistoryListControllerConstructor(signalController);
	// Magic variable for specifying which controller should be used for the undo / redo functionality (operations / list).
	console->historyType = "operations";
	return console;
}

int uiAddSignal(Console* console, char* currentToken) {
	int id, priorityNumber;
	char modulatedSignal[16], type[16];
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
		if (strcmp(console->historyType, "operations") == 0) {
			uiCreateOperation(console, deleteSignal, signal, createSignal, signal);
		}
		else if (strcmp(console->historyType, "list") == 0) {
			uiAppendUndoList(console);
		}
		
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
		if (strcmp(console->historyType, "operations") == 0) {
			uiCreateOperation(console, updateSignal, oldSignal, updateSignal, newSignal);
		}
		else if (strcmp(console->historyType, "list") == 0) {
			uiAppendUndoList(console);
		}
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
		if (strcmp(console->historyType, "operations") == 0) {
			uiCreateOperation(console, createSignal, signal, deleteSignal, signal);
		}
		else if (strcmp(console->historyType, "list") == 0) {
			uiAppendUndoList(console);
		}
	}

	SignalDestructor(signal);

	return deleteSignalResult;
}

void uiCreateOperation(Console* console, OperationFunction undoFn, Signal* signalToUndo, OperationFunction redoFn, Signal* signalToRedo) {
	Operation* undoOperation = OperationConstructor(undoFn, console->signalController, signalToUndo);
	Operation* redoOperation = OperationConstructor(redoFn, console->signalController, signalToRedo);
	createOperation(console->historyController, undoOperation, redoOperation);
	OperationDestructor(undoOperation);
	OperationDestructor(redoOperation);
}

void uiAppendUndoList(Console* console) {
	DynamicArray* itemsToUndo = getSignals(console->signalController);
	appendUndoList(console->historyListController, itemsToUndo);
	DynamicArrayDestructor(itemsToUndo);
}

int uiListSignals(Console* console, char* currentToken) {
	char listToString[640] = "";
	currentToken = strtok(NULL, " ");

	if (currentToken == NULL) {
		DynamicArray* allSignals = getSignals(console->signalController);
		signalsToString(allSignals, listToString);
		DynamicArrayDestructor(allSignals);
	}
	else if (strcmp(currentToken, "modulatedSignal") == 0) {
		char modulatedSignal[16];
		currentToken = strtok(NULL, " ");
		if (currentToken == NULL) {
			return -1;
		}
		strcpy(modulatedSignal, currentToken);
		currentToken = strtok(NULL, " ");
		if (currentToken != NULL) {
			return -1;
		}
		DynamicArray* signalsByModulatedSignal = getSignalsByModulatedSignal(console->signalController, modulatedSignal);
		signalsToString(signalsByModulatedSignal, listToString);
		DynamicArrayDestructor(signalsByModulatedSignal);
	}
	else {
		if (isStringNumber(currentToken)) {
			int priorityNumber = atoi(currentToken);
			char sortType[16] = "";
			currentToken = strtok(NULL, " ");
			if (currentToken != NULL) {
				if (strcmp(currentToken, "asc") != 0 && strcmp(currentToken, "desc") != 0) {
					return -1;
				}
				strcpy(sortType, currentToken);
			}
			currentToken = strtok(NULL, " ");
			if (currentToken != NULL) {
				return -1;
			}
			if (strcmp(sortType, "") == 0 || strcmp(sortType, "asc") == 0) {
				DynamicArray* signalsByPriorityNumberAsc = getSignalsByPriorityNumberAsc(console->signalController, priorityNumber);
				signalsToString(signalsByPriorityNumberAsc, listToString);
				DynamicArrayDestructor(signalsByPriorityNumberAsc);
			}
			else if (strcmp(sortType, "desc") == 0) {
				DynamicArray* signalsByPriorityNumberDesc = getSignalsByPriorityNumberDesc(console->signalController, priorityNumber);
				signalsToString(signalsByPriorityNumberDesc, listToString);
				DynamicArrayDestructor(signalsByPriorityNumberDesc);
			}
		}
		else {
			char type[16];
			strcpy(type, currentToken);
			currentToken = strtok(NULL, " ");
			if (currentToken != NULL) {
				return -1;
			}
			DynamicArray* signalsByType = getSignalsByType(console->signalController, type);
			signalsToString(signalsByType, listToString);
			DynamicArrayDestructor(signalsByType);
		}
	}

	printf("%s", listToString);
	return 1;
}

int isStringNumber(char* stringToCheck) {
	for (int i = 0; i < stringToCheck[i] != '\0'; i++) {
		if (!isdigit(stringToCheck[i])) {
			return 0;
		}
	}
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
				printf("Invalid arguments for 'list' command.\n");
			}
		}
		else if (strcmp(command, "undo") == 0) {
			int undoResult = -1;
			if (strcmp(console->historyType, "operations") == 0) {
				undoResult = undoOperation(console->historyController);
			}
			else if (strcmp(console->historyType, "list") == 0) {
				undoResult = undoItems(console->historyListController);
			}
			if (undoResult == -1) {
				printf("No controller was specified for the undo operation.\n");
			}
			else if (undoResult == 0) {
				printf("There is no action left to undo.\n");
			}
		}
		else if (strcmp(command, "redo") == 0) {
			int redoResult = -1;
			if (strcmp(console->historyType, "operations") == 0) {
				redoResult = redoOperation(console->historyController);
			}
			else if (strcmp(console->historyType, "list") == 0) {
				redoResult = redoItems(console->historyListController);
			}
			if (redoResult == -1) {
				printf("No controller was specified for the redo operation.\n");
			}
			else if (redoResult == 0) {
				printf("There is no action left to redo.\n");
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
		HistoryListControllerDestructor(console->historyListController);
		free(console);
	}
}