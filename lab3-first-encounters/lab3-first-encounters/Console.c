#include "Console.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Console ConsoleConstructor(SignalController* signalController) {
	Console console;
	console.signalController = signalController;
	return console;
}

int uiAddSignal(Console* console, char* currentToken) {
	int id, modulatedSignal, priorityNumber;
	char type[20];
	currentToken = strtok(NULL, " ");
	if (currentToken == NULL) {
		return -1;
	}
	id = atoi(currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	modulatedSignal = atoi(currentToken);
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
	return createSignal(console->signalController, id, modulatedSignal, type, priorityNumber);
}

int uiUpdateSignal(Console* console, char* currentToken) {
	int id, newModulatedSignal, newPriorityNumber;
	char newType[20];
	currentToken = strtok(NULL, " ");
	if (currentToken == NULL) {
		return -1;
	}
	id = atoi(currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) {
		return -1;
	}
	newModulatedSignal = atoi(currentToken);
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
	return updateSignal(console->signalController, id, newModulatedSignal, newType, newPriorityNumber);
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
	return deleteSignal(console->signalController, signalId);
}

int uiListSignals(Console* console, char* currentToken) {
	char listToString[640] = "";
	currentToken = strtok(NULL, " ");

	if (currentToken == NULL) {
		listSignals(console->signalController, listToString);
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
		else if (strcmp(command, "exit") == 0) {
			keepAlive = 0;
		}
		else {
			printf("Invalid command.\n");
		}
	}
}