#pragma once

#include "Controller.h"
#include <iostream>
#include <string>

class Console {

private:
	Controller* controller;

public:
	Console(Controller* controller);

	void runConsole();

	void uiAddPainting(std::string arguments);
	void uiMovePainting(std::string arguments);
	void uiListPaintings();

	~Console();
};

