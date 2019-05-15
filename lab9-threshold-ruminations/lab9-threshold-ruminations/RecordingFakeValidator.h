#pragma once

#include "RecordingValidator.h"

class RecordingFakeValidator : public RecordingValidator {

public:
	RecordingFakeValidator(const std::shared_ptr<RecordingRepository>& recordingRepository, const std::shared_ptr<WatchlistRepository>& watchlistRepository);

	~RecordingFakeValidator();
};

