#include "Console.h"

int main() {
	SignalRepository* signalRepository = SignalRepositoryConstructor();
	SignalValidator* signalValidator = SignalValidatorConstructor(signalRepository);
	SignalController* signalController = SignalControllerConstructor(signalValidator, signalRepository);
	HistoryController* historyController = HistoryControllerConstructor();
	Console* console = ConsoleConstructor(signalController, historyController);
	runConsole(console);
	ConsoleDestructor(console);
	_CrtDumpMemoryLeaks();
	return 0;
}