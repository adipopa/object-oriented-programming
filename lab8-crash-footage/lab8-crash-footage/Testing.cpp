#include "Testing.h"

Testing::Testing() {
	this->recordingRepository = std::make_shared<RecordingRepository>();
	this->recordingValidator = std::make_shared<RecordingValidator>(recordingRepository);
	this->recordingController = std::make_shared<RecordingController>(recordingValidator, recordingRepository, "high-security");
}

void Testing::testSetMode() {
	this->recordingController->setMode('B');

	try {
		this->recordingController->addRecording("anomaly 1", "deck D sector X1423", "01-13-3248", 5, "prev1.mp15");
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to add a new recording.") == 0);
	}

	try {
		this->recordingController->updateRecording("anomaly 1", "deck E sector X1542", "0101-13-3538", 8, "prev2.mp15");
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to update a recording.") == 0);
	}

	try {
		this->recordingController->deleteRecording("anomaly 1");
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to remove a recording.") == 0);
	}

	try {
		this->recordingController->getRecordings();
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to list the recordings.") == 0);
	}

	this->recordingController->setMode('A');

	try {
		this->recordingController->getNextRecording();
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to play a recording preview.") == 0);
	}

	try {
		this->recordingController->saveRecording("anomaly 1");
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to save a recording to your watchlist.") == 0);
	}

	try {
		this->recordingController->getRecordingsByLocationAndTimesAccessed("deck E sector X1542", 9);
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to list the recordings by location and times accessed.") == 0);
	}

	try {
		this->recordingController->getWatchlist();
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("You don't have the necessary clearance to see your watchlist.") == 0);
	}

	try {
		this->recordingController->setMode('C');
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("Invalid mode type (valid options are A/B).") == 0);
	}
}

void Testing::testCreateRecording() {
	this->recordingController->addRecording("anomaly 1", "deck D sector X1423", "01-13-3248", 5, "prev1.mp15");
	this->recordingController->addRecording("anomaly 2", "deck E sector X1542", "01-13-3538", 8, "prev2.mp15");
	this->recordingController->addRecording("anomaly 3", "deck F sector X4125", "01-13-4248", 3, "prev3.mp15");
	this->recordingController->addRecording("anomaly 4", "deck C sector X2142", "01-13-7238", 2, "prev4.mp15");
	this->recordingController->addRecording("anomaly 5", "deck T sector X2312", "01-13-5241", 4, "prev5.mp15");

	std::vector<Recording> recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 5);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[1].getLocation().compare("deck E sector X1542") == 0);
	assert(recordings[2].getLocation().compare("deck F sector X4125") == 0);
	assert(recordings[2].getTimeOfCreation().compare("01-13-4248") == 0);
	assert(recordings[3].getTimeOfCreation().compare("01-13-7238") == 0);
	assert(recordings[3].getTimesAccessed() == 2);
	assert(recordings[4].getFootagePreview().compare("prev5.mp15") == 0);

	try {
		this->recordingController->addRecording("anomaly 3", "deck F sector X4125", "01-13-4248", 3, "prev3.mp15");
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("Recording with given title already exists.") == 0);
	}
}

void Testing::testUpdateRecording() {
	this->recordingController->updateRecording("anomaly 1", "deck K sector X1623", "01-13-3448", 7, "prev1.2.mp15");
	this->recordingController->updateRecording("anomaly 2", "deck T sector X2312", "01-13-3238", 6, "prev2.7.mp15");
	this->recordingController->updateRecording("anomaly 3", "deck B sector X9512", "01-13-1248", 5, "prev3.4.mp15");

	std::vector<Recording> recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 5);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[0].getLocation().compare("deck K sector X1623") == 0);
	assert(recordings[1].getLocation().compare("deck T sector X2312") == 0);
	assert(recordings[1].getTimeOfCreation().compare("01-13-3238") == 0);
	assert(recordings[2].getTimeOfCreation().compare("01-13-1248") == 0);
	assert(recordings[2].getTimesAccessed() == 5);
	assert(recordings[2].getFootagePreview().compare("prev3.4.mp15") == 0);
	assert(recordings[3].getTimesAccessed() == 2);
	assert(recordings[4].getFootagePreview().compare("prev5.mp15") == 0);
}

