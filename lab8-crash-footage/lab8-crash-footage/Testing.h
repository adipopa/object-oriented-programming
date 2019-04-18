#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>

#include "RecordingController.h"

class Testing {

private:
	std::shared_ptr<RecordingRepository> recordingRepository;
	std::shared_ptr<RecordingValidator> recordingValidator;
	std::shared_ptr<RecordingController> recordingController;

public:
	Testing();

	void testSetMode();

	void testCreateRecording();
	void testUpdateRecording();
	void testDeleteRecording();
	void testGetRecordings();

	void testGetNextRecording();
	void testSaveRecording();
	void testgetRecordingsByLocationAndTimesAccessed();
	void testGetWatchlist();

	void testSetFileLocation();

	void printTestsPassed();

	void runTests();
};