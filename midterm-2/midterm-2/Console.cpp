#include "Console.h"

using namespace std;

Console::Console(Controller* controller) : controller{ controller } {}

void Console::runConsole() {
	bool keepAlive = true;
	while (keepAlive) {
		string inputString;

		cout << "Medical Software:~$ ";
		getline(cin, inputString);

		const string delimiter = " ";
		int position = inputString.find(delimiter);
		const string command = inputString.substr(0, position);
		inputString.erase(0, position + 1);

		try {
			if (command == "add") {
				this->uiAddPainting(inputString);
			}
			else if (command == "move") {
				this->uiMovePainting(inputString);
			}
			else if (command == "list") {
				this->uiListPaintings();
			}
			else if (command == "undo") {
				this->controller->undo();
			}
			else if (command == "exit") {
				keepAlive = 0;
			}
			else {
				printf("Invalid command.\n");
			}
		}
		catch (std::exception& exception) {
			cout << exception.what() << "\n";
		}
	}
}

void Console::uiAddPainting(string arguments) {
	int position = arguments.find(", ");
	const string artist = arguments.substr(0, position);
	arguments.erase(0, position + 2);

	position = arguments.find(", ");
	const string title = arguments.substr(0, position);
	arguments.erase(0, position + 2);

	position = arguments.find(", ");
	const int year = stoi(arguments.substr(0, position));

	this->controller->addPainting(artist, title, year);
}

void Console::uiMovePainting(string arguments) {
	int position = arguments.find(", ");
	const string artist = arguments.substr(0, position);
	arguments.erase(0, position + 2);

	position = arguments.find(", ");
	const string title = arguments.substr(0, position);
	arguments.erase(0, position + 2);

	position = arguments.find(", ");
	const int year = stoi(arguments.substr(0, position));

	this->controller->removePainting(artist, title, year);

}

void Console::uiListPaintings() {
	std::vector<Painting> paintings = this->controller->getAll();
	std::vector<Painting> specialStoragePaintings = this->controller->getAllSpecialStorage();

	cout << "Main hold:\n";
	for (auto painting : paintings) {
		cout << painting.toString();
	}

	cout << "Special storage:\n";
	for (auto painting : specialStoragePaintings) {
		cout << painting.toString();
	}
}


Console::~Console()
{
}
