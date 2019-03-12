#include "Console.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	SignalRepository signalRepository = SignalRepositoryConstructor();
	SignalValidator signalValidator = SignalValidatorConstructor(&signalRepository);
	SignalController signalController = SignalControllerConstructor(&signalValidator, &signalRepository);
	Console console = ConsoleConstructor(&signalController);
	runConsole(&console);
	return 0;
}