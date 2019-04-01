#include "RecordingController.h"

int RecordingController::setMode(const char mode) {
	if (mode == 'A') {
		this->clearanceLevel = "high-security";
		return 0;
	}
	else if (mode == 'B') {
		this->clearanceLevel = "low-security";
		return 0;
	}
	return 1;
}

int RecordingController::addRecording(const std::string& title, const std::string& location, const std::string& timeOfCreation,
	const int& timesAccessed, const std::string& footagePreview) {
	if (this->recordingValidator->validateAddRecording(title) == false) {
		return 1;
	}
	if (this->clearanceLevel.compare("low-security") == 0) {
		return 2;
	}
	Recording recording{ title, location, timeOfCreation, timesAccessed, footagePreview };
	this->recordingRepository->addToRepository(recording);
	return 0;
}

int RecordingController::updateRecording(const std::string& title, const std::string& newLocation, const std::string& newTimeOfCreation,
	const int& newTimesAccessed, const std::string& newFootagePreview) {
	if (this->clearanceLevel.compare("low-security") == 0) {
		return 2;
	}
	Recording newRecording{ title, newLocation, newTimeOfCreation, newTimesAccessed, newFootagePreview };
	this->recordingRepository->updateInRepository(newRecording);
	return 0;
}

int RecordingController::deleteRecording(const std::string& title) {
	if (this->recordingValidator->validateDeleteRecording(title) == false) {
		return 1;
	}
	if (this->clearanceLevel.compare("low-security") == 0) {
		return 2;
	}
	this->recordingRepository->deleteFromRepository(title);
	return 0;
}

DynamicVector<Recording> RecordingController::getRecordings() {
	return this->recordingRepository->getRecordings();
}

std::string RecordingController::getClearanceLevel() const {
	return this->clearanceLevel;
}