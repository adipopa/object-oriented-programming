#include "Console.h"
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	SignalRepository signalRepository = SignalRepositoryConstructor();
	SignalValidator signalValidator = SignalValidatorConstructor(&signalRepository);
	SignalController signalController = SignalControllerConstructor(&signalValidator, &signalRepository);
	Console console = ConsoleConstructor(&signalController);
	runConsole(&console);
	SignalRepositoryDestructor(&signalRepository);
	_CrtDumpMemoryLeaks();
	return 0;
}