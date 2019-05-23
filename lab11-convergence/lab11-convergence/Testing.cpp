#include "Testing.h"

Testing::Testing() {}

void Testing::testAddRecording() {
	std::shared_ptr<RecordingRepository> recordingFakeRepository = std::make_shared<RecordingFakeRepository>();
	std::shared_ptr<WatchlistRepository> watchlistFakeRepository = std::make_shared<WatchlistFakeRepository>();
	std::shared_ptr<RecordingValidator> recordingFakeValidator = std::make_shared<RecordingFakeValidator>(recordingFakeRepository, watchlistFakeRepository);
	std::shared_ptr<RecordingController> recordingController = std::make_shared<RecordingController>(recordingFakeValidator, recordingFakeRepository, watchlistFakeRepository, "high-security");

	recordingController->addRecording("anomaly 1", "deck D sector X1423", "01-13-3248", 5, "prev1.mp15");
	recordingController->addRecording("anomaly 2", "deck E sector X1542", "01-13-3538", 8, "prev2.mp15");
	recordingController->addRecording("anomaly 3", "deck F sector X4125", "01-13-4248", 3, "prev3.mp15");
	recordingController->addRecording("anomaly 4", "deck C sector X2142", "01-13-7238", 2, "prev4.mp15");
	recordingController->addRecording("anomaly 5", "deck T sector X2312", "01-13-5241", 4, "prev5.mp15");

	std::vector<Recording> recordings = recordingController->getRecordings();

	assert(recordings.size() == 5);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[1].getLocation().compare("deck E sector X1542") == 0);
	assert(recordings[2].getLocation().compare("deck F sector X4125") == 0);
	assert(recordings[2].getTimeOfCreation().compare("01-13-4248") == 0);
	assert(recordings[3].getTimeOfCreation().compare("01-13-7238") == 0);
	assert(recordings[3].getTimesAccessed() == 2);
	assert(recordings[4].getFootagePreview().compare("prev5.mp15") == 0);

	try {
		recordingController->addRecording("anomaly 3", "deck F sector X4125", "01-13-4248", 3, "prev3.mp15");
	}
	catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("Recording with given title already exists.") == 0);
	}
}

void Testing::printTestsPassed() {
	std::ifstream inputStream(".\\TestsPassed.txt");

	std::string line;

	while (std::getline(inputStream, line)) {
		std::cout << line << "\n";
	}
}

void Testing::runTests() {

	// Test the addRecording functionality in complete isolation.
	this->testAddRecording();

	this->printTestsPassed();
}
