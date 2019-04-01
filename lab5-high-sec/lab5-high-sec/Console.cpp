#include "Console.h"
#include <iostream>
#include <string>

using namespace std;

int Console::uiSelectMode(char* currentToken) {
	char mode;
	currentToken = strtok(NULL, " ");
	if (currentToken == NULL) { return -1; }
	mode = currentToken[0];
	currentToken = strtok(NULL, " ");
	if (currentToken != NULL) { return -1; }
	return this->recordingController->setMode(mode);
}

int Console::uiAddRecording(char* currentToken) {
	string title, location, timeOfCreation, footagePreview;
	int timesAccessed;
	currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	title = string(currentToken);
	currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	location = string(currentToken);
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) { return -1; }
	timeOfCreation = string(currentToken);
	currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	timesAccessed = atoi(currentToken);
	currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	footagePreview = string(currentToken);
	currentToken = strtok(NULL, " ");
	if (currentToken != NULL) { return -1; }
	return this->recordingController->addRecording(title, location, timeOfCreation, timesAccessed, footagePreview);
}

int Console::uiUpdateRecording(char* currentToken) {
	string title, newLocation, newTimeOfCreation, newFootagePreview;
	int newTimesAccessed;
	currentToken = strtok(NULL, ", ");
	if (currentToken == NULL) { return -1; }
	title = string(currentToken);
		currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	newLocation = string(currentToken);
		currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	newTimeOfCreation = string(currentToken);
		currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	newTimesAccessed = atoi(currentToken);
	currentToken = strtok(NULL, ",");
	if (currentToken == NULL) { return -1; }
	newFootagePreview = string(currentToken);
		currentToken = strtok(NULL, " ");
	if (currentToken != NULL) { return -1; }
	return this->recordingController->updateRecording(title, newLocation, newTimeOfCreation, newTimesAccessed, newFootagePreview);
}

int Console::uiDeleteRecording(char* currentToken) {
	string title;
	currentToken = strtok(NULL, " ");
	if (currentToken == NULL) { return -1; }
	title = string(currentToken);
	currentToken = strtok(NULL, " ");
	if (currentToken != NULL) { return -1; }
	return this->recordingController->deleteRecording(title);
}

int Console::uiListRecordings(char* currentToken) {
	currentToken = strtok(NULL, " ");
	if (currentToken != NULL) { return -1; }

	if (this->recordingController->getClearanceLevel().compare("low-security") == 0) {
		return 2;
	}

	string listToString = "";

	DynamicVector<Recording> recordings = this->recordingController->getRecordings();
	for (int i = 0; i < recordings.getSize(); i++) {
		Recording recording = recordings[i];
		listToString += recording.getTitle() + recording.getLocation() + " " + recording.getTimeOfCreation() + " " +
			to_string(recording.getTimesAccessed()) + recording.getFootagePreview() + "\n";
	}

	cout << listToString;

	return 0;
}

void Console::runConsole() {
	cout << "Argo Motherboard 3.07 ship\n\n";
	cout << "Please use the command 'mode A/B' to select your clearance level (high-security/low-security).\n";
	int keepAlive = 1;
	while (keepAlive) {
		char inputString[100];

		cout << "ship@root:~$ ";
		scanf(" %[^\n]s", inputString);
		char* currentToken = strtok(inputString, " ");

		char command[10];
		strcpy(command, currentToken);

		if (strcmp(command, "mode") == 0) {
			int selectModeResult = this->uiSelectMode(currentToken);
			if (selectModeResult == -1) {
				printf("Invalid arguments for 'mode' command.\n");
			}
			else if (selectModeResult == 1) {
				printf("Invalid mode type (valid options are A/B).\n");
			}
		}
		else if (strcmp(command, "add") == 0) {
			int addRecordingResult = this->uiAddRecording(currentToken);
			if (addRecordingResult == -1) {
				printf("Invalid arguments for 'add' command.\n");
			}
			else if (addRecordingResult == 1) {
				printf("Recording with given title already exists.\n");
			}
			else if (addRecordingResult == 2) {
				printf("You don't have the necessary clearance to add a new recording.\n");
			}
		}
		else if (strcmp(command, "update") == 0) {
			int updateRecordingResult = this->uiUpdateRecording(currentToken);
			if (updateRecordingResult == -1) {
				printf("Invalid arguments for 'update' command.\n");
			}
			else if (updateRecordingResult == 2) {
				printf("You don't have the necessary clearance to update a recording.\n");
			}
		}
		else if (strcmp(command, "delete") == 0) {
			int deleteRecordingResult = this->uiDeleteRecording(currentToken);
			if (deleteRecordingResult == -1) {
				printf("Invalid arguments for 'delete' command.\n");
			}
			else if (deleteRecordingResult == 1) {
				printf("Recording with given title doesn't exist.\n");
			}
			else if (deleteRecordingResult == 2) {
				printf("You don't have the necessary clearance to remove a recording.\n");
			}
		}
		else if (strcmp(command, "list") == 0) {
			int listRecordingsResult = this->uiListRecordings(currentToken);
			if (listRecordingsResult == -1) {
				printf("Invalid arguments for 'list' command.\n");
			}
			else if (listRecordingsResult == 2) {
				printf("You don't have the necessary clearance to list the recordings.\n");
			}
		}
		else if (strcmp(command, "exit") == 0) {
			keepAlive = 0;
		}
		else {
			printf("Invalid command.\n");
		}
	}
}
