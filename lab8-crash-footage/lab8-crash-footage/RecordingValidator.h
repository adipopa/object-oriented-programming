#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingRepository.h"

class RecordingValidator {

private:
	std::shared_ptr<RecordingRepository> recordingRepository;

public:
	RecordingValidator() {}

	RecordingValidator(const std::shared_ptr<RecordingRepository>& recordingRepository) : recordingRepository{ recordingRepository } {}

	bool validateAddRecording(const std::string& title);

	bool validateDeleteRecording(const std::string& title);

	bool validateSaveRecording(const std::string& title);
};