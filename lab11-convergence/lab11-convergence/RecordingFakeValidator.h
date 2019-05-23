#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingValidator.h"

class RecordingFakeValidator : public RecordingValidator {

public:
	RecordingFakeValidator(const std::shared_ptr<RecordingRepository>& recordingRepository, const std::shared_ptr<WatchlistRepository>& watchlistRepository);

	~RecordingFakeValidator();
};

