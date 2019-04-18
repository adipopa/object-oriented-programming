#include "DroneController.h"

// Method for placing the cleaning drone on a starting position (droneXStartPosition, droneYStartPosition).
// The method sets the drone's initial position, also adding the starting tile to the TilesRepository's list of tiles.
void DroneController::placeDrone(const int & droneXStartPosition, const int & droneYStartPosition) {
	this->drone = Drone{ droneXStartPosition, droneYStartPosition };

	Tile newTile{ droneXStartPosition, droneYStartPosition };
	this->tilesRepository.addTileInRepository(newTile);
}

// Method for moving the cleaning drone, given a direction string. The method interprets the direction (up/down/left/right)
// and changes the drone's position accordingly, also adding the cleaned tile to the TilesRepository's list of tiles.
void DroneController::moveDrone(const std::string & direction) {
	int newDroneXPosition = this->drone.getXPosition();
	int newDroneYPosition = this->drone.getYPosition();

	if (direction.compare("up") == 0) {
		newDroneYPosition += 1;
	} else if (direction.compare("down") == 0) {
		newDroneYPosition -= 1;
	}
	else if (direction.compare("left") == 0) {
		newDroneXPosition -= 1;
	}
	else if (direction.compare("right") == 0) {
		newDroneXPosition += 1;
	}

	if (!this->canMoveDrone(newDroneXPosition, newDroneYPosition)) {
		throw std::runtime_error("Cannot advance in that direction, this tile is already cleaned.");
	}
	if (newDroneXPosition < 0 || newDroneYPosition < 0 || newDroneXPosition > 10 || newDroneYPosition > 10) {
		throw std::runtime_error("Cannot advance in that direction, the drone would hit a wall.");
	}

	this->drone.setXPosition(newDroneXPosition);
	this->drone.setYPosition(newDroneYPosition);

	Tile newTile{ newDroneXPosition, newDroneYPosition };
	this->tilesRepository.addTileInRepository(newTile);
}

std::vector<Tile> DroneController::getCleanedTiles() {
	return this->tilesRepository.getCleanedTilesFromRepository();
}

bool DroneController::canMoveDrone(const int & newDroneXPosition, const int & newDroneYPosition) {
	std::vector<Tile> tiles = this->tilesRepository.getCleanedTilesFromRepository();

	for (auto it = tiles.begin(); it != tiles.end(); it++) {
		Tile tile = (Tile)*it;
		if (tile.getXPosition() == newDroneXPosition && tile.getYPosition() == newDroneYPosition) {
			return false;
		}
	}
	return true;
}

// Method for calculating the percentage of cleaned tiles.
double DroneController::getCleanedPercentage() {
	double totalTiles = 11 * 11;
	return (this->getCleanedTiles().size() * 100) / totalTiles;
}
