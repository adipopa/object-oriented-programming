#pragma once

#include "DroneController.h"
#include <iostream>
#include <string>

class Console {
	
private:
	DroneController droneController;

public:
	Console(const DroneController& droneController) : droneController{ droneController } {}

	void runConsole();

	void uiPlaceDrone();

	void uiMoveDrone(std::string arguments);

	void uiShowTiles();

	~Console() {}
};

