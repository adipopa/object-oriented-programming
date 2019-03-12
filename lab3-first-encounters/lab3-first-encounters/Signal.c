#include "Signal.h"
#include <string.h>

Signal SignalConstructor(int id, int modulatedSignal, char type[], int priorityNumber) {
	Signal signal;
	signal.id = id;
	signal.modulatedSignal = modulatedSignal;
	strcpy(signal.type, type);
	signal.priorityNumber = priorityNumber;
	return signal;
}

int getId(Signal signal) {
	return signal.id;
}
