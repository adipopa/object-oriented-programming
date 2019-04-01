#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "DynamicVector.h"
#include "Recording.h"

class RecordingRepository {

private:
	DynamicVector<Recording> recordings;

public:
	// Default constructor for an RecordingRepository.
	RecordingRepository() {};

	void addToRepository(const Recording& recording);

	void updateInRepository(const Recording& newRecording);

	void deleteFromRepository(const std::string& title);

	DynamicVector<Recording> getRecordings() const;
};