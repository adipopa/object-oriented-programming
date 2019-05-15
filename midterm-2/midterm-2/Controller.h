#pragma once

#include "Repository.h"
#include "UndoAddOperation.h"
#include "UndoMoveOperation.h"

class Controller {

private:
	Repository* repoAll;
	Repository* repoSpecialStorage;

	std::vector<UndoOperation*> undoOperations;

public:
	Controller(Repository* repoAll, Repository* repoSpecialStorage);

	void addPainting(std::string artist, std::string title, int year);
	void removePainting(std::string artist, std::string title, int year);
	std::vector<Painting> getAll();
	std::vector<Painting> getAllSpecialStorage();
	void undo();

	~Controller();
};

