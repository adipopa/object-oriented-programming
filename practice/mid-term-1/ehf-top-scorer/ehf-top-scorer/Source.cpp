#include "Console.h"

using namespace std;

int main() {
	TeamRepository teamRepository{};
	TeamController teamController{ teamRepository };

	teamController.addTeam("Larvik", "Norway");
	teamController.addTeam("CSM Bucuresti", "Romania");
	teamController.addTeam("Buducnost", "Montenegro");
	teamController.addTeam("Rostov-Don", "Russia");
	teamController.addTeam("FTC-Rail Cargo Hungaria", "Hungary");

	Console console{ teamController };
	console.runConsole();

	return 0;
}