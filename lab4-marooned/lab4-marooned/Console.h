#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "SignalController.h"
#include "HistoryController.h"

typedef struct Console {
	SignalController* signalController;
	HistoryController* historyController;
} Console;

Console* ConsoleConstructor(SignalController* signalController, HistoryController* historyController);

int uiAddSignal(Console* console, char* currentToken);

int uiUpdateSignal(Console* console, char* currentToken);

int uiDeleteSignal(Console* console, char* currentToken);

int uiListSignals(Console* console, char* currentToken);

void runConsole(Console* console);

void ConsoleDestructor(Console* console);