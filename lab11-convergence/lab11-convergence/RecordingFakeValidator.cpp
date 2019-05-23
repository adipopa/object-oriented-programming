#include "RecordingFakeValidator.h"

RecordingFakeValidator::RecordingFakeValidator(const std::shared_ptr<RecordingRepository>& recordingRepository, const std::shared_ptr<WatchlistRepository>& watchlistRepository) :
	RecordingValidator{recordingRepository, watchlistRepository} {}

RecordingFakeValidator::~RecordingFakeValidator() {}
