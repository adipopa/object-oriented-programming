#pragma once

#include "Tile.h"
#include <vector>
#include <algorithm>

class TilesRepository {

private:
	std::vector<Tile> cleanedTiles;

public:
	TilesRepository() {};

	void addTileInRepository(const Tile& tile);

	std::vector<Tile> getCleanedTilesFromRepository();

	~TilesRepository() {};
};

