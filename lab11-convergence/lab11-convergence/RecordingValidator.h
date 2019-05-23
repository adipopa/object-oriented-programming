#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingRepository.h"
#include "WatchlistRepository.h"

class RecordingValidator {

private:
	std::shared_ptr<RecordingRepository> recordingRepository;
	std::shared_ptr<WatchlistRepository> watchlistRepository;

public:
	RecordingValidator(const std::shared_ptr<RecordingRepository>& recordingRepository, const std::shared_ptr<WatchlistRepository>& watchlistRepository);

	bool validateAddRecording(const std::string& title);

	bool validateDeleteRecording(const std::string& title);

	bool validateSaveRecording(const std::string& title);

	~RecordingValidator();
};