#pragma once

#include "TeamRepository.h"

class TeamController {
	
private:
	TeamRepository teamRepository;

public:
	TeamController(const TeamRepository& teamRepository): teamRepository { teamRepository } {};

	void addTeam(const std::string& name, const std::string& country);

	std::vector<Team> getTeams();

	void pairTeams(const std::string& firstTeamName, const std::string& secondTeamName, const std::string& winningTeamName);

	bool canAddTeam(const std::string& name);

	bool canPairTeams(const std::string& firstTeamName, const std::string& secondTeamName);

	~TeamController() {};
};

