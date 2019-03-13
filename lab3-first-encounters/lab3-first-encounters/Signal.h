#pragma once

#define _CRT_SECURE_NO_WARNINGS

typedef struct Signal {
	int id;
	int modulatedSignal;
	char type[20];
	int priorityNumber;

} Signal;

Signal SignalConstructor(int id, int modulatedSignal, char type[], int priorityNumber);

int id(Signal signal);