#include "Painting.h"

Painting::Painting() {}

Painting::Painting(std::string title, std::string artist, int year) : title{ title }, artist{ artist }, year{ year } {}

bool Painting::isEqual(const Painting& paintingToCompare) const {
	return this->title == paintingToCompare.title && this->artist == paintingToCompare.artist &&
		this->year == paintingToCompare.year;
}

std::string Painting::toString() {
	return "Artist: " + this->artist + ", title: " + this->title + ", year: " + std::to_string(this->year) + "\n";
}

Painting::~Painting() {}
