#pragma once

#include "Drone.h"
#include "TilesRepository.h"

class DroneController {

private:
	Drone drone;
	TilesRepository tilesRepository;

public:
	DroneController(const TilesRepository& tilesRepository) : tilesRepository{ tilesRepository } {};

	void placeDrone(const int& droneXStartPosition, const int& droneYStartPosition);

	void moveDrone(const std::string& direction);

	std::vector<Tile> getCleanedTiles();

	bool canMoveDrone(const int& newDroneXPosition, const int& newDroneYPosition);

	double getCleanedPercentage();

	~DroneController() {}
};

