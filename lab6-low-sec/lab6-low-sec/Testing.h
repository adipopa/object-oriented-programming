#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>

#include "RecordingController.h"

class Testing {

private:
	RecordingRepository recordingRepository;
	RecordingValidator recordingValidator;
	RecordingController recordingController;

public:
	Testing() : recordingRepository(RecordingRepository{}), recordingValidator(&this->recordingRepository),
		recordingController(&this->recordingValidator, &this->recordingRepository, "high-security") {};
	void testSetMode();

	void testCreateRecording();
	void testUpdateRecording();
	void testDeleteRecording();
	void testGetRecordings();

	void testGetNextRecording();
	void testSaveRecording();
	void testgetRecordingsByLocationAndTimesAccessed();
	void testGetWatchlist();

	void printTestsPassed();

	void runTests();
};