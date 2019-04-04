#include "RecordingController.h"

void RecordingController::setMode(const char mode) {
	if (mode == 'A') {
		this->clearanceLevel = "high-security";
		return;
	}
	if (mode == 'B') {
		this->clearanceLevel = "low-security";
		return;
	}
	throw std::runtime_error("Invalid mode type (valid options are A/B).");
}

void RecordingController::addRecording(const std::string& title, const std::string& location, const std::string& timeOfCreation,
	const int& timesAccessed, const std::string& footagePreview) {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to add a new recording.");
	}
	if (this->recordingValidator->validateAddRecording(title) == false) {
		throw std::runtime_error("Recording with given title already exists.");
	}
	Recording recording{ title, location, timeOfCreation, timesAccessed, footagePreview };
	this->recordingRepository->addToRepository(recording);
}

void RecordingController::updateRecording(const std::string& title, const std::string& newLocation, const std::string& newTimeOfCreation,
	const int& newTimesAccessed, const std::string& newFootagePreview) {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to update a recording.");
	}
	Recording newRecording{ title, newLocation, newTimeOfCreation, newTimesAccessed, newFootagePreview };
	this->recordingRepository->updateInRepository(newRecording);
}

void RecordingController::deleteRecording(const std::string& title) {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to remove a recording.");
	}
	if (this->recordingValidator->validateDeleteRecording(title) == false) {
		throw std::runtime_error("Recording with given title doesn't exist.");
	}
	this->recordingRepository->deleteFromRepository(title);
}

DynamicVector<Recording> RecordingController::getRecordings() const {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to list the recordings.");
	}
	return this->recordingRepository->getRecordings();
}

Recording RecordingController::getNextRecording() {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to play a recording preview.");
	}
	if (this->recordingRepository->getRecordings().getSize() == 0) {
		throw std::runtime_error("No entries in the list, nothing to show.");
	}
	return this->recordingRepository->getNextRecording();
}

void RecordingController::saveRecording(const std::string& title) {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to save a recording to your watchlist.");
	}
	if (this->recordingValidator->validateSaveRecording(title) == false) {
		throw std::runtime_error("Recording with given title doesn't exist or was already saved in your watchlist.");
	}
	this->recordingRepository->addToWatchlist(title);
}

DynamicVector<Recording> RecordingController::getRecordingsByLocationAndTimesAccessed(const std::string & location, const int timesAccessed) {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to list the recordings by location and times accessed.");
	}
	return this->recordingRepository->getRecordingsByLocationAndTimesAccessed(location, timesAccessed);
}

DynamicVector<Recording> RecordingController::getWatchlist() {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw std::runtime_error("You don't have the necessary clearance to see your watchlist.");
	}
	return this->recordingRepository->getWatchlist();
}

