#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

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
};