#include "Testing.h"

void Testing::testSetMode() {
	this->recordingController.setMode('A');
	try {
		this->recordingController.addRecording("anomaly 1", "deck D sector X1423", "01-13-3248", 5, "prev1.mp15");
		this->recordingController.updateRecording("anomaly 1", "deck E sector X1542", "0101-13-3538", 8, "prev2.mp15");
		this->recordingController.deleteRecording("anomaly 1");
		this->recordingController.getRecordings();
		assert(true);
	}
	catch (std::exception&) {
		assert(false);
	}

	this->recordingController.addRecording("anomaly 1", "deck D sector X1423", "01-13-3248", 5, "prev1.mp15");

	this->recordingController.setMode('B');
	try {
		this->recordingController.getNextRecording();
		this->recordingController.saveRecording("anomaly 1");
		this->recordingController.getRecordingsByLocationAndTimesAccessed("deck E sector X1542", 9);
		this->recordingController.getWatchlist();
		assert(true);
	}
	catch (std::exception&) {
		assert(false);
	}

	this->recordingController.setMode('A');
	this->recordingController.deleteRecording("anomaly 1");
}

void Testing::testCreateRecording() {
	this->recordingController.addRecording("anomaly 1", "deck D sector X1423", "01-13-3248", 5, "prev1.mp15");
	this->recordingController.addRecording("anomaly 2", "deck E sector X1542", "01-13-3538", 8, "prev2.mp15");
	this->recordingController.addRecording("anomaly 3", "deck F sector X4125", "01-13-4248", 3, "prev3.mp15");
	this->recordingController.addRecording("anomaly 4", "deck C sector X2142", "01-13-7238", 2, "prev4.mp15");
	this->recordingController.addRecording("anomaly 5", "deck T sector X2312", "01-13-5241", 4, "prev5.mp15");

	DynamicVector<Recording> recordings = this->recordingController.getRecordings();

	assert(recordings.getSize() == 5);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[1].getLocation().compare("deck E sector X1542") == 0);
	assert(recordings[2].getLocation().compare("deck F sector X4125") == 0);
	assert(recordings[2].getTimeOfCreation().compare("01-13-4248") == 0);
	assert(recordings[3].getTimeOfCreation().compare("01-13-7238") == 0);
	assert(recordings[3].getTimesAccessed() == 2);
	assert(recordings[4].getFootagePreview().compare("prev5.mp15") == 0);
}

void Testing::testUpdateRecording() {
	this->recordingController.updateRecording("anomaly 1", "deck K sector X1623", "01-13-3448", 7, "prev1.2.mp15");
	this->recordingController.updateRecording("anomaly 2", "deck T sector X2312", "01-13-3238", 6, "prev2.7.mp15");
	this->recordingController.updateRecording("anomaly 3", "deck B sector X9512", "01-13-1248", 5, "prev3.4.mp15");

	DynamicVector<Recording> recordings = this->recordingController.getRecordings();

	assert(recordings.getSize() == 5);
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
	this->recordingController.deleteRecording("anomaly 3");
	this->recordingController.deleteRecording("anomaly 4");

	DynamicVector<Recording> recordings = this->recordingController.getRecordings();

	assert(recordings.getSize() == 3);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[0].getLocation().compare("deck K sector X1623") == 0);
	assert(recordings[1].getLocation().compare("deck T sector X2312") == 0);
	assert(recordings[1].getTimeOfCreation().compare("01-13-3238") == 0);
	assert(recordings[2].getTitle().compare("anomaly 5") == 0);
	assert(recordings[2].getFootagePreview().compare("prev5.mp15") == 0);
}

void Testing::testGetRecordings() {
	DynamicVector<Recording> recordings = this->recordingController.getRecordings();

	assert(recordings.getSize() == 3);
	assert(recordings[0].getTitle().compare("anomaly 1") == 0);
	assert(recordings[0].getLocation().compare("deck K sector X1623") == 0);
	assert(recordings[1].getLocation().compare("deck T sector X2312") == 0);
	assert(recordings[1].getTimeOfCreation().compare("01-13-3238") == 0);
	assert(recordings[2].getTitle().compare("anomaly 5") == 0);
	assert(recordings[2].getFootagePreview().compare("prev5.mp15") == 0);
}

