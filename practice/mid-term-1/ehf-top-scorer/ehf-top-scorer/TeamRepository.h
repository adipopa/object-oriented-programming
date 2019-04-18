#pragma once

#include "Team.h"
#include <vector>

class TeamRepository {
	
private:
	std::vector<Team> teams;

public:
	TeamRepository() {};

	void addTeamToRepository(const Team& team);

	std::vector<Team> getTeamsFromRepository();

	void increaseTeamScoreInRepository(const std::string& name);

	Team getByTitle(const std::string & name);

	~TeamRepository() {};
};