void Testing::testDeleteRecording() {
	this->recordingController->deleteRecording("anomaly 3");
	this->recordingController->deleteRecording("anomaly 4");

	std::vector<Recording> recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 3);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[0].getLocation().compare("deck K sector X1623") == 0);
	assert(recordings[1].getLocation().compare("deck T sector X2312") == 0);
	assert(recordings[1].getTimeOfCreation().compare("01-13-3238") == 0);
	assert(recordings[2].getTitle().compare("anomaly 5") == 0);
	assert(recordings[2].getFootagePreview().compare("prev5.mp15") == 0);

	try {
		this->recordingController->deleteRecording("anomaly 3");
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("Recording with given title doesn't exist.") == 0);
	}
}

void Testing::testGetRecordings() {
	std::vector<Recording> recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 3);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[0].getLocation().compare("deck K sector X1623") == 0);
	assert(recordings[1].getLocation().compare("deck T sector X2312") == 0);
	assert(recordings[1].getTimeOfCreation().compare("01-13-3238") == 0);
	assert(recordings[2].getTitle().compare("anomaly 5") == 0);
	assert(recordings[2].getFootagePreview().compare("prev5.mp15") == 0);
}

void Testing::testGetNextRecording() {
	Recording nextRecording = this->recordingController->getNextRecording();

	assert(nextRecording.getTitle().compare("anomaly 1") == 0);
	assert(nextRecording.getLocation().compare("deck K sector X1623") == 0);
	assert(nextRecording.getTimesAccessed() == 7);

	nextRecording = this->recordingController->getNextRecording();

	assert(nextRecording.getTitle().compare("anomaly 2") == 0);
	assert(nextRecording.getLocation().compare("deck T sector X2312") == 0);
	assert(nextRecording.getFootagePreview().compare("prev2.7.mp15") == 0);

	nextRecording = this->recordingController->getNextRecording();

	assert(nextRecording.getTitle().compare("anomaly 5") == 0);
	assert(nextRecording.getTimeOfCreation().compare("01-13-5241") == 0);

	nextRecording = this->recordingController->getNextRecording();

	assert(nextRecording.getTitle().compare("anomaly 1") == 0);

	nextRecording = this->recordingController->getNextRecording();

	assert(nextRecording.getTitle().compare("anomaly 2") == 0);

	this->recordingController->setMode('A');

	this->recordingController->setMode('B');

	nextRecording = this->recordingController->getNextRecording();

	assert(nextRecording.getTitle().compare("anomaly 1") == 0);

	this->recordingController->setMode('A');

	std::vector<Recording> recordingsCopy = this->recordingController->getRecordings();

	this->recordingController->deleteRecording("anomaly 1");
	this->recordingController->deleteRecording("anomaly 2");
	this->recordingController->deleteRecording("anomaly 5");

	this->recordingController->setMode('B');

	nextRecording = this->recordingController->getNextRecording();

	assert(nextRecording.getTitle().empty());

	this->recordingController->setMode('A');

	for (auto recording : recordingsCopy) {
		this->recordingController->addRecording(recording.getTitle(), recording.getLocation(), recording.getTimeOfCreation(),
			recording.getTimesAccessed(), recording.getFootagePreview());
	}

	this->recordingController->setMode('B');
}

void Testing::testSaveRecording() {
	this->recordingController->saveRecording("anomaly 1");
	this->recordingController->saveRecording("anomaly 5");

	std::vector<Recording> watchlist = this->recordingController->getWatchlist();

	assert(watchlist.size() == 2);
	assert(watchlist[0].getTitle().compare("anomaly 1") == 0);
	assert(watchlist[0].getLocation().compare("deck K sector X1623") == 0);
	assert(watchlist[0].getFootagePreview().compare("prev1.2.mp15") == 0);
	assert(watchlist[1].getTitle().compare("anomaly 5") == 0);
	assert(watchlist[1].getTimeOfCreation().compare("01-13-5241") == 0);

	try {
		this->recordingController->saveRecording("anomaly 1");
	} catch (std::exception& exception) {
		assert(std::string(exception.what()).compare("Recording with given title doesn't exist or was already saved in your watchlist.") == 0);
	}
}

