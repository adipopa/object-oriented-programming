#pragma once

#include "UndoOperation.h"

class UndoAddOperation : public UndoOperation {

private:
	Repository* paintingsRepo;

public:
	UndoAddOperation(Painting paintingToUndo, Repository* paintingsRepo);

	void executeUndo() override;

	~UndoAddOperation();
};

