#include "RecordingController.h"

RecordingController::RecordingController(const std::shared_ptr<RecordingValidator>& recordingValidator, const std::shared_ptr<RecordingRepository>& recordingRepository,
	const std::shared_ptr<WatchlistRepository>& watchlistRepository, const std::string & clearanceLevel) :
	recordingValidator{ recordingValidator }, recordingRepository{ recordingRepository }, watchlistRepository{ watchlistRepository }, clearanceLevel{ clearanceLevel } {}

void RecordingController::setMode(const char mode) {
	if (mode == 'A') {
		this->clearanceLevel = "high-security";
		return;
	}
	if (mode == 'B') {
		this->clearanceLevel = "low-security";
		this->recordingRepository->initializeIterator();
		return;
	}
	throw RecordingException("Invalid mode type (valid options are A/B).");
}

void RecordingController::addRecording(const std::string& title, const std::string& location, const std::string& timeOfCreation,
	const int& timesAccessed, const std::string& footagePreview) {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to add a new recording.");
	}
	if (this->recordingValidator->validateAddRecording(title) == false) {
		throw RecordingException("Recording with given title already exists.");
	}
	Recording recording{ title, location, timeOfCreation, timesAccessed, footagePreview };
	this->recordingRepository->addToRepository(recording);
}

void RecordingController::updateRecording(const std::string& title, const std::string& newLocation, const std::string& newTimeOfCreation,
	const int& newTimesAccessed, const std::string& newFootagePreview) {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to update a recording.");
	}
	Recording newRecording{ title, newLocation, newTimeOfCreation, newTimesAccessed, newFootagePreview };
	this->recordingRepository->updateInRepository(newRecording);
}

void RecordingController::deleteRecording(const std::string& title) {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to remove a recording.");
	}
	if (this->recordingValidator->validateDeleteRecording(title) == false) {
		throw RecordingException("Recording with given title doesn't exist.");
	}
	this->recordingRepository->deleteFromRepository(title);
}

std::vector<Recording> RecordingController::getRecordings() {
	if (this->clearanceLevel.compare("high-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to list the recordings.");
	}
	return this->recordingRepository->getRecordings();
}

Recording RecordingController::getNextRecording() {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to play a recording preview.");
	}
	return this->recordingRepository->getNextRecording();
}

void RecordingController::saveRecording(const std::string& title) {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to save a recording to your watchlist.");
	}
	if (this->recordingValidator->validateSaveRecording(title) == false) {
		throw RecordingException("Recording with given title doesn't exist or was already saved in your watchlist.");
	}
	std::vector<Recording> recordings = this->recordingRepository->getRecordings();
	auto recordingCompareFunction = [title](const Recording& recording) -> bool {
		return recording.getTitle().compare(title) == 0;
	};
	auto recordingIt = std::find_if(recordings.begin(), recordings.end(), recordingCompareFunction);
	Recording recording = (Recording)*recordingIt;
	this->watchlistRepository->saveToWatchlist(recording);
}

std::vector<Recording> RecordingController::getRecordingsByLocationAndTimesAccessed(const std::string & location, const int timesAccessed) {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to list the recordings by location and times accessed.");
	}
	return this->recordingRepository->getRecordingsByLocationAndTimesAccessed(location, timesAccessed);
}

std::vector<Recording> RecordingController::getWatchlist() {
	if (this->clearanceLevel.compare("low-security") != 0) {
		throw RecordingException("You don't have the necessary clearance to see your watchlist.");
	}
	return this->watchlistRepository->getWatchlist();
}

void RecordingController::setFileLocation(const std::string & fileLocation) {
	this->recordingRepository->setFileLocation(fileLocation);
}

void RecordingController::setMylistLocation(const std::string & mylistLocation) {
	std::vector<Recording> currentWatchlist = this->watchlistRepository->getWatchlist();
	std::size_t foundCSV = mylistLocation.find(".csv");
	std::size_t foundHTML = mylistLocation.find(".html");
	if (foundCSV != std::string::npos) {
		this->watchlistRepository = std::make_shared<WatchlistCSVRepository>(currentWatchlist);
	}
	else if (foundHTML != std::string::npos) {
		this->watchlistRepository = std::make_shared<WatchlistHTMLRepository>(currentWatchlist);
	}
	else {
		throw RecordingException("Invalid file type for mylist location, please provide a CSV / HTML file.");
	}
	this->recordingValidator = std::make_shared<RecordingValidator>(this->recordingRepository, this->watchlistRepository);
	this->watchlistRepository->setMylistLocation(mylistLocation);
}

void RecordingController::openMylist() {
	this->watchlistRepository->openMylist();
}
