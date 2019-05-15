#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "DynamicVector.h"
#include "Recording.h"

class RecordingRepository {

private:
	DynamicVector<Recording> recordings;
	DynamicVector<Recording>::Iterator recordingsIterator;

	DynamicVector<Recording> watchlist;

public:
	// Default constructor for an RecordingRepository.
	RecordingRepository(): recordingsIterator(recordings.begin()) {};

	void addToRepository(const Recording& recording);

	void updateInRepository(const Recording& newRecording);

	void deleteFromRepository(const std::string& title);

	void initializeIterator();

	DynamicVector<Recording> getRecordings() const;

	Recording getNextRecording();

	void addToWatchlist(const std::string& title);

	DynamicVector<Recording> getRecordingsByLocationAndTimesAccessed(const std::string& location, const int timesAccessed);

	DynamicVector<Recording> getWatchlist();
};