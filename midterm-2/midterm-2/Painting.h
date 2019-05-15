#pragma once

#include <string>

class Painting {

private:
	std::string title;
	std::string artist;
	int year;

public:
	Painting();

	Painting(std::string title, std::string artist, int year);

	bool isEqual(const Painting& paintingToCompare) const;

	std::string toString();

	~Painting();
};

