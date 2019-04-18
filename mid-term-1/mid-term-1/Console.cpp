#include "Console.h"

using namespace std;

void Console::runConsole() {
	this->uiPlaceDrone();

	bool keepAlive = true;
	while (keepAlive) {
		string inputString;

		cout << "\nDRONE:~$ ";
		getline(cin, inputString);

		int position = inputString.find(" ");
		const string command = inputString.substr(0, position);
		inputString.erase(0, position + 1);

		try {
			if (command.compare("move") == 0) {
				this->uiMoveDrone(inputString);
			}
			else if (command.compare("tiles") == 0) {
				this->uiShowTiles();
			}
			else if (command.compare("exit") == 0) {
				keepAlive = false;
			}
			else {
				cout << "Invalid input!\n";
			}
		}
		catch (exception& exception) {
			cout << exception.what() << "\n";
		}
	}
}

void Console::uiPlaceDrone() {
	string inputString;

	cout << "DRONE:~$ Place the cleaning drone at position (x y): ";
	getline(cin, inputString);

	int position = inputString.find(" ");
	const int droneXStartPosition = stoi(inputString.substr(0, position));
	inputString.erase(0, position + 1);

	position = inputString.find(" ");
	const int droneYStartPosition = stoi(inputString.substr(0, position));
	inputString.erase(0, position + 1);

	this->droneController.placeDrone(droneXStartPosition, droneYStartPosition);

	cout << "The drone was placed at position " << droneXStartPosition << " " << droneYStartPosition << "\n";
}

void Console::uiMoveDrone(string arguments) {
	int position = arguments.find(" ");
	// add validation if "direction" is missing
	const string direction = arguments.substr(0, position);
	this->droneController.moveDrone(direction);

	cout << "The drone was moved in the " << direction << " direction.\n";
}

void Console::uiShowTiles() {
	cout << "Cleaned tiles:\n";
	vector<Tile> tiles = this->droneController.getCleanedTiles();
	for (auto it = tiles.begin(); it != tiles.end(); it++) {
		Tile tile = (Tile)*it;
		cout << tile.getXPosition() << " " << tile.getYPosition() << "\n";
	}
	cout << "Percentage of cleaned tiles: " << this->droneController.getCleanedPercentage() << "%\n";
}
