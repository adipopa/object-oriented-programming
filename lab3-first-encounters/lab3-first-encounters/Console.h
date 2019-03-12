#pragma once

#define _CRT_SECURE_NO_WARNINGS

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