#include "Console.h"
#include <iostream>
#include <string>

using namespace std;

void Console::uiSelectMode(string inputString) {
	int position = inputString.find(" ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'mode' command."); }
	inputString.erase(0, position + 1);

	string currentToken = inputString.substr(0, inputString.size());
	char mode = currentToken[0];

	position = inputString.find(" ");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'mode' command."); }

	this->recordingController->setMode(mode);
}

void Console::uiAddRecording(string inputString) {
	int position = inputString.find(" ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'add' command."); }
	inputString.erase(0, position + 1);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'add' command."); }
	string currentToken = inputString.substr(0, position);
	string title = currentToken;
	inputString.erase(0, position + 2);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'add' command."); }
	currentToken = inputString.substr(0, position);
	string location = currentToken;
	inputString.erase(0, position + 2);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'add' command."); }
	currentToken = inputString.substr(0, position);
	string timeOfCreation = currentToken;
	inputString.erase(0, position + 2);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'add' command."); }
	currentToken = inputString.substr(0, position);
	int timesAccessed = atoi(currentToken.c_str());
	inputString.erase(0, position + 2);

	currentToken = inputString.substr(0, inputString.size());
	string footagePreview = currentToken;

	position = inputString.find(", ");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'add' command."); }

	this->recordingController->addRecording(title, location, timeOfCreation, timesAccessed, footagePreview);
}

void Console::uiUpdateRecording(string inputString) {
	int position = inputString.find(" ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'update' command."); }
	inputString.erase(0, position + 1);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'update' command."); }
	string currentToken = inputString.substr(0, position);
	string title = currentToken;
	inputString.erase(0, position + 2);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'update' command."); }
	currentToken = inputString.substr(0, position);
	string newLocation = currentToken;
	inputString.erase(0, position + 2);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'update' command."); }
	currentToken = inputString.substr(0, position);
	string newTimeOfCreation = currentToken;
	inputString.erase(0, position + 2);

	position = inputString.find(", ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'update' command."); }
	currentToken = inputString.substr(0, position);
	int newTimesAccessed = atoi(currentToken.c_str());
	inputString.erase(0, position + 2);

	currentToken = inputString.substr(0, inputString.size());
	string newFootagePreview = currentToken;

	position = inputString.find(", ");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'update' command."); }

	this->recordingController->updateRecording(title, newLocation, newTimeOfCreation, newTimesAccessed, newFootagePreview);
}

void Console::uiDeleteRecording(string inputString) {
	int position = inputString.find(" ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'delete' command."); }
	inputString.erase(0, position + 1);

	string currentToken = inputString.substr(0, inputString.size());
	string title = currentToken;

	position = inputString.find(", ");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'delete' command."); }

	this->recordingController->deleteRecording(title);
}

void Console::uiListRecordings(string inputString) {
	vector<Recording> recordings;

	int position = inputString.find(" ");
	inputString.erase(0, position + 1);

	if (position == string::npos) {
		recordings = this->recordingController->getRecordings();
	}
	else {
		position = inputString.find(", ");
		if (position == string::npos) { throw runtime_error("Invalid arguments for 'list' command."); }
		string currentToken = inputString.substr(0, position);
		string location = currentToken;
		inputString.erase(0, position + 2);

		currentToken = inputString.substr(0, inputString.size());
		int timesAccessed = atoi(currentToken.c_str());

		position = inputString.find(" ");
		if (position != string::npos) { throw runtime_error("Invalid arguments for 'list' command."); }

		recordings = this->recordingController->getRecordingsByLocationAndTimesAccessed(location, timesAccessed);
	}

	for (auto const& recording : recordings) {
		cout << recording.getTitle() + ", " + recording.getLocation() + ", " + recording.getTimeOfCreation() + ", " +
			to_string(recording.getTimesAccessed()) + ", " + recording.getFootagePreview() + "\n";
	}
}

void Console::uiNextRecording(string inputString) {
	int position = inputString.find(" ");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'next' command."); }

	Recording nextRecording = this->recordingController->getNextRecording();
	if (nextRecording.getTitle().empty()) {
		return;
	}
	cout << nextRecording.getTitle() + " " + nextRecording.getLocation() + " " + nextRecording.getTimeOfCreation() + " " +
		to_string(nextRecording.getTimesAccessed()) + " " + nextRecording.getFootagePreview() + "\n";
}

void Console::uiSaveRecording(string inputString) {
	int position = inputString.find(" ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'save' command."); }
	inputString.erase(0, position + 1);

	string currentToken = inputString.substr(0, inputString.size());
	string title = currentToken;

	position = inputString.find(", ");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'save' command."); }

	this->recordingController->saveRecording(title);
}

void Console::uiSeeWatchlist(string inputString) {
	int position = inputString.find(" ");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'mylist' command."); }

	vector<Recording> watchlist = this->recordingController->getWatchlist();
	for (auto const& recording : watchlist) {
		cout << recording.getTitle() + " " + recording.getLocation() + " " + recording.getTimeOfCreation() + " " +
			to_string(recording.getTimesAccessed()) + " " + recording.getFootagePreview() + "\n";
	}
}

void Console::uiSetFileLocation(std::string inputString) {
	int position = inputString.find(" ");
	if (position == string::npos) { throw runtime_error("Invalid arguments for 'fileLocation' command."); }
	inputString.erase(0, position + 1);

	string currentToken = inputString.substr(0, inputString.size());
	string fileLocation = currentToken;

	position = inputString.find("\n");
	if (position != string::npos) { throw runtime_error("Invalid arguments for 'fileLocation' command."); }

	this->recordingController->setFileLocation(fileLocation);
}

void Console::runConsole() {
	cout << "Argo Motherboard 3.14 ship\n\n";
	cout << "Please use the command 'mode A/B' to select your clearance level (high-security/low-security).\n";
	int keepAlive = 1;
	while (keepAlive) {
		string inputString;

		cout << "ship@root:~$ ";
		getline(cin, inputString);

		const string delimiter = " ";
		int position = inputString.find(delimiter);
		const string command = inputString.substr(0, position);

		try {
			if (command.compare("mode") == 0) {
				this->uiSelectMode(inputString);
			}
			else if (command.compare("add") == 0) {
				this->uiAddRecording(inputString);
			}
			else if (command.compare("update") == 0) {
				this->uiUpdateRecording(inputString);
			}
			else if (command.compare("delete") == 0) {
				this->uiDeleteRecording(inputString);
			}
			else if (command.compare("list") == 0) {
				this->uiListRecordings(inputString);
			}
			else if (command.compare("next") == 0) {
				this->uiNextRecording(inputString);
			}
			else if (command.compare("save") == 0) {
				this->uiSaveRecording(inputString);
			}
			else if (command.compare("mylist") == 0) {
				this->uiSeeWatchlist(inputString);
			}
			else if (command.compare("fileLocation") == 0) {
				this->uiSetFileLocation(inputString);
			}
			else if (command.compare("exit") == 0) {
				keepAlive = 0;
			}
			else {
				printf("Invalid command.\n");
			}
		}
		catch (exception& exception) {
			cout << exception.what() << "\n";
		}
	}
}
