#pragma once

#include "Painting.h"
#include <vector>
#include <algorithm>

class Repository {

private:
	std::vector<Painting> paintings;

public:
	Repository();

	void addPainting(Painting painting);
	void removePainting(Painting painting);
	std::vector<Painting> getAll();

	~Repository();
};

