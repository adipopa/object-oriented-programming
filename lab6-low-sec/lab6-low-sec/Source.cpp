#include "Testing.h"
#include "Console.h"

int main() {
	Testing testing{};
	// testing.runTests();

	RecordingRepository recordingRepository{};
	RecordingValidator recordingValidator{ &recordingRepository };
	RecordingController recordingController{ &recordingValidator, &recordingRepository, "low-security" };
	Console console{ &recordingController };
	console.runConsole();
	return 0;
}