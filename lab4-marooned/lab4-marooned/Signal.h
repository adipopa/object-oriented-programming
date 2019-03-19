#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Signal {
	int id;
	char* modulatedSignal;
	char* type;
	int priorityNumber;

} Signal;

Signal* SignalConstructor(int id, char* modulatedSignal, char* type, int priorityNumber);

Signal* copySignal(Signal* signal);

int compareSignal(Signal* signal1, Signal* signal2);

void signalToString(Signal* signal, char* formattedSignal);

void SignalDestructor(Signal* signal);