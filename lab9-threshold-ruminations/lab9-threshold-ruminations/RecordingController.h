#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingValidator.h"
#include "RecordingRepository.h"
#include "WatchlistRepository.h"
#include "WatchlistCSVRepository.h"
#include "WatchlistHTMLRepository.h"

class RecordingController {

private:
	std::shared_ptr<RecordingValidator> recordingValidator;
	std::shared_ptr<RecordingRepository> recordingRepository;
	std::shared_ptr<WatchlistRepository> watchlistRepository;
	std::string clearanceLevel;

public:
	RecordingController(const std::shared_ptr<RecordingValidator>& recordingValidator, const std::shared_ptr<RecordingRepository>& recordingRepository,
		const std::shared_ptr<WatchlistRepository>& watchlistRepository, const std::string& clearanceLevel);

	void setMode(const char mode);

	void addRecording(const std::string& title, const std::string& location, const std::string& timeOfCreation,
		const int& timesAccessed, const std::string& footagePreview);

	void updateRecording(const std::string& title, const std::string& newLocation, const std::string& newTimeOfCreation,
		const int& newTimesAccessed, const std::string& newFootagePreview);

	void deleteRecording(const std::string& title);

	std::vector<Recording> getRecordings();

	Recording getNextRecording();

	void saveRecording(const std::string& title);

	std::vector<Recording> getRecordingsByLocationAndTimesAccessed(const std::string& location, const int timesAccessed);

	std::vector<Recording> getWatchlist();

	void setFileLocation(const std::string& fileLocation);

	void setMylistLocation(const std::string& mylistLocation);

	void openMylist();
};