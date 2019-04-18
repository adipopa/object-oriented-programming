#pragma once

#include "TeamController.h"
#include <iostream>
#include <string>

class Console {
	
private:
	TeamController teamController;

public:
	Console(const TeamController& teamController) : teamController{ teamController } {};

	void runConsole();

	void uiAddTeam(const std::string& inputString);

	void uiShowAllTeams();

	void uiPairTeams(const std::string& inputString);

	~Console() {};
};

