#include "Signal.h"
#include <stdio.h>
#include <string.h>

Signal SignalConstructor(int id, char modulatedSignal[], char type[], int priorityNumber) {
	Signal signal;
	signal.id = id;
	strcpy(signal.modulatedSignal, modulatedSignal);
	strcpy(signal.type, type);
	signal.priorityNumber = priorityNumber;
	return signal;
}

void signalToString(Signal signal, char* formattedSignal) {
	sprintf(formattedSignal, "%d", signal.id);
	strcat(formattedSignal, " ");
	strcat(formattedSignal, signal.modulatedSignal);
	strcat(formattedSignal, " ");
	strcat(formattedSignal, signal.type);
	strcat(formattedSignal, " ");
	sprintf(formattedSignal + strlen(formattedSignal), "%d", signal.priorityNumber);
	strcat(formattedSignal, "\n");
}