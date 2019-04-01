#include <string>
#include "RecordingRepository.h"

void RecordingRepository::addToRepository(const Recording& recording) {
	this->recordings.add(recording);
}

void RecordingRepository::updateInRepository(const Recording& newRecording) {
	auto recordingCompareFn = [newRecording](const Recording& recording) -> bool {
		return recording.getTitle().compare(newRecording.getTitle()) == 0;
	};
	int recordingIndex = this->recordings.getIndex(recordingCompareFn);
	this->recordings.update(recordingIndex, newRecording);
}

void RecordingRepository::deleteFromRepository(const std::string& title) {
	auto recordingCompareFn = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	int recordingIndex = this->recordings.getIndex(recordingCompareFn);
	this->recordings.remove(recordingIndex);
}

DynamicVector<Recording> RecordingRepository::getRecordings() const {
	return this->recordings;
}
