#include "Console.h"

using namespace std;

Console::Console(std::shared_ptr<Person> person) : person{ person } {}

void Console::runConsole() {
	int keepAlive = 1;
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
				this->uiAddAnalysis(inputString);
			}
			else if (command == "list") {
				this->uiListAnalyses();
			}
			else if (command == "illness") {
				this->uiCheckIllness(inputString);
			}
			else if (command == "save") {
				this->uiSaveAnalyses(inputString);
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

void Console::uiAddAnalysis(string arguments) {
	int position = arguments.find(" ");
	const string type = arguments.substr(0, position);
	arguments.erase(0, position + 1);

	position = arguments.find(" ");
	const string date = arguments.substr(0, position);
	arguments.erase(0, position + 1);

	MedicalAnalysis* newAnalysis;
	
	if (type == "BMI") {
		position = arguments.find(" ");
		const double value = stod(arguments.substr(0, position));

		newAnalysis = new BMI{ date, value };
	}
	else if (type == "BP") {
		position = arguments.find(" ");
		const int systolicValue = stoi(arguments.substr(0, position));
		arguments.erase(0, position + 1);

		position = arguments.find(" ");
		const int diastolicValue = stoi(arguments.substr(0, position));

		newAnalysis = new BP{ date, systolicValue, diastolicValue };
	}
	else {
		throw runtime_error("Invalid analysis type.");
	}

	this->person->addAnalysis(newAnalysis);

	cout << "Added a new " << type << " analysis.\n";
}

void Console::uiListAnalyses() {
	vector<MedicalAnalysis*> medicalAnalyses = this->person->getAllAnalyses();
	
	for (auto medicalAnalysis : medicalAnalyses) {
		cout << medicalAnalysis->toString();
	}
}

void Console::uiCheckIllness(std::string arguments) {
	int position = arguments.find(" ");
	const int month = stoi(arguments.substr(0, position));

	cout << (this->person->isIll(month) ? "You're kinda' dying." : "You're doing fine.") << "\n";
}

void Console::uiSaveAnalyses(std::string arguments) {
	int position = arguments.find(" ");
	const string filename = arguments.substr(0, position);
	arguments.erase(0, position + 1);

	position = arguments.find(" ");
	const string startDate = arguments.substr(0, position);
	arguments.erase(0, position + 1);

	position = arguments.find(" ");
	const string endDate = arguments.substr(0, position);

	this->person->writeToFile(filename, startDate, endDate);
}

Console::~Console() {}
