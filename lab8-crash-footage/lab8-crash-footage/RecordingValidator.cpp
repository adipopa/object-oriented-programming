#include "RecordingValidator.h"

bool RecordingValidator::validateAddRecording(const std::string& title) {
	std::vector<Recording> recordings = this->recordingRepository->getRecordings();
	auto recordingCompareFn = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	auto recordingsIterator = std::find_if(recordings.begin(), recordings.end(), recordingCompareFn);
	return recordingsIterator == recordings.end();
}

bool RecordingValidator::validateDeleteRecording(const std::string& title) {
	std::vector<Recording> recordings = this->recordingRepository->getRecordings();
	auto recordingCompareFn = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	auto recordingsIterator = std::find_if(recordings.begin(), recordings.end(), recordingCompareFn);
	return recordingsIterator != recordings.end();
}

bool RecordingValidator::validateSaveRecording(const std::string& title) {
	std::vector<Recording> recordings = this->recordingRepository->getRecordings();
	std::vector<Recording> watchlist = this->recordingRepository->getWatchlist();
	auto recordingCompareFn = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	auto recordingsIterator = std::find_if(recordings.begin(), recordings.end(), recordingCompareFn);
	auto watchlistIterator = std::find_if(watchlist.begin(), watchlist.end(), recordingCompareFn);
	return recordingsIterator != recordings.end() && watchlistIterator == watchlist.end();
}