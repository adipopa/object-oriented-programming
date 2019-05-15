#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingController.h"

using namespace std;

class Console {

private:
	shared_ptr<RecordingController> recordingController;

public:
	Console(const shared_ptr<RecordingController>& recordingController);

	void runConsole();

	void uiSelectMode(string inputString);

	void uiAddRecording(string inputString);

	void uiUpdateRecording(string inputString);

	void uiDeleteRecording(string inputString);

	void uiListRecordings(string inputString);

	void uiNextRecording(string inputString);

	void uiSaveRecording(string inputString);

	void uiSeeWatchlist(string inputString);

	void uiSetFileLocation(string inputString);

	void uiSetMylistLocation(string inputString);

	void uiOpenMylist(string inputString);
};