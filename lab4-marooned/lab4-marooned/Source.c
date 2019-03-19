#include "Console.h"

int main() {
	// Creating instances for each application layer and running the actual app.
	SignalRepository* signalRepository = SignalRepositoryConstructor();
	SignalValidator* signalValidator = SignalValidatorConstructor(signalRepository);
	SignalController* signalController = SignalControllerConstructor(signalValidator, signalRepository);
	HistoryController* historyController = HistoryControllerConstructor();
	Console* console = ConsoleConstructor(signalController, historyController);
	runConsole(console);

	// Calling the ConsoleDestructor in order to free up all the memory that was allocated during runtime.
	ConsoleDestructor(console);

	_CrtDumpMemoryLeaks();

	return 0;
}