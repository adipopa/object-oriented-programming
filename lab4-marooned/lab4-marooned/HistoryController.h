#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "DynamicArray.h"
#include "Operation.h"

typedef struct HistoryController {
	DynamicArray* undoOperations;
	DynamicArray* redoOperations;
	int operationIndex;
} HistoryController;

HistoryController* HistoryControllerConstructor();

void createOperation(HistoryController* historyController, Operation* undoOperation, Operation* redoOperation);

int undoOperation(HistoryController* historyController);

int redoOperation(HistoryController* historyController);

Operation* getUndoOperation(HistoryController* historyController);

Operation* getRedoOperation(HistoryController* historyController);

int canUndo(HistoryController* historyController);

int canRedo(HistoryController* historyController);

void HistoryControllerDestructor(HistoryController* historyController);