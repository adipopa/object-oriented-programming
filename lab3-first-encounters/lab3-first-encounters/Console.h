#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include "SignalController.h"

typedef struct Console {
	SignalController* signalController;
} Console;

Console ConsoleConstructor(SignalController* signalController);

int uiAddSignal(Console* console, char* currentToken);

int uiUpdateSignal(Console* console, char* currentToken);

int uiDeleteSignal(Console* console, char* currentToken);

int uiListSignals(Console* console, char* currentToken);

void runConsole(Console* console);