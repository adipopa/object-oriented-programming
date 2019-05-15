#include "Console.h"

using namespace std;

void Console::runConsole() {
	cout << "EHF Team Management\n";
	bool keepAlive = true;
	while (keepAlive) {
		string inputString;

		cout << "\nEHF:~$ ";
		getline(cin, inputString);

		int position = inputString.find(" ");
		const string command = inputString.substr(0, position);
		inputString.erase(0, position + 1);

		try {
			if (command.compare("add") == 0) {
				this->uiAddTeam(inputString);
			}
			else if (command.compare("list") == 0) {
				this->uiShowAllTeams();
			}
			else if (command.compare("pair") == 0) {
				this->uiPairTeams(inputString);
			}
			else if (command.compare("exit") == 0) {
				keepAlive = false;
			}
			else {
				cout << "Invalid command!\n";
			}
		}
		catch (exception& exception) {
			cout << exception.what() << "\n";
		}
	}
}

void Console::uiAddTeam(const string& inputString) {
	string arguments = inputString;

	int position = arguments.find(", ");
	const string name = arguments.substr(0, position);
	arguments.erase(0, position + 2);


	position = arguments.find(", ");
	const string country = arguments.substr(0, position);
	arguments.erase(0, position + 2);

	this->teamController.addTeam(name, country);

	cout << "Team " << name << " successfully added.\n";
}

void Console::uiShowAllTeams() {
	vector<Team> teams = this->teamController.getTeams();

	for (auto it = teams.begin(); it != teams.end(); it++) {
		Team team = (Team)*it;
		cout << team.getName() << " " << team.getCountry() << " " << team.getCurrentScore() << "\n";
	}
}

void Console::uiPairTeams(const string & inputString) {
	string arguments = inputString;

	int position = arguments.find(", ");
	const string firstTeamName = arguments.substr(0, position);
	arguments.erase(0, position + 2);


	position = arguments.find(", ");
	const string secondTeamName = arguments.substr(0, position);
	arguments.erase(0, position + 2);


	position = arguments.find(", ");
	const string winningTeamName = arguments.substr(0, position);
	arguments.erase(0, position + 2);

	this->teamController.pairTeams(firstTeamName, secondTeamName, winningTeamName);

	cout << winningTeamName << " won at a match between " + firstTeamName + " vs " + secondTeamName + ".\n";
}
