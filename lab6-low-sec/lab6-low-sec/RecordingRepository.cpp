#include <string>
#include "RecordingRepository.h"

void RecordingRepository::addToRepository(const Recording& recording) {
	this->recordings.add(recording);
}

void RecordingRepository::updateInRepository(const Recording& newRecording) {
	auto recordingCompareFunction = [newRecording](const Recording& recording) -> bool {
		return recording.getTitle().compare(newRecording.getTitle()) == 0;
	};
	int recordingIndex = this->recordings.getIndex(recordingCompareFunction);
	this->recordings.update(recordingIndex, newRecording);
}

void RecordingRepository::deleteFromRepository(const std::string& title) {
	auto recordingCompareFunction = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	int recordingIndex = this->recordings.getIndex(recordingCompareFunction);
	this->recordings.remove(recordingIndex);
}

DynamicVector<Recording> RecordingRepository::getRecordings() const {
	return this->recordings;
}

DynamicVector<Recording> RecordingRepository::getRecordingsByLocationAndTimesAccessed(const std::string& location, const int timesAccessed) {
	DynamicVector<Recording> filteredRecordings = DynamicVector<Recording>{ this->recordings };
	auto recordingFilterFunction = [location, timesAccessed](const Recording& recording) -> bool {
		return recording.getLocation().find(location) != std::string::npos && recording.getTimesAccessed() < timesAccessed;
	};
	filteredRecordings.filterVector(recordingFilterFunction);
	return filteredRecordings;
}

Recording RecordingRepository::getNextRecording() {
	Recording nextRecording = *this->recordingsIterator;
	this->recordingsIterator++;
	if (this->recordingsIterator == this->recordings.end()) {
		this->recordingsIterator = this->recordings.begin();
	}
	return nextRecording;
}

void RecordingRepository::addToWatchlist(const std::string& title) {
	auto recordingCompareFunction = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	int recordingIndex = this->recordings.getIndex(recordingCompareFunction);
	Recording recording = this->recordings[recordingIndex];
	this->watchlist.add(recording);
}

DynamicVector<Recording> RecordingRepository::getWatchlist() {
	return this->watchlist;
}