#include "Testing.h"
#include "Console.h"

int main() {
	// Running tests to check if the app's functionalities work as expected.
	Testing* testing = TestingConstructor();
	runTests(testing);

	// Calling the TestingDestructor in order to free up the memory allocated during testing.
	TestingDestructor(testing);
	
	// Creating instances for each application layer and running the actual app.
	SignalRepository* signalRepository = SignalRepositoryConstructor();
	SignalValidator* signalValidator = SignalValidatorConstructor(signalRepository);
	SignalController* signalController = SignalControllerConstructor(signalValidator, signalRepository);
	Console* console = ConsoleConstructor(signalController);
	runConsole(console);

	// Calling the ConsoleDestructor in order to free up all the memory that was allocated during runtime.
	ConsoleDestructor(console);

	_CrtDumpMemoryLeaks();

	return 0;
}