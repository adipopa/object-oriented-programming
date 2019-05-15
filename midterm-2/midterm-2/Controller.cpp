#include "Controller.h"

Controller::Controller(Repository * repoAll, Repository * repoSpecialStorage) : repoAll{ repoAll }, repoSpecialStorage{ repoSpecialStorage } {}

void Controller::addPainting(std::string artist, std::string title, int year) {
	Painting newPainting{ title, artist, year };
	this->repoAll->addPainting(newPainting);

	UndoOperation* undoAddOperation = new UndoAddOperation{ newPainting, this->repoAll };
	this->undoOperations.push_back(undoAddOperation);
}

void Controller::removePainting(std::string artist, std::string title, int year) {
	Painting paintingToRemove{ title, artist, year };
	this->repoSpecialStorage->addPainting(paintingToRemove);
	this->repoAll->removePainting(paintingToRemove);

	UndoOperation* undoMoveOperation = new UndoMoveOperation{ paintingToRemove, this->repoAll, this->repoSpecialStorage };
	this->undoOperations.push_back(undoMoveOperation);
}

std::vector<Painting> Controller::getAll() {
	return this->repoAll->getAll();
}

std::vector<Painting> Controller::getAllSpecialStorage() {
	return this->repoSpecialStorage->getAll();
}

void Controller::undo() {
	if (this->undoOperations.size() == 0) {
		return;
	}
	UndoOperation* undoOperation = this->undoOperations.back();
	undoOperation->executeUndo();
	this->undoOperations.pop_back();
}

Controller::~Controller() {}
