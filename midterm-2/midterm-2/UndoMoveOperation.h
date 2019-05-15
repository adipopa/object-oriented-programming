#pragma once

#include "UndoOperation.h"

class UndoMoveOperation : public UndoOperation {

private:
	Repository* paintingsRepo;
	Repository* specialPaintingsRepo;

public:
	UndoMoveOperation(Painting paintingToUndo, Repository* paintingsRepo, Repository* specialPaintingsRepo);

	void executeUndo() override;

	~UndoMoveOperation();
};

