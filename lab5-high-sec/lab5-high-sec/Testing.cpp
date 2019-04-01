#include "Testing.h"

void Testing::testCreateRecording() {
	this->recordingController.addRecording("anomaly 1", "deck D sector X1423", "01-13-3248", 5, "prev1.mp15");
	this->recordingController.addRecording("anomaly 2", "deck E sector X1542", "01-13-3538", 8, "prev2.mp15");
	this->recordingController.addRecording("anomaly 3", "deck F sector X4125", "01-13-4248", 3, "prev3.mp15");
	this->recordingController.addRecording("anomaly 4", "deck C sector X2142", "01-13-7238", 2, "prev4.mp15");
	this->recordingController.addRecording("anomaly 5", "deck B sector X6433", "01-13-5241", 4, "prev5.mp15");

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
}

void Testing::testDeleteRecording() {
}

void Testing::testGetRecordings() {
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
	this->testCreateRecording();
	this->testUpdateRecording();
	this->testDeleteRecording();
	this->testGetRecordings();
	this->testUpdateRecording();

	this->printTestsPassed();
}
