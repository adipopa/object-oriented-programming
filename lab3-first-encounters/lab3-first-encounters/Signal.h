#pragma once

#define _CRT_SECURE_NO_WARNINGS

typedef struct Signal {
	int id;
	char modulatedSignal[16];
	char type[16];
	int priorityNumber;

} Signal;

Signal SignalConstructor(int id, char modulatedSignal[], char type[], int priorityNumber);

void signalToString(Signal signal, char* formattedSignal);