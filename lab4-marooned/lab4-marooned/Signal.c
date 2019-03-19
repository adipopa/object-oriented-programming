#include "Signal.h"

Signal* SignalConstructor(int id, char* modulatedSignal, char* type, int priorityNumber) {
	Signal* signal = (Signal*)malloc(sizeof(Signal));
	signal->id = id;
	signal->modulatedSignal = (char*)malloc(sizeof(char) * (strlen(modulatedSignal) + 1));
	strcpy(signal->modulatedSignal, modulatedSignal);
	signal->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(signal->type, type);
	signal->priorityNumber = priorityNumber;
	return signal;
}

Signal* copySignal(Signal* signal) {
	Signal* signalCopy = (Signal*)malloc(sizeof(Signal));
	signalCopy->id = signal->id;
	signalCopy->modulatedSignal = (char*)malloc(sizeof(char) * (strlen(signal->modulatedSignal) + 1));
	strcpy(signalCopy->modulatedSignal, signal->modulatedSignal);
	signalCopy->type = (char*)malloc(sizeof(char) * (strlen(signal->type) + 1));
	strcpy(signalCopy->type, signal->type);
	signalCopy->priorityNumber = signal->priorityNumber;
	return signalCopy;
}

int compareSignal(Signal* signal1, Signal* signal2) {
	return signal1->id == signal2->id;
}

void signalToString(Signal* signal, char* formattedSignal) {
	sprintf(formattedSignal, "%d %s %s %d\n", signal->id, signal->modulatedSignal, signal->type, signal->priorityNumber);
}

void SignalDestructor(Signal* signal) {
	if (signal != NULL) {
		// Free the memory which was allocated for the component fields.
		free(signal->modulatedSignal);
		free(signal->type);
		// Free the memory which was allocated for the Signal structure.
		free(signal);
	}
}