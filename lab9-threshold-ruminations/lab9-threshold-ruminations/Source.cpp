#include "Testing.h"
#include "Console.h"

int main() {
	Testing testing{};
	testing.runTests();

	std::shared_ptr<RecordingRepository> recordingRepository = std::make_shared<RecordingRepository>();
	std::shared_ptr<WatchlistRepository> watchlistRepository = std::make_shared<WatchlistRepository>();
	std::shared_ptr<RecordingValidator> recordingValidator = std::make_shared<RecordingValidator>(recordingRepository, watchlistRepository);
	std::shared_ptr<RecordingController> recordingController = std::make_shared<RecordingController>(
		recordingValidator, recordingRepository, watchlistRepository, "low-security"
	);
	
	Console console{ recordingController };
	console.runConsole();

	return 0;
}