void Testing::testGetNextRecording() {
	Recording recording1 = this->recordingController.getNextRecording();

	assert(recording1.getTitle().compare("anomaly 1") == 0);
	assert(recording1.getLocation().compare("deck K sector X1623") == 0);
	assert(recording1.getTimesAccessed() == 7);

	Recording recording2 = this->recordingController.getNextRecording();

	assert(recording2.getTitle().compare("anomaly 2") == 0);
	assert(recording2.getLocation().compare("deck T sector X2312") == 0);
	assert(recording2.getFootagePreview().compare("prev2.7.mp15") == 0);

	Recording recording3 = this->recordingController.getNextRecording();

	assert(recording3.getTitle().compare("anomaly 5") == 0);
	assert(recording3.getTimeOfCreation().compare("01-13-5241") == 0);

	Recording recording4 = this->recordingController.getNextRecording();

	assert(recording4.getTitle().compare("anomaly 1") == 0);
}

void Testing::testSaveRecording() {
	this->recordingController.saveRecording("anomaly 5");

	DynamicVector<Recording> watchlist = this->recordingController.getWatchlist();

	assert(watchlist.getSize() == 2);
	assert(watchlist[0].getTitle().compare("anomaly 1") == 0);
	assert(watchlist[0].getLocation().compare("deck D sector X1423") == 0);
	assert(watchlist[0].getFootagePreview().compare("prev1.mp15") == 0);
	assert(watchlist[1].getTitle().compare("anomaly 5") == 0);
	assert(watchlist[1].getTimeOfCreation().compare("01-13-5241") == 0);
}

void Testing::testgetRecordingsByLocationAndTimesAccessed() {
	DynamicVector<Recording> recordingsByLocationAndTimesAccessed = this->recordingController.getRecordingsByLocationAndTimesAccessed("deck T sector X2312", 9);

	assert(recordingsByLocationAndTimesAccessed.getSize() == 2);
	assert(recordingsByLocationAndTimesAccessed[0].getTitle().compare("anomaly 2") == 0);
	assert(recordingsByLocationAndTimesAccessed[0].getLocation().compare("deck T sector X2312") == 0);
	assert(recordingsByLocationAndTimesAccessed[0].getFootagePreview().compare("prev2.7.mp15") == 0);
	assert(recordingsByLocationAndTimesAccessed[1].getTitle().compare("anomaly 5") == 0);
	assert(recordingsByLocationAndTimesAccessed[1].getLocation().compare("deck T sector X2312") == 0);
	assert(recordingsByLocationAndTimesAccessed[1].getTimeOfCreation().compare("01-13-5241") == 0);
}

void Testing::testGetWatchlist() {
	DynamicVector<Recording> watchlist = this->recordingController.getWatchlist();

	assert(watchlist.getSize() == 2);
	assert(watchlist[0].getTitle().compare("anomaly 1") == 0);
	assert(watchlist[0].getLocation().compare("deck D sector X1423") == 0);
	assert(watchlist[0].getFootagePreview().compare("prev1.mp15") == 0);
	assert(watchlist[1].getTitle().compare("anomaly 5") == 0);
	assert(watchlist[1].getTimeOfCreation().compare("01-13-5241") == 0);
}

void Testing::printTestsPassed() {
	FILE *fp = fopen("TestsPassed.txt", "r");
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}
	printf("\n\n");
	fclose(fp);
}

void Testing::runTests() {
	// Try clearance mode functionality.
	this->testSetMode();

	// Testing the functionalities for clearance level A.
	this->recordingController.setMode('A');

	this->testCreateRecording();
	this->testUpdateRecording();
	this->testDeleteRecording();
	this->testGetRecordings();

	// Testing the functionalities for clearance level B.
	this->recordingController.setMode('B');

	// this->testGetNextRecording();
	this->testSaveRecording();
	this->testgetRecordingsByLocationAndTimesAccessed();
	this->testGetWatchlist();

	this->printTestsPassed();
}
