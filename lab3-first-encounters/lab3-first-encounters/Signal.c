#include "Signal.h"
#include <stdio.h>
#include <string.h>

Signal SignalConstructor(int id, int modulatedSignal, char type[], int priorityNumber) {
	Signal signal;
	signal.id = id;
	signal.modulatedSignal = modulatedSignal;
	strcpy(signal.type, type);
	signal.priorityNumber = priorityNumber;
	return signal;
}

void signalToString(Signal signal, char* formattedSignal) {
	sprintf(formattedSignal, "%d", signal.id);
	strcat(formattedSignal, " ");
	sprintf(formattedSignal + strlen(formattedSignal), "%d", signal.modulatedSignal);
	strcat(formattedSignal, " ");
	strcat(formattedSignal, signal.type);
	strcat(formattedSignal, " ");
	sprintf(formattedSignal + strlen(formattedSignal), "%d", signal.priorityNumber);
	strcat(formattedSignal, "\n");
}