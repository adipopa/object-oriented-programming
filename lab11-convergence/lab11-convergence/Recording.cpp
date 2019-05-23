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

std::istream& operator>>(std::istream& inputStream, Recording& recording) {
	std::string inputData;
	std::getline(inputStream, inputData);

	int position = inputData.find(", ");
	std::string currentToken = inputData.substr(0, position);
	recording.setTitle(currentToken);
	inputData.erase(0, position + 2);

	position = inputData.find(", ");
	currentToken = inputData.substr(0, position);
	recording.setLocation(currentToken);
	inputData.erase(0, position + 2);

	position = inputData.find(", ");
	currentToken = inputData.substr(0, position);
	recording.setTimeOfCreation(currentToken);
	inputData.erase(0, position + 2);

	position = inputData.find(", ");
	currentToken = inputData.substr(0, position);
	recording.setTimesAccessed(atoi(currentToken.c_str()));
	inputData.erase(0, position + 2);

	currentToken = inputData.substr(0, inputData.size());
	recording.setFootagePreview(currentToken);

	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Recording& recording) {
	outputStream << recording.getTitle() << ", " << recording.getLocation() << ", " << recording.getTimeOfCreation() << ", " <<
		recording.getTimesAccessed() << ", " << recording.getFootagePreview() << "\n";
	return outputStream;
}
