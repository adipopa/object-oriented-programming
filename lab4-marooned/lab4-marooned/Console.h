#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "SignalController.h"
#include "HistoryController.h"
#include "HistoryListController.h"

typedef struct Console {
	SignalController* signalController;
	HistoryController* historyController;
	HistoryListController* historyListController;

	char* historyType;
} Console;

Console* ConsoleConstructor(SignalController* signalController);

int uiAddSignal(Console* console, char* currentToken);

int uiUpdateSignal(Console* console, char* currentToken);

int uiDeleteSignal(Console* console, char* currentToken);

void uiCreateOperation(Console* console, OperationFunction undoFn, Signal* signalToUndo, OperationFunction redoFn, Signal* signalToRedo);

void uiAppendUndoList(Console* console);

int uiListSignals(Console* console, char* currentToken);

int isStringNumber(char* stringToCheck);

void runConsole(Console* console);

void ConsoleDestructor(Console* console);