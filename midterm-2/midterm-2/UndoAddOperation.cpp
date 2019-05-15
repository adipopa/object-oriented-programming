#include "UndoAddOperation.h"

UndoAddOperation::UndoAddOperation(Painting paintingToUndo, Repository* paintingsRepo) :
	paintingsRepo{ paintingsRepo }, UndoOperation{ paintingToUndo } {}

void UndoAddOperation::executeUndo() {
	this->paintingsRepo->removePainting(this->paintingToUndo);
}

UndoAddOperation::~UndoAddOperation() {}