void Testing::testgetRecordingsByLocationAndTimesAccessed() {
	std::vector<Recording> recordingsByLocationAndTimesAccessed = this->recordingController->getRecordingsByLocationAndTimesAccessed("deck T sector X2312", 9);

	assert(recordingsByLocationAndTimesAccessed.size() == 2);
	assert(recordingsByLocationAndTimesAccessed[0].getTitle().compare("anomaly 2") == 0);
	assert(recordingsByLocationAndTimesAccessed[0].getLocation().compare("deck T sector X2312") == 0);
	assert(recordingsByLocationAndTimesAccessed[0].getFootagePreview().compare("prev2.7.mp15") == 0);
	assert(recordingsByLocationAndTimesAccessed[1].getTitle().compare("anomaly 5") == 0);
	assert(recordingsByLocationAndTimesAccessed[1].getLocation().compare("deck T sector X2312") == 0);
	assert(recordingsByLocationAndTimesAccessed[1].getTimeOfCreation().compare("01-13-5241") == 0);
}

void Testing::testGetWatchlist() {
	std::vector<Recording> watchlist = this->recordingController->getWatchlist();

	assert(watchlist.size() == 2);
	assert(watchlist[0].getTitle().compare("anomaly 1") == 0);
	assert(watchlist[0].getLocation().compare("deck K sector X1623") == 0);
	assert(watchlist[0].getFootagePreview().compare("prev1.2.mp15") == 0);
	assert(watchlist[1].getTitle().compare("anomaly 5") == 0);
	assert(watchlist[1].getTimeOfCreation().compare("01-13-5241") == 0);
}

void Testing::testSetFileLocation() {
	std::vector<Recording> recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 3);

	this->recordingController->setFileLocation(".\\TestInput.txt");

	recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 7);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[1].getLocation().compare("deck C sector X1622") == 0);
	assert(recordings[2].getLocation().compare("deck T sector X4225") == 0);
	assert(recordings[2].getTimeOfCreation().compare("01-13-5343") == 0);
	assert(recordings[3].getTimeOfCreation().compare("01-13-3238") == 0);
	assert(recordings[3].getTimesAccessed() == 2);
	assert(recordings[4].getFootagePreview().compare("prev5.2.mp15") == 0);

	this->recordingController->addRecording("anomaly 8", "deck G sector X5323", "01-13-2312", 6, "prev8.2.mp15");

	recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 8);
	assert(recordings[7].getTitle().compare("anomaly 8") == 0);
	assert(recordings[7].getLocation().compare("deck G sector X5323") == 0);
	assert(recordings[7].getTimeOfCreation().compare("01-13-2312") == 0);
	assert(recordings[7].getTimesAccessed() == 6);
	assert(recordings[7].getFootagePreview().compare("prev8.2.mp15") == 0);

	this->recordingController->updateRecording("anomaly 8", "deck H sector X2341", "01-13-6433", 8, "prev8.3.mp15");

	recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 8);
	assert(recordings[7].getTitle().compare("anomaly 8") == 0);
	assert(recordings[7].getLocation().compare("deck H sector X2341") == 0);
	assert(recordings[7].getTimeOfCreation().compare("01-13-6433") == 0);
	assert(recordings[7].getTimesAccessed() == 8);
	assert(recordings[7].getFootagePreview().compare("prev8.3.mp15") == 0);

	this->recordingController->deleteRecording("anomaly 8");

	recordings = this->recordingController->getRecordings();

	assert(recordings.size() == 7);
}

void Testing::printTestsPassed() {
	std::ifstream inputStream(".\\TestsPassed.txt");

	std::string line;

	while (std::getline(inputStream, line)) {
		std::cout << line << "\n";
	}
}

void Testing::runTests() {
	// Try clearance mode functionality.
	this->testSetMode();

	// Testing the functionalities for clearance level A.
	this->recordingController->setMode('A');

	this->testCreateRecording();
	this->testUpdateRecording();
	this->testDeleteRecording();
	this->testGetRecordings();

	// Testing the functionalities for clearance level B.
	this->recordingController->setMode('B');

	this->testGetNextRecording();
	this->testSaveRecording();
	this->testgetRecordingsByLocationAndTimesAccessed();
	this->testGetWatchlist();

	// Testing the operations on a text file.
	this->recordingController->setMode('A');

	this->testSetFileLocation();

	this->printTestsPassed();
}
