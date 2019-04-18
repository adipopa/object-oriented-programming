#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Recording.h"
#include <string>
#include <vector>
#include <algorithm>

class RecordingRepository {

private:
	std::vector<Recording> recordings;

	unsigned int nextRecordingIndex;

	std::vector<Recording> watchlist;

	std::string fileLocation;

public:
	// Default constructor for an RecordingRepository.
	RecordingRepository() {};

	void addToRepository(const Recording& recording);

	void updateInRepository(const Recording& newRecording);

	void deleteFromRepository(const std::string& title);

	std::vector<Recording> getRecordings();

	void initializeIterator();

	Recording getNextRecording();

	void addToWatchlist(const std::string& title);

	std::vector<Recording> getRecordingsByLocationAndTimesAccessed(const std::string& location, const int timesAccessed);

	std::vector<Recording> getWatchlist();

	void setFileLocation(const std::string& fileLocation);

	void loadFileData();

	void saveDataToFile();
};