#include "TeamController.h"

#include <algorithm>

void TeamController::addTeam(const std::string & name, const std::string & country) {
	if (!this->canAddTeam(name)) {
		throw std::runtime_error("A team with this name already exists.");
	}
	Team team{ name, country };
	this->teamRepository.addTeamToRepository(team);
}

std::vector<Team> TeamController::getTeams() {
	std::vector<Team> teams = this->teamRepository.getTeamsFromRepository();
	auto sortFunction = [](const Team& firstTeam, const Team& secondTeam) -> bool {
		return firstTeam.getCurrentScore() > secondTeam.getCurrentScore();
	};
	std::sort(teams.begin(), teams.end(), sortFunction);
	return teams;
}

void TeamController::pairTeams(const std::string & firstTeamName, const std::string & secondTeamName, const std::string & winningTeamName) {
	if (!this->canPairTeams(firstTeamName, secondTeamName)) {
		throw std::runtime_error("Cannot pair these two teams because they have different scores.");
	}
	if (firstTeamName == secondTeamName) {
		throw std::runtime_error("A team cannot compete with itself.");
	}
	if (winningTeamName != firstTeamName && winningTeamName != secondTeamName) {
		throw std::runtime_error("The winning team must be one of the ones paired.");
	}
	this->teamRepository.increaseTeamScoreInRepository(winningTeamName);
}

bool TeamController::canAddTeam(const std::string & name) {
	std::vector<Team> teams = this->teamRepository.getTeamsFromRepository();
	auto compareFunction = [name](const Team& team) { return team.getName() == name; };
	auto it = std::find_if(teams.begin(), teams.end(), compareFunction);
	return it == teams.end();
}

bool TeamController::canPairTeams(const std::string & firstTeamName, const std::string & secondTeamName) {
	Team firstTeam = this->teamRepository.getByTitle(firstTeamName);
	Team secondTeam = this->teamRepository.getByTitle(secondTeamName);
	return firstTeam.getCurrentScore() == secondTeam.getCurrentScore();
}