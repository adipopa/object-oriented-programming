#include "UndoOperation.h"

UndoOperation::UndoOperation(Painting paintingToUndo) : paintingToUndo{ paintingToUndo } {}

void UndoOperation::executeUndo() {}

UndoOperation::~UndoOperation() {}
