#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>

#include "RecordingFakeRepository.h"
#include "WatchlistFakeRepository.h"
#include "RecordingFakeValidator.h"
#include "RecordingController.h"

class Testing {

private:

public:
	Testing();

	void testAddRecording();

	void printTestsPassed();

	void runTests();
};