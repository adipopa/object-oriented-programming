#include "UndoMoveOperation.h"

UndoMoveOperation::UndoMoveOperation(Painting paintingToUndo, Repository* paintingsRepo, Repository* specialPaintingsRepo) : 
	UndoOperation{ paintingToUndo }, paintingsRepo{ paintingsRepo }, specialPaintingsRepo{ specialPaintingsRepo } {}

void UndoMoveOperation::executeUndo() {
	this->paintingsRepo->addPainting(this->paintingToUndo);
	this->specialPaintingsRepo->removePainting(this->paintingToUndo);
}

UndoMoveOperation::~UndoMoveOperation() {}
