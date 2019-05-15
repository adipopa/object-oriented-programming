#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Recording.h"
#include "RecordingException.h"
#include <vector>
#include <algorithm>

class RecordingRepository {

protected:
	std::vector<Recording> recordings;
	unsigned int nextRecordingIndex;

	std::string fileLocation;

public:
	// Default constructor for an RecordingRepository.
	RecordingRepository();

	virtual void addToRepository(const Recording& recording);

	void updateInRepository(const Recording& newRecording);

	void deleteFromRepository(const std::string& title);

	std::vector<Recording> getRecordings();

	void initializeIterator();

	Recording getNextRecording();

	std::vector<Recording> getRecordingsByLocationAndTimesAccessed(const std::string& location, const int timesAccessed);

	void setFileLocation(const std::string& fileLocation);

	void loadFileData();

	void saveDataToFile();

	~RecordingRepository();
};