#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingRepository.h"

class RecordingFakeRepository : public RecordingRepository {

public:
	// Default constructor for an RecordingFakeRepository.
	RecordingFakeRepository();

	void addToRepository(const Recording& recording) override;

	~RecordingFakeRepository();
};