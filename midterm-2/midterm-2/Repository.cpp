#include "Repository.h"

Repository::Repository() {}

void Repository::addPainting(Painting painting) {
	this->paintings.push_back(painting);
}

void Repository::removePainting(Painting paintingToRemove) {
	auto paintingCompareFn = [paintingToRemove](const Painting& painting) -> bool {
		return painting.isEqual(paintingToRemove);
	};
	auto paintingsIterator = std::find_if(this->paintings.begin(), this->paintings.end(), paintingCompareFn);
	if (paintingsIterator == this->paintings.end()) {
		return;
	}
	this->paintings.erase(paintingsIterator);
}

std::vector<Painting> Repository::getAll() {
	return this->paintings;
}

Repository::~Repository() {}
