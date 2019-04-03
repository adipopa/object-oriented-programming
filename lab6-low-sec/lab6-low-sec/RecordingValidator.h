#pragma once
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingRepository.h"

class RecordingValidator {

private:
	RecordingRepository* recordingRepository;

public:
	RecordingValidator(RecordingRepository* recordingRepository) : recordingRepository(recordingRepository) {}

	bool validateAddRecording(const std::string& title);

	bool validateDeleteRecording(const std::string& title);

	bool validateSaveRecording(const std::string& title);
};