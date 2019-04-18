#include "Console.h"
#include <iostream>
#include <assert.h>

using namespace std;

// Exam 1 - Drone duty

void testMoveDrone(DroneController droneController) {
	droneController.placeDrone(2, 3);

	droneController.moveDrone("right");
	droneController.moveDrone("right");
	droneController.moveDrone("up");

	// assert(droneController.getDrone())
}

int main() {
	TilesRepository tilesRepository{};
	DroneController droneController{ tilesRepository };
	Console console{ droneController };

	testMoveDrone(droneController);

	console.runConsole();
	return 0;
}