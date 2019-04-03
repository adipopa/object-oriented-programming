#include "RecordingValidator.h"

bool RecordingValidator::validateAddRecording(const std::string& title) {
	DynamicVector<Recording> recordings = this->recordingRepository->getRecordings();
	auto recordingCompareFn = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	return recordings.getIndex(recordingCompareFn) == -1;
}

bool RecordingValidator::validateDeleteRecording(const std::string& title) {
	DynamicVector<Recording> recordings = this->recordingRepository->getRecordings();
	auto recordingCompareFn = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	return recordings.getIndex(recordingCompareFn) != -1;
}

bool RecordingValidator::validateSaveRecording(const std::string& title) {
	DynamicVector<Recording> recordings = this->recordingRepository->getRecordings();
	DynamicVector<Recording> watchlist = this->recordingRepository->getWatchlist();
	auto recordingCompareFn = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	return recordings.getIndex(recordingCompareFn) != -1 && watchlist.getIndex(recordingCompareFn) == -1;
}