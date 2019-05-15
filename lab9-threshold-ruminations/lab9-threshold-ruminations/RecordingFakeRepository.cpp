#include "RecordingFakeRepository.h"

RecordingFakeRepository::RecordingFakeRepository() : RecordingRepository{} {}

void RecordingFakeRepository::addToRepository(const Recording& recording) {
	this->recordings.push_back(recording);
}

RecordingFakeRepository::~RecordingFakeRepository() {}
