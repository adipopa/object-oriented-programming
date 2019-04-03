#include "Recording.h"

Recording::Recording(): title(""), location(""), timeOfCreation(""), timesAccessed(0), footagePreview("") {}

Recording::Recording(const std::string& title, const std::string& location, const std::string& timeOfCreation,
	const int& timesAccessed, const std::string& footagePreview) {
	this->title = title;
	this->location = location;
	this->timeOfCreation = timeOfCreation;
	this->timesAccessed = timesAccessed;
	this->footagePreview = footagePreview;
}