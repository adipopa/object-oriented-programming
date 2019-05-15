#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <fstream>

class Recording {

private:
	std::string title;
	std::string location;
	std::string timeOfCreation;
	int timesAccessed;
	std::string footagePreview;

public:
	// Default constructor for an Recording.
	Recording();

	// Constructor with parameters.
	Recording(const std::string& title, const std::string& location, const std::string& timeOfCreation, const int& timesAccessed, const std::string& footagePreview);

	std::string getTitle() const { return title; }
	std::string getLocation() const { return location; }
	std::string getTimeOfCreation() const { return timeOfCreation; }
	int getTimesAccessed() const { return timesAccessed; }
	std::string getFootagePreview() const { return footagePreview; }

	void setTitle(const std::string& title) { this->title = title; };
	void setLocation(const std::string& location) { this->location = location; };
	void setTimeOfCreation(const std::string& timeOfCreation) { this->timeOfCreation = timeOfCreation; };
	void setTimesAccessed(const int& timesAccessed) { this->timesAccessed = timesAccessed; };
	void setFootagePreview(const std::string& footagePreview) { this->footagePreview = footagePreview; };

	friend std::istream& operator>>(std::istream& inputStream, Recording& recording);

	friend std::ostream& operator<<(std::ostream& outputStream, const Recording& recording);
};