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

int signalCompareFn(Signal* signal1, Signal* signal2) {
	return signal1->id == signal2->id;
}

int signalModulatedSignalFilterFn(Signal* signal, char* modulatedSignal) {
	return strcmp(signal->modulatedSignal, modulatedSignal) == 0;
}

int signalTypeFilterFn(Signal* signal, char* type) {
	return strcmp(signal->type, type) == 0;
}

int signalPriorityNumberFilterFn(Signal* signal, int* priorityNumber) {
	return signal->priorityNumber < *priorityNumber;
}

int signalModulatedSignalAscSortFn(Signal* signal1, Signal* signal2) {
	return strcmp(signal1->modulatedSignal, signal2->modulatedSignal) == -1;
}

int signalModulatedSignalDescSortFn(Signal* signal1, Signal* signal2) {
	return strcmp(signal1->modulatedSignal, signal2->modulatedSignal) == 1;
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