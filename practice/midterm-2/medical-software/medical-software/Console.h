#pragma once

#include "Person.h"
#include <iostream>

class Console {
	
private:
	std::shared_ptr<Person> person;

public:
	Console(std::shared_ptr<Person> person);

	void runConsole();

	void uiAddAnalysis(std::string arguments);
	void uiListAnalyses();
	void uiCheckIllness(std::string arguments);
	void uiSaveAnalyses(std::string arguments);

	~Console();
};

