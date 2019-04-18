#include "TeamRepository.h"

#include <algorithm>

void TeamRepository::addTeamToRepository(const Team & team) {
	this->teams.push_back(team);
}

std::vector<Team> TeamRepository::getTeamsFromRepository() {
	return this->teams;
}

void TeamRepository::increaseTeamScoreInRepository(const std::string & name) {
	for (unsigned int i = 0; i < this->teams.size(); i++) {
		if (this->teams[i].getName() == name) {
			this->teams[i].setCurrentScore(this->teams[i].getCurrentScore() + 1);
			return;
		}
	}
}

Team TeamRepository::getByTitle(const std::string & name) {
	auto compareFunction = [name](const Team& team) { return team.getName() == name; };
	auto it = std::find_if(this->teams.begin(), this->teams.end(), compareFunction);
	if (it == this->teams.end()) {
		throw std::runtime_error("No team with the name " + name + " exists.");
	}
	return (Team)*it;
}
