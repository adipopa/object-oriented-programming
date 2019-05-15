#include "TilesRepository.h"

void TilesRepository::addTileInRepository(const Tile& tile) {
	this->cleanedTiles.push_back(tile);
}

std::vector<Tile> TilesRepository::getCleanedTilesFromRepository() {
	return this->cleanedTiles;
}
