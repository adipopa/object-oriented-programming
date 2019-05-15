#include "RecordingRepository.h"

RecordingRepository::RecordingRepository() {}

void RecordingRepository::addToRepository(const Recording & recording) {
	this->loadFileData();
	this->recordings.push_back(recording);
	this->saveDataToFile();
}


void RecordingRepository::updateInRepository(const Recording& newRecording) {
	this->loadFileData();
	auto recordingCompareFunction = [newRecording](const Recording& recording) -> bool {
		return recording.getTitle().compare(newRecording.getTitle()) == 0;
	};
	auto recordingsIterator = std::find_if(this->recordings.begin(), this->recordings.end(), recordingCompareFunction);
	int recordingIndex = std::distance(this->recordings.begin(), recordingsIterator);
	this->recordings[recordingIndex] = newRecording;
	this->saveDataToFile();
}

void RecordingRepository::deleteFromRepository(const std::string& title) {
	this->loadFileData();
	auto recordingCompareFunction = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	auto recordingsIterator = std::find_if(this->recordings.begin(), this->recordings.end(), recordingCompareFunction);
	this->recordings.erase(recordingsIterator);
	this->saveDataToFile();
}

std::vector<Recording> RecordingRepository::getRecordings() {
	this->loadFileData();
	return this->recordings;
}

void RecordingRepository::initializeIterator() {
	this->nextRecordingIndex = 0;
}

Recording RecordingRepository::getNextRecording() {
	if (this->recordings.size() == 0) {
		return Recording();
	}
	if (this->nextRecordingIndex >= this->recordings.size()) {
		this->nextRecordingIndex = 0;
	}
	Recording nextRecording = (Recording)this->recordings[this->nextRecordingIndex];
	this->nextRecordingIndex++;
	return nextRecording;
}

std::vector<Recording> RecordingRepository::getRecordingsByLocationAndTimesAccessed(const std::string& location, const int timesAccessed) {
	this->loadFileData();
	std::vector<Recording> filteredRecordings = std::vector<Recording>{};
	auto recordingFilterFunction = [location, timesAccessed](const Recording& recording) -> bool {
		return recording.getLocation().find(location) != std::string::npos && recording.getTimesAccessed() < timesAccessed;
	};
	std::copy_if(this->recordings.begin(), this->recordings.end(), std::back_inserter(filteredRecordings), recordingFilterFunction);
	return filteredRecordings;
}

void RecordingRepository::setFileLocation(const std::string& fileLocation) {
	this->fileLocation = fileLocation;
	this->loadFileData();
}

void RecordingRepository::loadFileData() {
	if (this->fileLocation.empty()) {
		return;
	}

	std::ifstream inputStream(this->fileLocation);

	Recording recording{};
	this->recordings.clear();

	while (inputStream >> recording) {
		this->recordings.push_back(recording);
	}

	inputStream.close();
}

void RecordingRepository::saveDataToFile() {
	if (this->fileLocation.empty()) {
		return;
	}

	std::ofstream outputStream(this->fileLocation);

	for (auto const& recording : this->recordings) {
		outputStream << recording;
	}

	outputStream.close();
}

RecordingRepository::~RecordingRepository() {}
