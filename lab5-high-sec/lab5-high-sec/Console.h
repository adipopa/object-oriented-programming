#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingController.h"

class Console {

private:
	RecordingController* recordingController;

public:
	Console(RecordingController* recordingController) : recordingController(recordingController) {}

	int uiSelectMode(char* currentToken);

	int uiAddRecording(char* inputString);

	int uiUpdateRecording(char* currentToken);

	int uiDeleteRecording(char* currentToken);

	int uiListRecordings(char* currentToken);

	void runConsole();
};