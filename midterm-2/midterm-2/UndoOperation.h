#pragma once

#include "Repository.h"

class UndoOperation {

protected:
	Painting paintingToUndo;

public:
	UndoOperation(Painting paintingToUndo);

	virtual void executeUndo();

	~UndoOperation();
};

